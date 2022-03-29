#include <ostream>

#include "point_varieties.h"

namespace graphics {
	std::ostream& operator<< (std::ostream& _s, const point_base& _point) {
		_s << "{";
		for (int i = 0; i < _point.size; i++)
		{
			_s << _point.at(i);
			if (i + 1 < _point.size)
				_s << ", ";
		}
		_s << "}";
		return _s;
	}

	bool operator!= (const point_base& _point1, const point_base& _point2) {
		return !(_point1 == _point2);
	}
}

// POINT2
namespace graphics {

	point2::point2(int _x, int _y) {
		size = 2;
		xx = _x;
		yy = _y;
	}

	/*point2::point2(const std::vector<int>& _vector) {
		if (_vector.size() < 2)
			throw std::exception("Invalid vector size in point2 constructor");

		size = 2;
		xx = _vector[0];
		yy = _vector[1];
	}*/

	point2::point2(const point_base& _point) {
		size = 2;
		xx = _point.at(0);
		yy = _point.at(1);
	}

	// Getters
	/*std::vector<int> point2::getVector() const {
		return { xx, yy };
	}*/

	int point2::x() const {
		return xx;
	}

	int point2::y() const {
		return yy;
	}

	int point2::z() const {
		throw std::exception("Point2.z() doesn't exist.");
		return NULL;
	}

	int& point2::operator[] (int _index) {
		if (_index < 0 || _index >= 2)
			throw std::exception("Wrong index [] at point2");

		return _index == 0 ? xx : yy;
	}

	int point2::at(int _index) const {
		if (_index < 0 || _index >= 2)
			throw std::exception("Wrong index [] at point2");

		return _index == 0 ? xx : yy;
	}

	// Copy operators
	point_base& point2::operator= (const point_base& _point) {
		if (this == &_point)
			return *this;

		xx = _point.at(0);
		yy = _point.at(1);

		return *this;
	}
	/*point_base& point2::operator= (const std::vector<int>& _point) {
		if (_point.size() > 1)
		{
			xx = _point[0];
			yy = _point[1];
		}
		else {
			throw std::exception("invalid vector point2::operator=(vector)");
		}

		return *this;
	}*/

	// Invert operator
	const point_base& point2::operator-() {
		xx = -xx;
		yy = -yy;

		return *this;
	}

	// Multiply operator
	const point2 point2::operator*(const point_base& _point) const {
		return { xx * _point.at(0), yy * _point.at(1) };
	}

	const point2 point2::operator*(int _scalar) const {
		return { xx * _scalar, yy * _scalar };
	}

	// Sum and substraction operators
	const point2 point2::operator+(const point_base& _point) const {
		return { xx + _point.at(0), yy + _point.at(1) };
	}

	const point2 point2::operator-(const point_base& _point) const {
		return { xx - _point.at(0), yy - _point.at(1) };
	}

	// Multiplication operator
	point_base& point2::operator*=(const point_base& _point) {
		xx *= _point.at(0);
		yy *= _point.at(1);

		return *this;
	}

	point_base& point2::operator*=(int _scalar)
	{
		xx *= _scalar;
		yy *= _scalar;

		return *this;
	}

	// Sum/sub and equal operators
	point_base& point2::operator+=(const point_base& _point) {
		xx += _point.at(0);
		yy += _point.at(1);
		
		return *this;
	}

	point_base& point2::operator-=(const point_base& _point) {
		xx -= _point.at(0);
		yy -= _point.at(1);

		return *this;
	}

	// is Equal operator
	bool point2::operator==(const point_base& _point) const {
		return xx == _point.at(0) && yy == _point.at(1);
	}

	// Stream output operator 
	//std::ostream& operator<< (std::ostream& _s, const point2& _point) {
	//	_s << "point2 {" << _point.xx << ", " << _point.yy << "}";
	//	return _s;
	//}
}

// POINT3
namespace graphics {

	point3::point3(int _x, int _y, int _z) : point2(_x, _y) {
		size = 3;
		zz = _z;
	}

	/*point3::point3(const std::vector<int>& _vector){
		if (_vector.size() < 3)
			throw std::exception("Invalid vector size in point2 constructor");

		size = 3;
		xx = _vector[0];
		yy = _vector[1];
		zz = _vector[2];
	}*/

	point3::point3(const point_base& _point) : point2(_point) {
		size = 3;
		if (_point.size >= 3)
			zz = _point.at(2);
	}

	//std::vector<int> point3::getVector() const {
	//	return { xx, yy, zz };
	//}

	int point3::z() const {
		return zz;
	}

	int& point3::operator[] (int _index) {
		if (_index < 0 || _index >= 3)
			throw std::exception("Wrong index [] at point3");

		if (_index == 0)
			return xx;
		
		return _index == 1 ? yy : zz;
	}

	int point3::at(int _index) const {
		if (_index < 0 || _index >= 3)
			throw std::exception("Wrong index [] at point3");

		if (_index == 0)
			return xx;

		return _index == 1 ? yy : zz;
	}

