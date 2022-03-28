#pragma once
#include <ostream>
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
		virtual point_base& operator= (const point_base& _point) = 0;
		//virtual point_base& operator= (const std::vector<int>& _vector) = 0;

		// Operator scalar multiplying
		virtual point_base& operator*= (int _scalar) = 0;
	};
}