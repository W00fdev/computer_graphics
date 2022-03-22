#include "point_container.h"

namespace graphics {
	pointContainer::pointContainer(size_t _size) {
		if (_size < 2)
			throw std::exception("Wrong pointContainer size in ctor(size)");
		else if (_size > maxPointContainerSize)
			throw std::exception("Wrong pointContainer size in ctor(size)");

		if (_size == 2)
			pointData = new point2();
		else if (_size == 3)
			pointData = new point3();
		else
			pointData = new pointn(_size);
	}
}