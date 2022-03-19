#pragma once

#include "point.h"

namespace comp_lab {
	class point2 : point_base {
	protected:
		int xx = 0;
		int yy = 0;

	public:
		point2();
		point2(int _x, int _y);
		point2(const point2& _point);
		point2(vector<int> _vector);

		// Getters
		virtual vector<int> getVector() const override;

		virtual int x() const;
		virtual int y() const;

		virtual int& operator[] (int index) override;
		virtual int at(int index) const override;

		// Copy operators
		virtual point2& operator= (const point_base& _point) override ;
		virtual point2& operator= (const vector<int>& _point) override;
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

// N - dimension
namespace comp_lab {

	class point_dynamic : public point_base {
	private:
		int* data = nullptr;

	public:
		point_dynamic(int _size) {
			if (size <= 0)
				throw std::exception("Wrong point dimension in constructor");

			size = _size;
			data = new int[size];
		}
	};

	using pointn = point_dynamic;
}