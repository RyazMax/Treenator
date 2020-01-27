#include "polygon.h"

Polygon::Polygon(const ModelVertsIterator &a, const ModelVertsIterator &b, const ModelVertsIterator &c, QColor color, bool n_flag) :
    _a(a), _b(b), _c(c), _color(color), _n_flag(n_flag)
{

}

Polygon::Polygon(const Polygon &other) : _a(other._a), _b(other._b), _c(other._c), _color(other._color), _n_flag(other._n_flag)
{

}

Verticle Polygon::first()
{
    return *_a;
}

Verticle Polygon::second()
{
    return *_b;
}

Verticle Polygon::third()
{
    return *_c;
}

size_t Polygon::fnum() const
{
    return _a.id();
}

size_t Polygon::snum() const
{
    return _b.id();
}

size_t Polygon::tnum() const
{
    return _c.id();
}

bool Polygon::n_flag() const
{
    return _n_flag;
}

QColor Polygon::color() const
{
    return _color;
}

Vec3i<float> Polygon::normal() const
{
    Vec3i<float> first = Vec3i<float>(_c->point()) - Vec3i<float>(_a->point());
    Vec3i<float> second = Vec3i<float>(_b->point()) - Vec3i<float>(_a->point());
    Vec3i<float> n;
    if (_n_flag) {
        n = first ^ second;
    } else {
        n = second ^ first;
    }
    return n;
}
