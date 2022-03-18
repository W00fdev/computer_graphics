#pragma once

#include <exception>
#include <vector>

using std::vector;

namespace comp_lab {
	class matrix
	{
	private:
		vector<vector<int>> data;
		
		int row_size = 0;
		int col_size = 0;

		bool transposed = false;

	public:
		matrix(int _rowSize, int _colSize);
		matrix(const vector<vector<int>>& _data);
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

		vector<int> getRows() const;
		vector<int> getCols() const;

		int getSizeRow() const;
		int getSizeCol() const;

		const vector<int>& operator[] (int index) const;
	};
}

