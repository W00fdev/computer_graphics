#pragma once
#include <iostream>

template <typename T>
class MathObject
{
protected:
	template <typename T>
	virtual void Swap(T& a, T& b) {
		T tmp(std::move(a));
		a = std::move(b);
		b = std::move(tmp);
	}

	template <typename T>
	virtual T& operator=(T&& source) {
		T tmp(std::move(src));
		Swap(tmp);
		return *this;
	}



	/*virtual void Swap(T& other) {
		T tmp(std::move(other));
		other = std::move(*this);
		*this = std::move(other);
	}*/
};