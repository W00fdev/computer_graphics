#pragma once

#include "../../Point/point_varieties.h"

namespace graphics {
	// It's best to use Undefined inheritor.
	enum class pointContainerType { UNDEFINED = 1, POINT2 = 2, POINT3 = 3, POINTN = 4};

	// Move this to constants.h
	const int maxPointContainerSize = 10;

	const pointContainerType TYPEUNDEF	= pointContainerType::UNDEFINED;
	const pointContainerType TYPE2		= pointContainerType::POINT2;
	const pointContainerType TYPE3		= pointContainerType::POINT3;
	const pointContainerType TYPEN		= pointContainerType::POINTN;

	class pointContainer {
	protected:
		point_base* pointData = nullptr;
		pointContainerType type = pointContainerType::UNDEFINED;

		void checkWrongType(const pointContainerType _type, const char* _functionPlace) const;
	public:
		int size = 0;

		pointContainer() {}
		pointContainer(size_t _size);
		~pointContainer();

		void defineDataType(size_t _size);

		int& operator[](int _index); 
		int at(int _index) const;

		int x() const;
		int y() const;
		int z() const;

		pointContainer& operator= (const pointContainer& _pointContainer);
		pointContainer& operator= (const point_base& _point);
	};
}

