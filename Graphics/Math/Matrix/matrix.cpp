#include "matrix.h"

namespace graphics {

	matrix::matrix(int _rowSize, int _colSize) {
		if (_rowSize < 0 || _colSize < 0)
			throw std::exception("Invalid matrix size");

		row_size = _rowSize;
		col_size = _colSize;
	}

	matrix::matrix(const matrix& _matrix) {
		data = _matrix.data;

		row_size = _matrix.row_size;
		col_size = _matrix.col_size;
	}

	matrix matrix::sum(const matrix& _matrix) {
		if (_matrix.col_size != col_size || _matrix.row_size != row_size)
			throw std::exception("Wrong dimensions matrix's sum.");
		
		matrix result(row_size, col_size);
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				result.data[i][j] = data[i][j] + _matrix.data[i][j];
			}
		}
			
		return result;
	}

	matrix matrix::operator+(const matrix& _matrix)
	{
		return sum(_matrix);
	}

	matrix& matrix::operator+=(const matrix& _matrix)
	{
		return *this;
	}

	// GETTERS

	int matrix::getSizeRow() const {
		return row_size;
	}

	int matrix::getSizeCol() const {
		return col_size;
	}

}