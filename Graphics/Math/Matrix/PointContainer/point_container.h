#pragma once

#include "../../Point/point_varieties.h"

namespace graphics {
	class pointWrapper {
	protected:
		point_base* pointData = nullptr;
		pointWrapperType type = pointWrapperType::UNDEFINED;

		void checkWrongType(const pointWrapperType _type, const char* _functionPlace) const;
	public:

		pointWrapper();
		pointWrapper(size_t _size);
		pointWrapper(pointWrapperType _type);
		pointWrapper(const pointWrapper& _pointWrapper);
		~pointWrapper();

		void defineDataType(size_t _size);
		void defineDataType(pointWrapperType _type);

		int& operator[](int _index); 
		int at(int _index) const;

		int x() const;
		int y() const;
		int z() const;

		pointWrapper& operator= (const pointWrapper& _pointWrapper);
		pointWrapper& operator= (const point_base& _point);

		friend std::ostream& operator<<(std::ostream& _s, const pointWrapper& _point);
	};
}

// POINT_ARRAY

/// <summary>
///		pointArray is very static, so the class doesn't need a capacity;
/// </summary>
namespace graphics {
	class pointArray {
	protected:
		pointWrapper* points = nullptr;
	public:
		size_t size;

		pointArray();
		pointArray(size_t _size);
		pointArray(size_t _size, pointWrapperType _type);
		pointArray(size_t _size, const pointWrapper& _pointWrapper);

		void add(const pointWrapper& _pointWrapper);
		void remove(int _index);

		pointWrapper& operator[](int _index);
		pointWrapper at(int _index) const;

		/*void print() const;*/
		friend std::ostream& operator<< (std::ostream& _s, const pointArray& _pointArray);

		// Operators:
		pointArray& operator= (const pointArray& _pointArray);

		// Invert operator
		const pointArray& operator-();

		// Multiply operator
		const pointArray operator*(const pointArray& _pointArray) const;
		const pointArray operator*(int _scalar) const;

		// Sum and substraction operators
		const pointArray operator+(const pointArray& _pointArray) const;
		const pointArray operator-(const pointArray& _pointArray) const;

		// Sum/sub and equal operators
		pointArray& operator+=(const pointArray& _pointArray);
		pointArray& operator-=(const pointArray& _pointArray);

		// Multiplication operator
		pointArray& operator*=(const pointArray& _pointArray);
		pointArray& operator*= (int _scalar);

		// is Equal operator
		bool operator==(const pointArray& _pointArray);
	};
}