#pragma once

#include "matrix.h"

namespace comp_lab {
	class point2 {
	protected:
		int xx = 0;
		int yy = 0;

	public:
		point2() {}
		point2(int _x, int _y);
		point2(const point2& _point);
		point2(vector<int> _vector);
		point2(const matrix& _matrix);

		// Getters
		virtual vector<int> getVector() const;
		virtual matrix getMatrix() const;

		int x() const;
		int y() const;

		virtual int operator[] (int index);

		// Copy operators
		virtual point2& operator= (const point2& _point) noexcept;

		virtual point2& operator= (const vector<int>& _point);
		virtual point2& operator= (const matrix& _matrix);
	};

	/*class point3 : public point2 {
	private:
		int zz;

	public:
		point3(int _x, int _y, int _z);
		point3(const point3& _point);
		point3(vector<int> _vector);
		point3(const matrix& _matrix);

		// Getters
		vector<int> getVector() const;
		matrix getMatrix() const;

		int z() const;

		int operator[] (int index);

		// Copy operators

		point3& operator= (const point3& _point) noexcept;
		point3& operator= (const vector<int>& _point);
		point3& operator= (const matrix& _matrix);
		
	};
	*/
}