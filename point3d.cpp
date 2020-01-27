#include "point3d.h"

Point3D::Point3D(double x, double y, double z) :
    _mtrx({{x, y, z}})
{

}

double Point3D::get_x() const
{
    return _mtrx[0][0];
}

double Point3D::get_y() const
{
    return _mtrx[0][1];
}

double Point3D::get_z() const
{
    return _mtrx[0][2];
}

void Point3D::set_x(double x)
{
    _mtrx[0][0] = x;
}

void Point3D::set_y(double y)
{
    _mtrx[0][1] = y;
}

void Point3D::set_z(double z)
{
    _mtrx[0][2] = z;
}

Point3D &Point3D::operator=(const Point3D &other)
{
    this->set_x(other.get_x());
    this->set_y(other.get_y());
    this->set_z(other.get_z());
    return *this;
}

Point3D Point3D::inverse() const
{
    return Point3D(-_mtrx[0][0], -_mtrx[0][1], -_mtrx[0][2]);
}

Matrix &Point3D::matrix()
{
    return _mtrx;
}

