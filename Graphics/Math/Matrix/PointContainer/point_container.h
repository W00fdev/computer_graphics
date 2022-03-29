#pragma once

#include "../../Point/point_varieties.h"

// POINT_WRAPPER
namespace graphics {
	class pointWrapper {
	protected:
		point_base* pointData = nullptr;
		pointType type = TYPEUNDEF;

		void checkWrongType(const pointType _type, const char* _functionPlace) const;
	public:

		pointWrapper();
		pointWrapper(size_t _size);
		pointWrapper(pointType _type);
		pointWrapper(const pointWrapper& _pointWrapper);
		~pointWrapper();

		void defineDataType(size_t _size);
		void defineDataType(pointType _type);

		int& operator[](int _index); 
		int at(int _index) const;

		point_base& getPointBase();

		int x() const;
		int y() const;
		int z() const;

		pointWrapper& operator= (const pointWrapper& _pointWrapper);
		pointWrapper& operator= (const point_base& _point);

		bool operator==(const pointWrapper& _pointWrapper);
		bool operator!=(const pointWrapper& _pointWrapper);

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
		pointArray(size_t _size, pointType _type);
		pointArray(size_t _size, const pointWrapper& _pointWrapper);
		pointArray(const pointArray& _pointArray);

		virtual void add(const pointWrapper& _pointWrapper);
		void remove(int _index);

		pointWrapper& operator[](int _index);
		pointWrapper at(int _index) const;

		/*void print() const;*/
		friend std::ostream& operator<< (std::ostream& _s, const pointArray& _pointArray);

		// Operators:
		virtual pointArray& operator= (const pointArray& _pointArray);

		// Invert operator
		const pointArray& operator-();

		// Multiply operator
		virtual const pointArray operator*(const pointArray& _pointArray) const;
		const pointArray operator*(int _scalar) const;

		// Sum and substraction operators
		virtual const pointArray operator+(const pointArray& _pointArray) const;
		virtual const pointArray operator-(const pointArray& _pointArray) const;

		// Sum/sub and equal operators
		virtual pointArray& operator+=(const pointArray& _pointArray);
		virtual pointArray& operator-=(const pointArray& _pointArray);

		// Multiplication operator
		virtual pointArray& operator*=(const pointArray& _pointArray);
		virtual pointArray& operator*= (int _scalar);

		// is Equal operator
		virtual bool operator==(const pointArray& _pointArray) const;
		bool operator!=(const pointArray& _pointArray) const;
	};
}

namespace graphics {
	
	// Constant type of values
	class pointArrayConcrete : public pointArray {
	protected:
		pointType arrayType = TYPEUNDEF;
	public:

	};

	using matrixPoints = pointArrayConcrete;
}