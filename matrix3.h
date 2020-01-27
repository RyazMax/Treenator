#ifndef MATRIX3_H
#define MATRIX3_H

#include "vec3i.h"

template <class Dtype>
class Matrix3 {
public:
    Matrix3();
    Matrix3(Vec3i<Dtype> x, Vec3i<Dtype> y, Vec3i<Dtype> z);
    Matrix3(const Matrix3& other);
    ~Matrix3() = default;

    Matrix3& operator=(const Matrix3& other);

    Matrix3 operator^(int pow) const;
    Matrix3 operator*(Dtype val) const;

    Vec3i<Dtype>& operator[](size_t i);

    Matrix3 adj() const;
    Matrix3 T() const;
    Dtype det() const;

    friend Vec3i<Dtype> Vec3i<Dtype>::operator*(const Matrix3 &right) const;
private:
    Vec3i<Dtype> _x;
    Vec3i<Dtype> _y;
    Vec3i<Dtype> _z;
};

template <class Dtype>
Matrix3<Dtype>::Matrix3() : _x(0, 0, 0), _y(0, 0, 0), _z(0, 0, 0) {
}

template <class Dtype>
Matrix3<Dtype>::Matrix3(Vec3i<Dtype> x, Vec3i<Dtype> y, Vec3i<Dtype> z) : _x(x), _y(y), _z(z) {
}

template<class Dtype>
Matrix3<Dtype>::Matrix3(const Matrix3 &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

template <class Dtype>
Matrix3<Dtype>& Matrix3<Dtype>::operator=(const Matrix3 &other) {
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
}

template <class Dtype>
Vec3i<Dtype>& Matrix3<Dtype>::operator[](size_t i) {
    switch(i) {
        case 0:
            return _x;
        case 1:
            return _y;
        case 2:
            return _z;
        default:
            throw "Incorrect index";
    }
}

template <class Dtype>
Matrix3<Dtype> Matrix3<Dtype>::operator*(Dtype val) const {
    return Matrix3(_x * val, _y * val, _z * val);
}

template <class Dtype>
Matrix3<Dtype> Matrix3<Dtype>::T() const {
    Vec3i<Dtype> x(_x.x(), _y.x(), _z.x());
    Vec3i<Dtype> y(_x.y(), _y.y(), _z.y());
    Vec3i<Dtype> z(_x.z(), _y.z(), _z.z());
    return Matrix3(x, y, z);
}

template <class Dtype>
Dtype Matrix3<Dtype>::det() const {
    Dtype a = _x.x() * (_y.y() * _z.z() - _y.z() * _z.y());
    Dtype b = -_x.y() * (_y.x() * _z.z() - _y.z() * _z.x());
    Dtype c = _x.z() * (_y.x() * _z.y() - _y.y() * _z.x());
    return a + b + c;
}

template <class Dtype>
Matrix3<Dtype> Matrix3<Dtype>::adj() const {
    Dtype a = (_y.y() * _z.z() - _y.z() * _z.y());
    Dtype b = - (_y.x() * _z.z() - _y.z() * _z.x());
    Dtype c = (_y.x() * _z.y() - _y.y() * _z.x());
    Vec3i<Dtype> x(a, b, c);

    a = -(_x.y() * _z.z() - _x.z() * _z.y());
    b = (_x.x() * _z.z() - _x.z() * _z.x());
    c = -(_x.x() * _z.y() - _x.y() * _z.x());
    Vec3i<Dtype> y(a, b, c);

    a = (_x.y() * _y.z() - _x.z() * _y.y());
    b = -(_x.x() * _y.z() - _x.z() * _y.x());
    c = (_x.x() * _y.y() - _x.y() * _y.x());
    Vec3i<Dtype> z(a, b, c);

    return Matrix3(x, y, z);
}

template <class Dtype>
Matrix3<Dtype> Matrix3<Dtype>::operator^(int pow) const {
    if (pow != -1) throw "Not implemented";
    Dtype det = this->det();
    if (det == 0) throw "Degenerate matrix";

    Matrix3 negative = this->T();
    negative = negative.adj();
    return negative * (1 / det);
}

#endif // MATRIX3_H
