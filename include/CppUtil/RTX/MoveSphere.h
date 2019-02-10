#ifndef _RTX_HITABLE_MOVE_SPHERE_H_
#define _RTX_HITABLE_MOVE_SPHERE_H_

#include <CppUtil/RTX/Sphere.h>

namespace RTX {
	class MoveSphere : public Hitable{
		HITABLE_SETUP(MoveSphere)
	public:
		MoveSphere(float t0, float t1, const glm::vec3 & center0, const glm::vec3 & center1, float radius, CppUtil::Basic::CPtr<Material> material = NULL);

		virtual HitRst RayIn(CppUtil::Basic::Ptr<Ray> & ray) const;

		virtual const AABB GetBoundingBox() const { return box; }
	private:
		const glm::vec3 center0;
		const glm::vec3 center1;
		float t0;
		float t1;
		float radius;
		AABB box;
	};
}

#endif // !_RTX_HITABLE_MOVE_SPHERE_H_
