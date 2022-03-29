#pragma once

namespace graphics {
	// Max size of pointn.
	const int maxPointSize = 10;

	// Max size of pointArr.
	const int maxPointArraySize = 10;

	// Type of the pointWrapper
	enum class pointWrapperType { UNDEFINED = 1, POINT2 = 2, POINT3 = 3, POINTN = 4 };

	const pointWrapperType TYPEUNDEF = pointWrapperType::UNDEFINED;
	const pointWrapperType TYPE2 = pointWrapperType::POINT2;
	const pointWrapperType TYPE3 = pointWrapperType::POINT3;
	const pointWrapperType TYPEN = pointWrapperType::POINTN;
}