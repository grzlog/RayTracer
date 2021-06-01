#ifndef POINT_H
#define POINT_H
#include "render.h"

namespace raytracer {
	
template<typename T>
class Point2 {
public:
	Point2() { x = y = 0; }
	Point2(T xx, T yy) :x(xx), y(yy) {}
	template<typename U>
	explicit Point2(const Point2<U>& p) :x(T(p.x)), y(T(p.y)), z(T(p.z)) {}
	template<typename U>
	explicit operator Vector2<U>() {
		return Vector2<U>(x, y);
	}
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
	Point2<T> operator+(const Point2<T> &p) const {
		return Point2<T>(x + p.x, y + p.y);
	}
	Point2<T>& operator+=(const Point2<T> &p) {
		x += p.x;
		y += p.y;
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
	Vector2<T> operator-(const Point2<T>& p)const {
		return Vector2<T>(x - p.x, y - p.y, z - p.z);
	}

	T operator[](int i) const {
		CHECK(i >= 0 && i <= 1);
		if (i == 0) return x;
		return y;
	}
	T& operator[](int i) {
		CHECK(i >= 0 && i <= 1);
		if (i == 0) return x;
		return y;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point2<T> &p) {
		os <<"Point: x is " << p.x << "; y is " << p.y;
		return os;
	}
	T x, y;
};

template<typename T>
class Point3 {
public:
	Point3() { x = y = z = 0; }
	Point3(T xx, T yy, T zz):x(xx),y(yy),z(zz){}
	template<typename U>
	explicit Point3(const Point3<U>& p):x((T)p.x),y((T)p.y),z((T)p.z) {}
	template<typename U>
	explicit operator Vector3<U>() const {
		return Vector3<U>(x, y, z);
	}

	Point3<T> operator+(const Point3<T>& p)const {
		return Point3<T>(x+p.x,y+p.y,z+p.z);
	}
	Point3<T>& operator+=(const Point3<T>& p) {
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}
	Point3<T> operator+(const Vector3<T>& v)const {
		return Point3<T>(x + v.x, y + v.y, z + v.z);
	}
	Point3<T>& operator+=(const Vector3<T>& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3<T> operator-(const Point3<T>& p)const {
		return Vector3<T>(x - p.x, y - p.y, z - p.z);
	}
	Point3<T>& operator-=(const Vector3<T>& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Point3<T> operator-()const {
		return Point3<T>(-x, -y, -z);
	}
	Point3<T> operator-(const Vector3<T> &v)const {
		return Point3<T>(x - v.x, y - v.y, z - z.v);
	}
	
	template<typename U>
	Point3<T> operator*(U s) const {
		return Point3<T>(x*s, y*s, z*s);
	}
	template<typename U>
	Point3<T>& operator*=(U s)const {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	template<typename U>
	Point3<T> operator/(U s)const {
		CHECK_NE(s, 0);
		float inv = 1.0f / s;
		return Point3<T>(x*s, y*s, z*s);
	}
	template<typename U>
	Point3<T>& operator/=(U s) {
		CHECK_NE(s, 0);
		float inv = 1.0f / s;
		x *= inv;
		y *= inv;
		z *= inv;
		return *this;
	}

	bool operator==(const Point3<T>& p) const{
		return x == p.x&&y == p.y&&z == p.z;
	}
	bool operator!=(const Point3<T>& p) const {
		return x != p.x || y != p.y || z != p.z;
	}

	T operator[](int i) const {
		CHECK(i >= 0 && i <= 2);
		if (i == 0) return x;
		if (i == 1) return y;
		return z;
	}
	T& operator[](int i) {
		CHECK(i >= 0 && i <= 2);
		if (i == 0) return x;
		if (i == 1) return y;
		return z;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point3<T>& p) {
		os << "Point: x is " << p.x << "; y is " << p.y << "; z is "<<p.z;
		return os;
	}
	T x, y, z;
};

typedef Point2<int> Point2i;
typedef Point2<float> Point2f;
typedef Point3<int> Point3i;
typedef Point3<float> Point3f;

}

#endif