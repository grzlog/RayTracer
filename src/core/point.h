#ifndef POINT_H
#define POINT_H
#include "render.h"

namespace raytracer {
	
template<typename T>
class Point2 {
public:
	Point2() { x = y = 0; }
	Point2(T xx, T yy) :x(xx), y(yy) {}
	Vector2<T> operator-(const Point2<T> & p) const {
		return Vector2<T>(x - p.x, y - p.y);
	}
	bool operator==(const Point2<T> &p) const {
		return (x = p.x && y = p.y) ? true : false;
	}
	bool operator!=(const Point2<T> &p) const {
		return (x != p.x || y != p.y) ? true : false;
	}
	
	template<typename U>
	Point2<T> operator*(U s) const{
		return Point2<T>(x*s, y*s);
	}
	template<typename U>
	Point2<T>& operator*=(U s) {
		x *= s;
		y *= s;
		return *this;
	}

	template<typename U>
	Point2<T> operator/(U s) const {
		CHECK_NE(s, 0);
		float inv = 1.0f / s;
		return Point2<T>(x*inv, y*inv);
	}
	template<typename U>
	Point2<T>& operator/=(U s) {
		CHECK_NE(s, 0);
		float inv = 1.0f / s;
		x *=inv;
		y *=inv;
		return *this;
	}

	Point2<T> operator+(const Vector2<T> &v) const{
		return Point2<T>(x + v.x, y + v.y);
	}

	Point2<T>& operator+=(const Vector2<T> &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Point2<T> operator-(const Vector2<T> &v) const {
		return Point2<T>(x - v.x, y - v.y);
	}
	Point2<T>& operator-=(const Vector2<T> &v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	Point2<T> operator-() const {
		return Point2<T>(-x, -y);
	}

	T operator[](int n) const {
		CHECK(n >= 0 && n <= 1);
		if (n == 0) return x;
		return y;
	}
	T& operator[](int i) {
		CHECK(i >= 0 && i <= 1);
		if (i == 0) return x;
		return y;
	}

	Point2<T> operator+(const Point2<T> &p) const {
		return Point2<T>(x + p.x, y + p.y);
	}
	Point2<T>& operator+=(const Point2<T> &p) {
		x += p.x;
		y += p.y;
		return *this;
	}

	T x, y;
};






}

#endif