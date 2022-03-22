#pragma once

#include "../../Point/point_varieties.h"

namespace graphics {

	const int maxPointContainerSize = 10;

	class pointContainer {
	protected:
		point_base* pointData = nullptr;
		//size_t size;

	public:
		pointContainer() {}
		pointContainer(size_t size);
	};

	class pointContainer2 : public pointContainer {
	public:
		pointContainer2();
	};

	class pointContainer3 : public pointContainer {
	public:
		pointContainer3();
	};
}

