#include "verticle.h"

Verticle::Verticle(const Point3D &point) : _point(point)
{

}

Verticle::Verticle(double x, double y, double z) : _point(x, y, z)
{
}

Verticle::Verticle(const Verticle &other) : _point(other.point())
{
}

double Verticle::get_x() const
{
    return _point.get_x();
}

double Verticle::get_y() const
{
    return _point.get_y();
}

double Verticle::get_z() const
{
    return _point.get_z();
}

Point3D Verticle::point() const
{
    return _point;
}

void Verticle::set_x(double x)
{
    _point.set_x(x);
}

void Verticle::set_y(double y)
{
    _point.set_y(y);
}

void Verticle::set_z(double z)
{
    _point.set_z(z);
}

void Verticle::set_point(Point3D point)
{
    _point = point;
}
