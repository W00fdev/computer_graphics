#include "point_container.h"

// POINT_WRAPPER
namespace graphics {
	pointWrapper::pointWrapper() {
		type = TYPEUNDEF;
	}

	pointWrapper::pointWrapper(size_t _size) {
		defineDataType(_size);
	}

	pointWrapper::pointWrapper(pointWrapperType _pointWrapper) {
		defineDataType(_pointWrapper);
	}

	pointWrapper::pointWrapper(const pointWrapper& _pointWrapper) {
		defineDataType(_pointWrapper.type);
		int newSize = _pointWrapper.pointData->size;
		pointData->operator=(*_pointWrapper.pointData);
	}

	pointWrapper::~pointWrapper() {
		if (pointData != nullptr)
			delete pointData;
	}

	void pointWrapper::defineDataType(size_t _size) {
		if (_size < 2)
			throw std::exception("Wrong pointContainer size in ctor(size)");
		else if (_size > maxPointSize)
			throw std::exception("Wrong pointContainer size in ctor(size)");

		if (pointData != nullptr) {
			delete pointData;
		}

		if (_size == 2) {
			pointData = new point2();
			type = pointWrapperType::POINT2;
		}
		else if (_size == 3)
		{
			pointData = new point3();
			type = pointWrapperType::POINT3;
		}
		else {
			pointData = new pointn(_size);
			type = pointWrapperType::POINTN;
		}
	}

	void pointWrapper::defineDataType(pointWrapperType _type) {
		if (type == _type)
			return;

		if (pointData != nullptr) {
			delete pointData;
		}

		if (_type == TYPE2)
			pointData = new point2();
		else if (_type == TYPE3)
			pointData = new point3();
		else if (_type == TYPEN)
			pointData = new pointn();

		type = _type;
	}

	pointWrapper& pointWrapper::operator= (const pointWrapper& _pointWrapper) {
		
		if (pointData != nullptr) {
			if (type == _pointWrapper.type) {
				// non-alloc copy
				pointData->operator=(*_pointWrapper.pointData);
				return *this;
			}
			type = pointWrapperType::UNDEFINED;
			delete pointData;
			pointData = nullptr;
		}

		if (_pointWrapper.type == TYPEUNDEF || _pointWrapper.pointData == nullptr) {
			type = TYPEUNDEF;
			return *this;
		}

		int newSize = _pointWrapper.pointData->size;
		defineDataType(newSize);
		pointData->operator=(*_pointWrapper.pointData);
		return *this;
	}

	pointWrapper& pointWrapper::operator= (const point_base& _point) {
		if (pointData != nullptr) {
			if ((int)type == _point.size && _point.size < 4) {
				// non-alloc copy
				pointData->operator=(_point);
				return *this;
			}
			type = pointWrapperType::UNDEFINED;
			delete pointData;
		}

		defineDataType(_point.size);
		pointData->operator=(_point);
		return *this;
	}

	void pointWrapper::checkWrongType(const pointWrapperType _type, const char* _functionPlace) const {
		if (type != _type)
			return;			// OK

		std::string errorType;
		switch (_type) {
		case pointWrapperType::UNDEFINED:
			errorType = "UNDEFINED";
			break;
		case pointWrapperType::POINT2:
			errorType = "POINT2";
			break;
		case pointWrapperType::POINT3:
			errorType = "POINT3";
			break;
		case pointWrapperType::POINTN:
			errorType = "POINTN";
			break;
		default:
			errorType = "wrong enum type";
		}

		throw std::exception(std::string("Point Container is wrong type of "
			+ errorType + "in " + _functionPlace).c_str());
	}

	int& pointWrapper::operator[](int _index) {
		checkWrongType(TYPEUNDEF, "operator[]()\0");

		// Index check is incapsulated
		return pointData->operator[](_index);
	}

	int  pointWrapper::at(int _index) const {
		checkWrongType(TYPEUNDEF, "at()\0");

		// Index check is incapsulated
		return pointData->at(_index);
	}

	int pointWrapper::x() const {
		checkWrongType(TYPEUNDEF, "x()\0");
			
		return pointData->x();
	}

	int pointWrapper::y() const {
		checkWrongType(TYPEUNDEF, "y()\0");

		return pointData->y();
	}

	int pointWrapper::z() const {
		checkWrongType(TYPEUNDEF, "z()\0");
		checkWrongType(TYPE2, "z()\0");

		return pointData->z();
	}

	std::ostream& operator<<(std::ostream& _s, const pointWrapper& _pointWrapper) {
		if (_pointWrapper.type == TYPEUNDEF)
			_s << "{undefined point}";
		else
			_s << *(_pointWrapper.pointData);
		return _s;
	}
}

namespace graphics {
	pointArray::pointArray() {
		size = 0;
	}
	
	pointArray::pointArray(size_t _size) {
		if (_size > maxPointArraySize)
			throw std::exception("You can't create pointArray of size > maxPointArraySize");

		size = _size;
		points = new pointWrapper[size];
	}

	pointArray::pointArray(size_t _size, pointWrapperType _type) {
		if (_size > maxPointArraySize)
			throw std::exception("You can't create pointArray of size > maxPointArraySize");

		size = _size;
		points = new pointWrapper[size];

		for (size_t i = 0; i < size; i++)
			points[i].defineDataType(_type);
	}
	
	pointArray::pointArray(size_t _size, const pointWrapper& _pointWrapper) {
		if (_size > maxPointArraySize)
			throw std::exception("You can't create pointArray of size > maxPointArraySize");

		size = _size;
		points = new pointWrapper[size];
		for (size_t i = 0; i < size; i++)
			points[i] = _pointWrapper;
	}

	void pointArray::add(const pointWrapper& _pointWrapper) {
		pointWrapper* newPoints = new pointWrapper[(size + 1)];
		
		for (size_t i = 0; i < size; i++)
			newPoints[i] = points[i];

		newPoints[size] = _pointWrapper;
		size++;
		delete points;
		points = nullptr;
		points = newPoints;
	}

	void pointArray::remove(int _index) {

	}

	pointWrapper& pointArray::operator[](int _index) {
		return points[_index];
	}

	pointWrapper pointArray::at(int _index) const {
		pointWrapper temp = points[_index];
		return temp;
	}

	std::ostream& operator<< (std::ostream& _s, const pointArray& _pointArray) {
		_s << "{";
		for (size_t i = 0u; i < _pointArray.size; i++)
			_s << _pointArray.at(i) << ", ";
		_s << "}";

		return _s;
	}
}
