#include "light.h"

Light::Light() : _intens(1)
{

}

Light::Light(Vec3i<float> pos, Vec3i<float> dir, QColor color) : _pos(pos), _dir(dir), _color(color), _intens(1)
{

}

Light::Light(const Light &other) : _pos(other._pos), _dir(other._dir), _color(other._color), _intens(other._intens)
{

}

Vec3i<float> Light::pos() const
{
    return _pos;
}

Vec3i<float> Light::dir() const
{
    return _dir;
}

QColor Light::color() const
{
    return _color;
}

double Light::intens() const
{
    return _intens;
}

void Light::set_pos(const Vec3i<float> &pos)
{
    _pos = pos;
}

void Light::set_dir(const Vec3i<float> &dir)
{
    _dir = dir;
}

void Light::set_color(QColor color)
{
    _color = color;
}

void Light::set_intens(double val)
{
    _intens = val;
}

std::shared_ptr<Object3D> Light::copy()
{
    return std::shared_ptr<Object3D>(new Light(*this));
}
