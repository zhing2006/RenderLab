#ifndef _RTX_HITABLE_VOLUME_H_
#define _RTX_HITABLE_VOLUME_H_

#include <CppUtil/RTX/Hitable.h>

namespace RTX {
	class Volume : public Hitable{
		HITABLE_SETUP(Volume)
	public:
		Volume(Hitable::CPtr boundary = NULL, float density = 1.0f, CppUtil::Basic::CPtr<Material> material = NULL);

		virtual HitRst RayIn(CppUtil::Basic::Ptr<Ray> & ray) const;
		virtual const AABB GetBoundingBox() const { return boundary ? boundary->GetBoundingBox() : AABB::InValid; }
		const Hitable::CPtr GetBoundary() const { return boundary; }
		float GetDensity() const { return density; }
	private:
		Hitable::CPtr boundary;
		float density;
	};
}

#endif // !_RTX_HITABLE_VOLUME_H_
