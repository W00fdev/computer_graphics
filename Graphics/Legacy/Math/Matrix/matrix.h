#pragma once

#include <exception>
#include <vector>

#include "../Point/point_varieties.h"
#include "PointContainer/point_container.h"

using std::vector;

namespace graphics {

	// Move to constants.h
	const int MATRIX_2_SIZE = 2;
	const int MATRIX_3_SIZE = 3;

	struct matrix_size {
		int size1, size2;
		matrix_size(int _size1 = 0, int _size2 = 0) {
			size1 = _size1;
			size2 = _size2;
		}
	};

	class matrix_base {
	protected:
		pointWrapper data;
		matrix_size size;

		bool transposed = false;
	public:
		matrix_base() {}

		void transpose() { transposed = !transposed; };

		virtual pointWrapper& operator[](int _index) = 0;
		virtual pointWrapper  at(int _index) const = 0;

		const matrix_size& getSize() const { return size; };
	};

	class matrix
	{
	public:
		matrix(int _size1, int _size2) {};
		matrix(const matrix& _matrix) {};

		//matrix sum(const matrix& _matrix);

		//void transpose();

		// Operators

		//matrix operator-() const;

		//matrix operator+(const matrix& _matrix);
		//matrix operator*(const matrix& _matrix);
		//matrix operator/(const matrix& _matrix);
		//matrix operator^(const int);				// pow and transpose

		//matrix& operator=(const matrix&& _matrix);

		//matrix& operator+=(const matrix& _matrix);
		//matrix& operator-=(const matrix& _matrix);

		// GETTERS
	};

	//class matrix2 : public matrix_base {
	//public:
	//	matrix2();
	//	matrix2(const matrix2& _matrix);
	//	//matrix2(const matrix& _matrix);

	//	//virtual pointContainer& operator[](int _index) override;
	//	//virtual pointContainer  at(int _index) const override;
	//};
}

