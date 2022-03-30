#pragma once

#include <ostream>
#include "../constants.h"

//#include <vector>

// POINT 

namespace graphics {
	class point_base {
	protected:
		bool transposed = false;

	public:
		int size = 0;

		// Constructors
		point_base() {}

		// Getter
		//virtual std::vector<int> getVector() const = 0;

		virtual int& operator[](int _index) = 0;
		virtual int  at(int _index) const = 0;

		virtual int x() const = 0;
		virtual int y() const = 0;
		virtual int z() const = 0;

		// Copy operators
		point_base& operator= (const point_base& _point);
		//virtual point_base& operator= (const std::vector<int>& _vector) = 0;

		// Invert operator
		virtual const point_base& operator-() = 0;

		// Operator scalar multiplying
		virtual point_base& operator*= (const point_base& _point) = 0;
		virtual point_base& operator*= (int _scalar) = 0;

		virtual point_base& operator+= (const point_base& _point) = 0;
		virtual point_base& operator-= (const point_base& _point) = 0;

		virtual bool operator== (const point_base& _point) const = 0;

		friend bool operator!= (const point_base& _point1, const point_base& _point2);

		friend std::ostream& operator<< (std::ostream& s, const point_base& point);
	};

	std::ostream& operator<< (std::ostream& _s, const point_base& _point);

	point_base& point_base::operator= (const point_base& _point) {
		if (size != _point.size)
			throw std::exception("Wrong dimensions in point_base::operator=()");

		for (int i = 0; i < size; i++)
			this->operator[](i) = _point.at(i);

		return *this;
	}
}