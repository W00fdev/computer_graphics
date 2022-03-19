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

	point2::point2(const point2& _point) : point2() {
		xx = _point.x();
		yy = _point.y();
	}

	point2::point2(vector<int> _vector) : point2() {
		if (_vector.size() < 2)
			throw std::exception("Invalid vector size in point2 constructor");

		xx = _vector[0];
		yy = _vector[1];
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
	point2& point2::operator= (const point_base& _point) {
		if (this == &_point)
			return *this;

		xx = _point.at(0);
		yy = _point.at(1);

		return *this;
	}

	point2& point2::operator= (const vector<int>& _point) {
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

	/*point3::point3(int _x, int _y, int _z) {
		xx = _x;
		yy = _y;
		zz = _z;
	}

	point3::point3(const point3& _point) {
		xx = _point.x();
		yy = _point.y();
		zz = _point.z();
	}

	point3::point3(vector<int> _vector) {
		if (_vector.size() < 3)
			throw std::exception("Invalid vector size in point2 constructor");

		xx = _vector[0];
		yy = _vector[1];
		zz = _vector[2];
	}

	point3::point3(const matrix& _matrix) {
		if (_matrix.getSizeRow() < 1 || _matrix.getSizeCol() < 3)
			throw std::exception("Invalid matrix size in point3 constructor");

		xx = _matrix[0][0];
		yy = _matrix[0][1];
		zz = _matrix[0][2];
	}


	point3& point3::operator= (const point3& _point) noexcept {
		if (this == &_point)
			return *this;

		xx = _point.xx;
		yy = _point.yy;

		return *this;
	}

	point3& point3::operator= (const vector<int>& _point) {
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

	point3& point3::operator= (const matrix& _matrix) {
		if (_matrix.getSizeRow() > 0 && _matrix.getSizeRow() > 2) {
			xx = _matrix[0][0];
			yy = _matrix[0][1];
			zz = _matrix[0][2];
		}
		else if (_matrix.getSizeRow() > 2 && _matrix.getSizeRow() > 0) {
			xx = _matrix[0][0];
			yy = _matrix[1][0];
			zz = _matrix[2][0];
		}
		else {
			throw std::exception("invalid matrix point3::operator=(matrix)");
		}

		return *this;
	}
	*/
}