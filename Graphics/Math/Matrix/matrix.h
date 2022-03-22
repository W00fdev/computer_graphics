#pragma once

#include <exception>
#include <vector>

#include "../Point/point_varieties.h"
#include "PointContainer/point_container.h"

using std::vector;

namespace graphics {

	class matrix_base {
	protected:
		int size1;
		int size2;

		pointContainer data;
		bool transposed = false;

	public:
		matrix_base() {}

		virtual void transpose() = 0;

		virtual pointContainer& operator[](int _index) = 0;
		virtual pointContainer  at(int _index) const = 0;
	};

	class matrix
	{
	private:
		vector<vector<int>> data;
		
		// Can't name row and call because of transpose functionality.
		int row_size = 0;
		int col_size = 0;

		bool transposed = false;

	public:
		matrix(int _rowSize, int _colSize);
		matrix(const matrix& _matrix);

		matrix sum(const matrix& _matrix);

		void transpose();

		// Operators

		matrix operator-() const;

		matrix operator+(const matrix& _matrix);
		matrix operator*(const matrix& _matrix);
		matrix operator/(const matrix& _matrix);
		matrix operator^(const int);				// pow and transpose

		matrix& operator=(const matrix&& _matrix);

		matrix& operator+=(const matrix& _matrix);
		matrix& operator-=(const matrix& _matrix);

		// GETTERS

		int getSizeRow() const;
		int getSizeCol() const;
	};
}

