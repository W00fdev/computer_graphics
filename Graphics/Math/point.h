#pragma once
#include <ostream>
#include <vector>

// POINT 

namespace comp_lab {
	class point_base {
	protected:
		bool transposed = false;

	public:
		int size = 0;

		// Constructors
		point_base() {}
		point_base(int _size);
		point_base(const point_base& _point);

		// Getter
		virtual std::vector<int> getVector() const = 0;

		virtual int& operator[](int _index) = 0;
		virtual int  at(int _index) const = 0;

		// Copy operators
		virtual point_base& operator= (const point_base& _point) = 0;
		virtual point_base& operator= (const std::vector<int>& _vector) = 0;

		//// Invert operator
		//virtual const point_base& operator-() = 0;

		//// Sum and substraction operators
		//virtual const point_base operator+(const point_base& _point) = 0;
		//virtual const point_base operator-(const point_base& _point) = 0;
		//
		//// Sum/sub and equal operators
		//virtual point_base& operator+=(const point_base& _point) = 0;
		//virtual point_base& operator-=(const point_base& _point) = 0;
		//
		//// is Equal operator
		//virtual bool operator==(const point_base& _point) = 0;
	};
}