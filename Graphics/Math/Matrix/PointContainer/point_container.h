#pragma once

#include "../../Point/point_varieties.h"

namespace graphics {

	const int maxPointContainerSize = 10;

	enum class pointContainerType { UNDEFINED = 0, POINT2 = 1, POINT3 = 2, POINTN = 3};

	class pointContainer {
	protected:
		point_base* pointData = nullptr;
		pointContainerType type = pointContainerType::UNDEFINED;
		//size_t size;

		void defineDataType(size_t _size);

	public:
		pointContainer() {}
		pointContainer(size_t size);
		virtual ~pointContainer();

		virtual pointContainer& operator= (const pointContainer& _point);
	};

	class pointContainer2 : public pointContainer {
	public:
		pointContainer2();
		~pointContainer2();
	};

	class pointContainer3 : public pointContainer {
	public:
		pointContainer3();
		~pointContainer3();
	};
}

