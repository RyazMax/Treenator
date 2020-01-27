#ifndef VEC3I_H
#define VEC3I_H

#include <cmath>

#include <QColor>

#include "point3d.h"

template <class T>
class Matrix3;

template <class T>
class Vec3i
{
public:
    Vec3i();
    Vec3i(T x, T y, T z);
    Vec3i(const Vec3i &other);
    Vec3i(const Point3D &p);
    Vec3i(const QColor &color);

    Vec3i &operator=(const Vec3i &other);
    Vec3i operator+(const Vec3i &right) const;
    Vec3i operator-(const Vec3i &right) const;
    Vec3i operator^(const Vec3i &right) const; // Векторное произведение

    Vec3i operator*(float k) const;
    Vec3i operator*(const Matrix3<T> &other) const;
    Vec3i operator&(const Vec3i &right) const;
    T operator*(const Vec3i &right) const; // Скалярное произведение

    Vec3i normalize() const;

    double len() const;

    QColor to_color() const;

    template <class D>
    Vec3i<D> to_vec() const;

    T x() const;
    T y() const;
    T z() const;
private:
    T _x;
    T _y;
    T _z;
};

template <class T>
double Vec3i<T>::len() const {
    return sqrt(_x * _x + _y * _y + _z * _z);
}

template<class T>
Vec3i<T>::Vec3i()
{
    _x = 0;
    _y = 0;
    _z = 0;
}

template <class T>
Vec3i<T>::Vec3i(const QColor &color) : _x(color.red()), _y(color.green()), _z(color.blue()) {

}

template <class T>
template <class D>
Vec3i<D> Vec3i<T>::to_vec() const {
    return Vec3i<D>(_x, _y, _z);
}

template<class T>
Vec3i<T>::Vec3i(T x, T y, T z) : _x(x), _y(y), _z(z)
{

}

template <class T>
Vec3i<T>::Vec3i(const Vec3i &other) : _x(other._x), _y(other._y), _z(other._z)
{

}

template <class T>
QColor Vec3i<T>::to_color() const {
    return QColor(_x, _y, _z);
}

template <class T>
Vec3i<T>::Vec3i(const Point3D &p) : _x(p.get_x()), _y(p.get_y()), _z(p.get_z())
{

}

template <class T>
Vec3i<T> &Vec3i<T>::operator=(const Vec3i &other)
{
    this->_x = other._x;
    this->_y = other._y;
    this->_z = other._z;
    return *this;
}

template <class T>
Vec3i<T> Vec3i<T>::operator+(const Vec3i &right) const
{
    return Vec3i(this->_x + right._x, this->_y + right._y, this->_z + right._z);
}

template <class T>
Vec3i<T> Vec3i<T>::operator-(const Vec3i &right) const
{
    return Vec3i(this->_x - right._x, this->_y - right._y, this->_z - right._z);
}

template <class T>
Vec3i<T> Vec3i<T>::operator^(const Vec3i &right) const
{
    T x = this->_y * right._z - this->_z * right._y;
    T y = this->_z * right._x - this->_x * right._z;
    T z = this->_x * right._y - this->_y * right._x;
    return Vec3i(x, y, z);
}

template <class T>
Vec3i<T> Vec3i<T>::operator&(const Vec3i &right) const
{
    return Vec3i(_x * right._x, _y * right._y, _z * right._z);
}

template <class T>
Vec3i<T> Vec3i<T>::operator*(float k) const
{
    return Vec3i(this->_x * k, this->_y * k, this->_z * k);
}

template <class T>
T Vec3i<T>::operator*(const Vec3i &right) const
{
    return this->_x * right._x + this->_y * right._y + this->_z * right._z;
}

template <class T>
T Vec3i<T>::x() const
{
    return _x;
}

template <class T>
T Vec3i<T>::y() const
{
    return _y;
}

template <class T>
T Vec3i<T>::z() const
{
    return _z;
}

template <class T>
Vec3i<T> Vec3i<T>::operator*(const Matrix3<T> &other) const {
    Matrix3<T> tmp = other.T();
    T x = *this * tmp._x;
    T y = *this * tmp._y;
    T z = *this * tmp._z;
    return Vec3i<T>(x, y, z);
}

template <class T>
Vec3i<T> Vec3i<T>::normalize() const
{
    float length = sqrt(_x * _x + _y * _y + _z * _z);
    return Vec3i(_x / length, _y / length, _z / length);
}

#endif // VEC3I_H
