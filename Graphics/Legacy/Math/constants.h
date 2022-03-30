#pragma once

namespace graphics {
	// Max size of pointn.
	const int maxPointSize = 10;

	// Max size of pointArr.
	const int maxPointArraySize = 10;

	// Type of the pointWrapper
	enum class pointType { /*UNCHECK = 0,*/ UNDEFINED = 1, POINT2 = 2, POINT3 = 3, POINTN = 4 };

	// Only for pointArrayConcrete (matrixPoints) [not needed]
	// const pointType TYPEUNCHECK = pointType::UNDEFINED;
	const pointType TYPEUNDEF	= pointType::UNDEFINED;
	const pointType TYPE2		= pointType::POINT2;
	const pointType TYPE3		= pointType::POINT3;
	const pointType TYPEN		= pointType::POINTN;
}