#include "treesegment.h"

TreeSegment::TreeSegment(Vec3i<float> begin, Vec3i<float> end, double w1, bool is_parent) :
    _begin(begin), _end(end), _w1(w1), _w2(0), _is_parent(is_parent)
{

}

Vec3i<float> TreeSegment::begin() const
{
    return _begin;
}

Vec3i<float> TreeSegment::end() const
{
    return _end;
}

void TreeSegment::set_begin(Vec3i<float> b)
{
    _begin = b;
}

void TreeSegment::set_end(Vec3i<float> e)
{
    _end = e;
}

void TreeSegment::set_w1(double w)
{
    _w1 = w;
}

void TreeSegment::set_w2(double w)
{
    _w2 = w;
}

bool TreeSegment::is_parent() const
{
    return _is_parent;
}

double TreeSegment::w1() const
{
    return _w1;
}

double TreeSegment::w2() const
{
    return _w2;
}

Vec3i<float> TreeSegment::delta() const
{
    return _end - _begin;
}
