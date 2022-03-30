#include "matrix.h"

// MATRIX_BASE (in .h)

// MATRIX2
namespace graphics {
	//matrix2::matrix2() {
	//	size = { MATRIX_2_SIZE, MATRIX_2_SIZE };
	//	data.defineDataType(MATRIX_2_SIZE);
	//}

	//matrix2::matrix2(const matrix2& _matrix) {
	//	size = { MATRIX_2_SIZE, MATRIX_2_SIZE };
	//	data = _matrix.data;
	//}

	//matrix2::matrix2(const matrix& _matrix) {
	//	if (_matrix.getSize())
	//	size = { MATRIX_2_SIZE, MATRIX_2_SIZE };
	//}

	//pointContainer& matrix2::operator[](int _index) {
	//	
	//}

	//pointContainer  matrix2::at(int _index) const {

	//}
}

// MATRIX
namespace graphics {

	//matrix::matrix(int _rowSize, int _colSize) {
	//	if (_rowSize < 0 || _colSize < 0)
	//		throw std::exception("Invalid matrix size");

	//	row_size = _rowSize;
	//	col_size = _colSize;
	//}

	//matrix::matrix(const matrix& _matrix) {
	//	data = _matrix.data;

	//	row_size = _matrix.row_size;
	//	col_size = _matrix.col_size;
	//}

	//matrix matrix::sum(const matrix& _matrix) {
	//	if (_matrix.col_size != col_size || _matrix.row_size != row_size)
	//		throw std::exception("Wrong dimensions matrix's sum.");
	//	
	//	matrix result(row_size, col_size);
	//	for (int i = 0; i < row_size; i++) {
	//		for (int j = 0; j < col_size; j++) {
	//			result.data[i][j] = data[i][j] + _matrix.data[i][j];
	//		}
	//	}
	//		
	//	return result;
	//}

	//matrix matrix::operator+(const matrix& _matrix)
	//{
	//	return sum(_matrix);
	//}

	//matrix& matrix::operator+=(const matrix& _matrix)
	//{
	//	return *this;
	//}

	//// GETTERS

	//int matrix::getSizeRow() const {
	//	return row_size;
	//}

}