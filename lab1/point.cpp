#include "point.h"

// POINT2

namespace comp_lab {

	point2::point2(int _x, int _y) {
		xx = _x;
		yy = _y;
	}

	point2::point2(const point2& _point) {
		xx = _point.x();
		yy = _point.y();
	}

	point2::point2(vector<int> _vector) {
		if (_vector.size() < 2)
			throw std::exception("Invalid vector size in point2 constructor");

		xx = _vector[0];
		xx = _vector[1];
	}

	point2::point2(const matrix& _matrix) {
		if (_matrix.getSizeRow() < 1 || _matrix.getSizeCol() < 2)
			throw std::exception("Invalid matrix size in point2 constructor");

		xx = _matrix[0][0];
		yy = _matrix[0][1];
	}

	// Getters
	vector<int> point2::getVector() const {
		return { xx, yy };
	}

	matrix point2::getMatrix() const {
		return matrix({ {xx, yy} });
	}

	int point2::x() const {
		return xx;
	}

	int point2::y() const {
		return yy;
	}

	int point2::operator[] (int index) {
		if (index < 0 || index >= 2)
			throw std::exception("Wrong index [] at point2");

		return index == 0 ? xx : yy;
	}


	// Copy operators

	point2& point2::operator= (const point2&& _point) {

	}

	point2& point2::operator= (const vector<int>&& _point) {

	}

	point2& point2::operator= (const matrix&& _matrix) {

	}

}


// POINT3

namespace comp_lab {

	point3::point3(int _x, int _y, int _z) {
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
}