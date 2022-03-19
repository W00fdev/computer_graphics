#pragma once
#include <vector>

using std::vector;

// POINT 

namespace comp_lab {
	class point_base {
	protected:
		bool transposed = false;

	public:
		int size = 0;

		point_base() {}
		point_base(int _size);
		point_base(const point_base& _point);

		virtual point_base& operator= (const point_base& _point) = 0;
		virtual point_base& operator= (const vector<int>& _vector) = 0;

		virtual int& operator[](int _index) = 0;

		virtual int at(int _index) const = 0;

		virtual vector<int> getVector() const = 0;
	};
}