#ifndef VECTOR_H
#define VECTOR_H
#include "render.h"

namespace raytracer {

template<typename T>
class Vector2 {
public:
	Vector2() { x = 0; y = 0; }
	Vector2(T xx, T yy):x(xx),y(yy){}
	
	Vector2<T> operator+(const Vector2<T> &v) const {
		return Vector2(x + v.x, y + v.y);
	}
	
	Vector2<T> operator-(const Vector2<T> &v) const {
		return Vector2(x - v.x, y - v.y);
	}
	
	Vector2<T>& operator+=(const Vector2<T> &v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	
	Vector2<T>& operator-=(const Vector2<T> &v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	
	template<typename U>
	Vector2<T> operator*(U s) const {
		return Vector2<T>(x*s, y*s);
	}

	template<typename U>
	Vector2<T>& operator*=(U s) {
		x *= s;
		y *= s;
		return *this;
	}
	template<typename U>
	friend Vector2<T> operator*(U s, const Vector2<T> &v) {
		return Vector2<T>(s*v.x,s*v.y);
	}
	template<typename U>
	Vector2<T> operator/(U s) const {
		CHECK_NE(s, 0);
		float inv = 1.0f / s;
		return Vector2<T>(x*inv, y*inv);
	}
	template<typename U>
	Vector2<T>& operator/=(U s) {
		CHECK_NE(s, 0);
		float inv = 1.0f / s;
		x *= inv;
		y *= inv;
		return *this;
	}

	bool operator==(const Vector<T> &v) const{
		return x == v.x && y == v.y;
	}
	bool operator!=(const Vector<T> &v) const {
		return x != v.x || y != v.y;
	}

	float length() const {
		return std::sqrt(x*x + y*y);
	}

	T x, y;
};




}
#endif
