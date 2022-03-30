#pragma once
#include <vector>

using std::vector;

namespace graphics {

class Matrix
{
public:
	Matrix(int _square_size = 0, float _value = 0.0);
	Matrix(int _row_size, int _col_sile, float _value = 0.0);
	Matrix(int _row_size, int _col_sile, vector<float> _vec);
	Matrix(const Matrix& _matrix);

	void Add(vector<float> _row) noexcept;
	void RemoveRow(size_t row_index);
	void RemoveCol(size_t col_index);

	// -------------------------- Base Operators --------------------------

	Matrix& Negative() noexcept;
	
	Matrix Sum(const Matrix& _matrix) const noexcept;
	Matrix Sub(const Matrix& _matrix) const noexcept;
	Matrix Mul(const Matrix& _matrix) const noexcept;
	Matrix Mul(float _scalar) const noexcept;
	Matrix Div(float _scalar) const noexcept;

	void Transpose() noexcept;
	void Inverse() noexcept;

	// -------------------------- Operators Redefinition --------------------------

	Matrix operator-() const noexcept;

	Matrix operator+(const Matrix& _matrix) const noexcept;
	Matrix operator-(const Matrix& _matrix) const noexcept;
	Matrix operator*(const Matrix& _matrix) const noexcept;
	Matrix operator/(float _scalar) const noexcept;

	Matrix& operator=(const Matrix& _matrix) noexcept;
	Matrix& operator+=(const Matrix& _matrix) noexcept;
	Matrix& operator-=(const Matrix& _matrix) noexcept;
	Matrix& operator*=(const Matrix& _matrix) noexcept;
	Matrix& operator*=(float _scalar) noexcept;
	Matrix& operator/=(float _scalar) noexcept;

	inline bool operator==(const Matrix& _matrix) const noexcept;
	inline bool operator!=(const Matrix& _matrix) const noexcept;

	// -------------------------- GETTERS --------------------------

	float& operator()(size_t row_index, size_t col_index);
	float at(size_t row_index, size_t col_index) const;

	vector<float> GetRow(size_t _index) const noexcept;
	vector<float> GetCol(size_t _index) const noexcept;

public:
	bool transposed{ false };

private:
	vector<float> data {};
	size_t row_size{ 0 };
	size_t col_size{ 0 };

	void Resize(size_t new_row_size, size_t new_col_size);
};

}

