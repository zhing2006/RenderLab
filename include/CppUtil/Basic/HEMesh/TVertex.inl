template<typename V, typename E, typename P>
const std::vector<Ptr<THalfEdge<V, E, P>>> TVertex<V, E, P>::AjdOutHEs() {
	std::vector<Ptr<HE>> hes;
	if (IsIsolated())
		return hes;

	auto he = HalfEdge();
	do {
		hes.push_back(he);
		he = he->RotateNext();
	} while (he != HalfEdge());
	return hes;
}

template<typename V, typename E, typename P>
const std::vector<Ptr<E>> TVertex<V, E, P>::AdjEdges() {
	std::vector<Ptr<E>> edges;
	for (auto he : AjdOutHEs())
		edges.push_back(he->Edge());
	return edges;
}

template<typename V, typename E, typename P>
const Ptr<THalfEdge<V, E, P>> TVertex<V, E, P>::FindFreeOutHE() {
	for (auto outHE : AjdOutHEs()) {
		if (outHE->IsFree())
			return outHE;
	}
	return nullptr;
}

template<typename V, typename E, typename P>
const std::vector<Ptr<V>> TVertex<V, E, P>::AdjVertices() {
	std::vector<Ptr<V>> adjVs;
	for (auto he : AjdOutHEs())
		adjVs.push_back(CastTo<V>(he->End()));
	return adjVs;
}

template<typename V, typename E, typename P>
bool TVertex<V, E, P>::IsConnected(PtrC<V> v0, PtrC<V> v1) {
	if (v0 == nullptr || v1 == nullptr)
		return false;

	for (auto adjV : v0->AdjVertices()) {
		if (adjV == v1)
			return true;
	}

	return false;
}