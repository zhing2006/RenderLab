#ifndef _BASIC_NODE_ELEMENT_H_
#define _BASIC_NODE_ELEMENT_H_

#include <CppUtil/Basic/HeapObj.h>
#include <CppUtil/Basic/Visitor.h>

namespace CppUtil {
	namespace Basic {
		class ElementBase : public HeapObjBase {
		public:
			virtual void Accept(Ptr<VisitorBase> visitor) = 0;

		protected:
			ElementBase() = default;
			virtual ~ElementBase() = default;
		};

		template<typename ImplT>
		class Element : public HeapObj<ImplT, ElementBase> {
		protected:
			Element() = default;
			virtual ~Element() = default;

		public:
			virtual void Accept(Ptr<VisitorBase> visitor) override {
				visitor->Visit(This());
			}
		};
	}
}

#endif // !_BASIC_NODE_ELEMENT_H_
