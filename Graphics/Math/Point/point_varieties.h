#pragma once

#include "point.h"

namespace graphics {
	class point2 : public point_base {
	protected:
		int xx = 0;
		int yy = 0;

	public:
		// Constructors
		//point2();
		point2(int _x = 0, int _y = 0);
		//point2(const std::vector<int>& _vector);
		point2(const point_base& _point);

		// Getters
		//virtual std::vector<int> getVector() const override;

		virtual int x() const override;
		virtual int y() const override;
		virtual int z() const override;

		virtual int& operator[] (int index) override;
		virtual int  at(int index) const override;

		// Copy operators
		virtual point_base& operator= (const point_base& _point) override;
		//virtual point_base& operator= (const std::vector<int>& _point) override;

		// Invert operator
		virtual const point_base& operator-();

		// Multiply operator
		const point2 operator*(const point_base& _point) const;
		const point2 operator*(int _scalar) const;

		// Sum and substraction operators
		const point2 operator+(const point_base& _point) const;
		const point2 operator-(const point_base& _point) const;

		// Sum/sub and equal operators
		virtual point_base& operator+=(const point_base& _point);
		virtual point_base& operator-=(const point_base& _point);

		// Multiplication operator
		virtual point_base& operator*=(const point_base& _point);
		virtual point_base& operator*= (int _scalar) override;

		// is Equal operator
		virtual bool operator==(const point_base& _point);

		// Stream output operator 
		//friend std::ostream& operator<< (std::ostream& _s, const point2& _point);
	};

	class point3 : public point2 {
	protected:
		int zz = 0;

	public:
		//point3();
		point3(int _x = 0, int _y = 0, int _z = 0);
		//point3(const std::vector<int>& _vector);
		point3(const point_base& _point);

		// Getters
		//std::vector<int> getVector() const override;

		virtual int z() const override;

		int& operator[] (int index) override;
		int at(int index) const override;

		// Copy operators
		point_base& operator= (const point_base& _point) override;
		//point_base& operator= (const std::vector<int>& _point) override;

		// Invert operator
		virtual const point_base& operator-() override;

		// Multiply operator
		const point3 operator* (const point_base& _point) const;
		const point3 operator* (int _scalar) const;

		// Sum and substraction operators
		const point3 operator+ (const point_base& _point) const;
		const point3 operator- (const point_base& _point) const;

		// Multiplication operator
		virtual point_base& operator*= (const point_base& _point) override;
		virtual point_base& operator*= (int _scalar) override;

		// Sum/sub and equal operators
		virtual point_base& operator+=(const point_base& _point) override;
		virtual point_base& operator-=(const point_base& _point) override;

		// is Equal operator
		virtual bool operator== (const point_base& _point) override;

		// Stream output operator 
		//friend std::ostream& operator<< (std::ostream& s, const point3& point);
	};
	
}

// N - dimension
namespace graphics {
	class point_dynamic : public point_base {
	private:
		int* data = nullptr;

	public:
		point_dynamic() {}

		point_dynamic(int _size) {
			if (size <= 0 || size >= maxPointSize)
				throw std::exception("Wrong point dimension in constructor");

			size = _size;
			data = new int[size];
		}

		virtual int& operator[](int _index) override;
		virtual int  at(int _index) const override;

		virtual int x() const override;
		virtual int y() const override;
		virtual int z() const override;

		// Copy operators
		virtual point_base& operator= (const point_base& _point) override;

		// Operator scalar multiplying
		virtual point_base& operator*= (int _scalar) override;
	};

	using pointn = point_dynamic;
}