	point_base& point3::operator= (const point_base& _point) {
		if (this == &_point)
			return *this;

		xx = _point.at(0);
		yy = _point.at(1);
		if (_point.size >= 3)
			zz = _point.at(2);

		return *this;
	}
	//point_base& point3::operator= (const std::vector<int>& _point) {
	//	if (_point.size() > 2)
	//	{
	//		xx = _point[0];
	//		yy = _point[1];
	//		zz = _point[2];
	//	}
	//	else {
	//		throw std::exception("invalid vector point3::operator=(vector)");
	//	}

	//	return *this;
	//}

	// Invert operator
	const point_base& point3::operator-() {
		xx = -xx;
		yy = -yy;
		zz = -zz;
		
		return *this;
	}

	// Multiply operator
	const point3 point3::operator*(const point_base& _point) const {
		point3 temp = *this;
		if (_point.size >= 3)
			temp.zz *= _point.at(2);
		else
			temp.zz = 0;
		
		temp.xx *= _point.at(0);
		temp.yy *= _point.at(1);

		return temp;
	}

	const point3 point3::operator*(int _scalar) const {
		return { xx * _scalar, yy * _scalar, zz * _scalar };
	}

	// Sum and substraction operators
	const point3 point3::operator+(const point_base& _point) const {
		point3 temp = *this;
		if (_point.size >= 3)
			temp.zz += _point.at(2);

		temp.xx += _point.at(0);
		temp.yy += _point.at(1);

		return temp;
	}

	const point3 point3::operator-(const point_base& _point) const {
		point3 temp = *this;
		if (_point.size >= 3)
			temp.zz -= _point.at(2);

		return { temp.xx + _point.at(0), temp.yy + _point.at(1), temp.zz };
	}

	// Multiplication operator
	point_base& point3::operator*=(const point_base& _point) {
		if (_point.size < 3)
			zz *= 0;
		else
			zz *= _point.at(2);

		xx *= _point.at(0);
		yy *= _point.at(1);

		return *this;
	}
	
	point_base& point3::operator*=(int _scalar)
	{
		xx *= _scalar;
		yy *= _scalar;
		zz *= _scalar;

		return *this;
	}

	// Sum/sub and equal operators
	point_base& point3::operator+=(const point_base& _point) {
		xx += _point.at(0);
		yy += _point.at(1);
		if (_point.size >= 3)
			zz += _point.at(2);

		return *this;
	}

	point_base& point3::operator-=(const point_base& _point) {
		xx -= _point.at(0);
		yy -= _point.at(1);
		if (_point.size >= 3)
			zz -= _point.at(2);

		return *this;
	}

	// is Equal operator
	bool point3::operator==(const point_base& _point) const {
		bool zz_equals = false;
		if (_point.size == 3)
			zz_equals = zz == _point.at(2);
		
		return xx == _point.at(0) && yy == _point.at(1) && zz_equals;
	}

	// Stream output operator 
	//std::ostream& operator<< (std::ostream& _s, const point3& _point) {
	//	_s << "point3 {" << _point.xx << ", " << _point.yy << ", " << _point.zz << "}";
	//	return _s;
	//}
}

// POINTN
namespace graphics {
	int& pointn::operator[](int _index) {
		if (_index >= size || _index < 0)
			throw std::exception("Wrong index at pointn[]");

		return data[_index];
	}

	int  pointn::at(int _index) const {
		if (_index >= size || _index < 0)
			throw std::exception("Wrong index at pointn[]");

		return data[_index];
	}

	int pointn::x() const {
		return at(0);
	}

	int pointn::y() const {
		return at(1);
	}

	int pointn::z() const {
		return at(2);
	}

	// Copy operators
	point_base& pointn::operator= (const point_base& _point) {
		if (data != nullptr)
			delete data;

		size = _point.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = _point.size;

		return *this;
	}

	const point_base& pointn::operator-() {
		for (int i = 0; i < size; i++)
			data[i] = -data[i];

		return *this;
	}

	const pointn operator+(const point_base& _point1, const point_base& _point2) {

	}

	const pointn operator-(const point_base& _point1, const point_base& _point2) {

	}

	// Operators multiplying
	point_base& pointn::operator*= (const point_base& _point) {
		if (size != _point.size)
			throw std::exception("Wrong dimensions in pointn::operator*=()");

		for (int i = 0; i < size; i++)
			data[i] *= _point.at(i);

		return *this;
	}

	point_base& pointn::operator*= (int _scalar) {
		for (int i = 0; i < size; i++)
			data[i] *= _scalar;
		
		return *this;
	}

	point_base& pointn::operator+=(const point_base& _point) {
		*this = *this + _point;
		return *this;
	}

	point_base& pointn::operator-=(const point_base& _point) {
		*this = *this - _point;
		return *this;
	}

	bool pointn::operator== (const point_base& _point) const {
		if (size != _point.size)
			return false;

		for (int i = 0; i < size; i++) {
			if (data[i] != _point.at(i))
				return false;
		}

		return true;
	}
}