#include "point_varieties.h"

// POINT2
namespace comp_lab {

	point2::point2() {
		size = 2;
	}

	point2::point2(int _x, int _y) : point2() {
		xx = _x;
		yy = _y;
	}

	point2::point2(const vector<int>& _vector) : point2() {
		if (_vector.size() < 2)
			throw std::exception("Invalid vector size in point2 constructor");

		xx = _vector[0];
		yy = _vector[1];
	}

	point2::point2(const point_base& _point) : point2() {
		xx = _point.at(0);
		yy = _point.at(1);
	}

	// Getters
	vector<int> point2::getVector() const {
		return { xx, yy };
	}

	int point2::x() const {
		return xx;
	}

	int point2::y() const {
		return yy;
	}

	int& point2::operator[] (int index) {
		if (index < 0 || index >= 2)
			throw std::exception("Wrong index [] at point2");

		return index == 0 ? xx : yy;
	}

	int point2::at(int index) const {
		if (index < 0 || index >= 2)
			throw std::exception("Wrong index [] at point2");

		return index == 0 ? xx : yy;
	}

	// Copy operators
	point_base& point2::operator= (const point_base& _point) {
		if (this == &_point)
			return *this;

		xx = _point.at(0);
		yy = _point.at(1);

		return *this;
	}
	point_base& point2::operator= (const vector<int>& _point) {
		if (_point.size() > 1)
		{
			xx = _point[0];
			yy = _point[1];
		}
		else {
			throw std::exception("invalid vector point2::operator=(vector)");
		}

		return *this;
	}
}

// POINT3
namespace comp_lab {

	point3::point3() {
		size = 3;
	}

	point3::point3(int _x, int _y, int _z) : point2(_x, _y) {
		point3();
		zz = _z;
	}

	point3::point3(const vector<int>& _vector) : point3() {
		if (_vector.size() < 3)
			throw std::exception("Invalid vector size in point2 constructor");

		xx = _vector[0];
		yy = _vector[1];
		zz = _vector[2];
	}

	point3::point3(const point_base& _point) : point2(_point) {
		point3();
		if (_point.size >= 3)
			zz = _point.at(2);
	}

	vector<int> point3::getVector() const {
		return { xx, yy, zz };
	}

	int point3::z() const {
		return zz;
	}

	int& point3::operator[] (int index) {
		if (index < 0 || index >= 3)
			throw std::exception("Wrong index [] at point3");

		if (index == 0)
			return xx;
		
		return index == 1 ? yy : zz;
	}

	int point3::at(int index) const {
		if (index < 0 || index >= 3)
			throw std::exception("Wrong index [] at point3");

		if (index == 0)
			return xx;

		return index == 1 ? yy : zz;
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
	point_base& point3::operator= (const vector<int>& _point) {
		if (_point.size() > 2)
		{
			xx = _point[0];
			yy = _point[1];
			zz = _point[2];
		}
		else {
			throw std::exception("invalid vector point3::operator=(vector)");
		}

		return *this;
	}
}