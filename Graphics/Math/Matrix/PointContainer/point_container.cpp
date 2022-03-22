#include "point_container.h"

namespace graphics {
	pointContainer::pointContainer(size_t _size) {
		defineDataType(_size);
	}

	pointContainer::~pointContainer()
	{
		if (pointData != nullptr)
			delete pointData;
	}

	void pointContainer::defineDataType(size_t _size) {
		if (_size < 2)
			throw std::exception("Wrong pointContainer size in ctor(size)");
		else if (_size > maxPointContainerSize)
			throw std::exception("Wrong pointContainer size in ctor(size)");

		if (_size == 2) {
			pointData = new point2();
			type = pointContainerType::POINT2;
		}
		else if (_size == 3)
		{
			pointData = new point3();
			type = pointContainerType::POINT3;
		}
		else {
			pointData = new pointn(_size);
			type = pointContainerType::POINTN;
		}
	}

	pointContainer& pointContainer::operator= (const pointContainer& _point) {
		if (pointData != nullptr) {
			if (type == _point.type) {
				// non-alloc copy
				pointData->operator=(*_point.pointData);
				return;
			}
			type = pointContainerType::UNDEFINED;
			delete pointData;
		}

		int newSize = _point.pointData->size;
		defineDataType(newSize);
		pointData->operator=(*_point.pointData);
	}
}