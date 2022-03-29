#include "point_container.h"

// POINT_WRAPPER
namespace graphics {
	pointWrapper::pointWrapper() {
		type = TYPEUNDEF;
	}

	pointWrapper::pointWrapper(size_t _size) {
		defineDataType(_size);
	}

	pointWrapper::pointWrapper(pointType _type) {
		defineDataType(_type);
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
			type = pointType::POINT2;
		}
		else if (_size == 3)
		{
			pointData = new point3();
			type = pointType::POINT3;
		}
		else {
			pointData = new pointn(_size);
			type = pointType::POINTN;
		}
	}

	void pointWrapper::defineDataType(pointType _type) {
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
			type = pointType::UNDEFINED;
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
			type = pointType::UNDEFINED;
			delete pointData;
		}

		defineDataType(_point.size);
		pointData->operator=(_point);
		return *this;
	}

	void pointWrapper::checkWrongType(const pointType _type, const char* _functionPlace) const {
		if (type != _type)
			return;			// OK

		std::string errorType;
		switch (_type) {
		case pointType::UNDEFINED:
			errorType = "UNDEFINED";
			break;
		case pointType::POINT2:
			errorType = "POINT2";
			break;
		case pointType::POINT3:
			errorType = "POINT3";
			break;
		case pointType::POINTN:
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

	point_base& pointWrapper::getPointBase() {
		return *(pointData);
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

	bool pointWrapper::operator==(const pointWrapper& _pointWrapper) {
		return type == _pointWrapper.type && (*pointData) == (*_pointWrapper.pointData);
	}

	bool pointWrapper::operator!=(const pointWrapper& _pointWrapper) {
		return type != _pointWrapper.type || (*pointData) != (*_pointWrapper.pointData);
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

	pointArray::pointArray(size_t _size, pointType _type) {
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

	pointArray::pointArray(const pointArray& _pointArray) {
		size = 0;
		this->operator=(_pointArray);
	}

	void pointArray::add(const pointWrapper& _pointWrapper) {
		pointWrapper* newPoints = new pointWrapper[(size + 1)];
		
		for (size_t i = 0; i < size; i++)
			newPoints[i] = points[i];

		newPoints[size] = _pointWrapper;
		size++;
		delete[] points;
		points = newPoints;
	}

	// Without capacity variant.
	void pointArray::remove(int _index) {
		if (_index < 0 || _index >= maxPointArraySize)
			throw std::exception("Wrong index at pointArray::remove()");

		if (size > 1) {
			pointWrapper* newPoints = new pointWrapper[(size - 1)];

			size_t j = 0;
			for (size_t i = 0; i < size; i++)
				if (i != _index)
					newPoints[j++] = points[i];

			size--;
			delete[] points;
			points = newPoints;
			return;
		} 

		if (points == nullptr)
		{
			throw std::exception("Bad try to remove element in empty pointArray");
			return;
		}

		// Only 1 element in array.
		delete[] points;
		points = nullptr;
		size = 0;
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
		if (_pointArray.size == 0u)
			_s << "EMPTY POINTS";
		for (size_t i = 0u; i < _pointArray.size; i++)
		{
			_s << _pointArray.at(i);
			if (i + 1 < _pointArray.size)
				_s << ", ";
		}
		_s << "}";

		return _s;
	}

	// Operators:
	pointArray& pointArray::operator= (const pointArray& _pointArray) {
		if (size != 0 && points != nullptr) {
			delete[] points;
			points = nullptr;
		}
		
		size = _pointArray.size;
		if (size > 0)
			points = new pointWrapper[size];

		for (size_t i = 0; i < size; i++)
			points[i] = _pointArray.at(i);

		return *this;
	}

	// Invert operator
	const pointArray& pointArray::operator-() {
		for (size_t i = 0; i < size; i++)
			-(points[i].getPointBase());
	}

	// Multiply operator
	const pointArray pointArray::operator*(const pointArray& _pointArray) const {
		if (_pointArray.size != size)
			throw std::exception("Wrong dimensions in pointArray::operator*()");

		pointArray result = *this;

		for (size_t i = 0; i < size; i++)
			result[i].getPointBase() *= _pointArray.at(i).getPointBase();
	
		return result;
	}

	const pointArray pointArray::operator*(int _scalar) const {
		pointArray result = *this;

		for (size_t i = 0; i < size; i++)
			result[i].getPointBase() *= _scalar;
		
		return result;
	}

	// Sum and substraction operators
	const pointArray pointArray::operator+(const pointArray& _pointArray) const {
		if (_pointArray.size != size)
			throw std::exception("Wrong dimensions in pointArray::operator*()");

		pointArray result = *this;

		for (size_t i = 0; i < size; i++)
			result[i].getPointBase() += _pointArray.at(i).getPointBase();

		return result;
	}

	const pointArray pointArray::operator-(const pointArray& _pointArray) const {
		if (_pointArray.size != size)
			throw std::exception("Wrong dimensions in pointArray::operator*()");

		pointArray result = *this;
		return -result + _pointArray;
	}

	// Sum/sub and equal operators
	pointArray& pointArray::operator+=(const pointArray& _pointArray) {
		if (_pointArray.size != size)
			throw std::exception("Wrong dimensions in pointArray::operator*()");

		for (size_t i = 0; i < size; i++)
			points[i].getPointBase() += _pointArray.at(i).getPointBase();

		return *this;
	}

	pointArray& pointArray::operator-=(const pointArray& _pointArray) {
		if (_pointArray.size != size)
			throw std::exception("Wrong dimensions in pointArray::operator*()");

		*this = -(*this) + _pointArray;
		return *this;
	}

	// Multiplication operator
	pointArray& pointArray::operator*=(const pointArray& _pointArray) {
		if (_pointArray.size != size)
			throw std::exception("Wrong dimensions in pointArray::operator*=()");

		for (size_t i = 0; i < size; i++)
			points[i].getPointBase() *= _pointArray.at(i).getPointBase();

		return *this;
	}

	pointArray& pointArray::operator*= (int _scalar) {
		for (size_t i = 0; i < size; i++)
			points[i].getPointBase() *= _scalar;

		return *this;
	}

	// is Equal operator
	bool pointArray::operator==(const pointArray& _pointArray) const {
		if (size != _pointArray.size)
			return false;

		for (size_t i = 0; i < size; i++) {
			if (points[i] != _pointArray.points->at(i))
				return false;
		}

		return true;
	}

	bool pointArray::operator!=(const pointArray& _pointArray) const {
		return ((*this) == _pointArray);
	}
}
