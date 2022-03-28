#include "point_container.h"

namespace graphics {
	pointContainer::pointContainer(size_t _size) {
		defineDataType(_size);
	}

	pointContainer::~pointContainer() {
		if (pointData != nullptr)
			delete pointData;
	}

	void pointContainer::defineDataType(size_t _size) {
		if (_size < 2)
			throw std::exception("Wrong pointContainer size in ctor(size)");
		else if (_size > maxPointContainerSize)
			throw std::exception("Wrong pointContainer size in ctor(size)");

		if (pointData != nullptr) {
			delete pointData;
		}

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

	pointContainer& pointContainer::operator= (const pointContainer& _pointContainer) {
		
		if (pointData != nullptr) {
			if (type == _pointContainer.type) {
				// non-alloc copy
				pointData->operator=(*_pointContainer.pointData);
				return *this;
			}
			type = pointContainerType::UNDEFINED;
			delete pointData;
			pointData = nullptr;
		}

		if (_pointContainer.type == TYPEUNDEF || _pointContainer.pointData == nullptr) {
			type = TYPEUNDEF;
			return *this;
		}

		int newSize = _pointContainer.pointData->size;
		defineDataType(newSize);
		pointData->operator=(*_pointContainer.pointData);
		return *this;
	}

	pointContainer& pointContainer::operator= (const point_base& _point) {
		if (pointData != nullptr) {
			if ((int)type == _point.size && _point.size < 4) {
				// non-alloc copy
				pointData->operator=(_point);
				return *this;
			}
			type = pointContainerType::UNDEFINED;
			delete pointData;
		}

		defineDataType(_point.size);
		pointData->operator=(_point);
		return *this;
	}

	void pointContainer::checkWrongType(const pointContainerType _type, const char* _functionPlace) const {
		if (type != _type)
			return;			// OK

		std::string errorType;
		switch (_type) {
		case pointContainerType::UNDEFINED:
			errorType = "UNDEFINED";
			break;
		case pointContainerType::POINT2:
			errorType = "POINT2";
			break;
		case pointContainerType::POINT3:
			errorType = "POINT3";
			break;
		case pointContainerType::POINTN:
			errorType = "POINTN";
			break;
		default:
			errorType = "wrong enum type";
		}

		throw std::exception(std::string("Point Container is wrong type of "
			+ errorType + "in " + _functionPlace).c_str());
	}

	int& pointContainer::operator[](int _index) {
		checkWrongType(TYPEUNDEF, "operator[]()\0");

		// Index check is incapsulated
		return pointData->operator[](_index);
	}

	int  pointContainer::at(int _index) const {
		checkWrongType(TYPEUNDEF, "at()\0");

		// Index check is incapsulated
		return pointData->at(_index);
	}

	int pointContainer::x() const {
		checkWrongType(TYPEUNDEF, "x()\0");
			
		return pointData->x();
	}

	int pointContainer::y() const {
		checkWrongType(TYPEUNDEF, "y()\0");

		return pointData->y();
	}

	int pointContainer::z() const {
		checkWrongType(TYPEUNDEF, "z()\0");
		checkWrongType(TYPE2, "z()\0");

		pointData->z();
	}
}