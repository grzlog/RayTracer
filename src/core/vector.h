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
	Vector2<T> operator-() const{
		return Vector2<T>(-x, -y);
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

	T operator[](int i) const {            //c=a[1]
		CHECK(i >= 0 && i <= 1);
		if (i == 0) return x;
		return y;
	}

	T& operator[](int i) {
		CHECK(i >= 0 && i <= 1);
		if (i == 0) return x;
		return y;
	}

	float length() const {
		return std::sqrt(x*x + y*y);
	}

	T x, y;
};

template<typename T>
class Vector3 {
	Vector3() { x = y = z = 0; }
	Vector3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) {}
	
	Vector3<T> operator+(const Vector3<T> &v) const {
		return Vector3<T>(x + v.x, y + v.y, z + v.z);
	}
	Vector3<T>& operator+=(const Vector3<T> &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vector3<T> operator-(const Vector3<T> &v) const{
		return Vector3<T>(x - v.x, y - v.y, z - v.z);
	}
	Vector3<T>& operator-=(const Vector3<T> &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Vector3<T> operator-() const {
		return Vector3<T>(-x, -y, -z);
	}
	
	template<typename U>
	Vector3<T> operator*(U s)const {
		return Vector3<T>(x*s, y*s, z*s);
	}
	template<typename U>
	Vector3<T>& operator*=(U s) {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	template<typename U>
	friend Vector3<T> operator*(U s, const Vector3<T> &v) {
		return Vector3(v.x*s, v.y*s, v.z*s);
	}

	template<typename U>
	Vector3<T> operator/(U s) const{
		CHECK_NE(s, 0);
		float inv = 1.0f / s;
		return Vector3<T>(x*inv, y*inv, z*inv);
	}

	template<typename U>
	Vector3<T>& operator/=(U s) {
		CHECK_NE(s, 0);
		float inv = 1.0f / s;
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}

	bool operator== (const Vector3<T> &v) const {
		return x == v.x && y == v.y && z = v.z;
	}
	bool operator!=(const Vector3<T> &v) const {
		return x != v.x || y != v.y || z != v.z;
	}

	float length() const {
		return std::sqrt(x*x + y*y + z*z);
	}

	T operator[](int i) const{
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

	T x, y, z;
};


}
#endif
