#include "point.h"

namespace comp_lab {
	point_base::point_base(int _size) {
		size = _size;
	}

	point_base::point_base(const point_base& _point) {
		size = _point.size;
	}

	//int& point_base::operator[](int _index) {
	//	return emptyData;
	//}

	//int point_base::at(int _index) const {
	//	return emptyData;
	//}
}