#ifndef TREESEGMENT_H
#define TREESEGMENT_H

#include "Object/visibleobject.h"
#include "vec3i.h"

class TreeSegment
{
public:
    TreeSegment(Vec3i<float> a, Vec3i<float> b, double w1, bool is_parent = true);
    explicit TreeSegment(const TreeSegment& other) = default;
    ~TreeSegment() = default;

    Vec3i<float> begin() const;
    Vec3i<float> end() const;

    void set_begin(Vec3i<float> b);
    void set_end(Vec3i<float> e);

    double w1() const;
    double w2() const;
    void set_w1(double w);
    void set_w2(double w);

    bool is_parent() const;

    Vec3i<float> delta() const;
private:
    bool _is_parent;
    Vec3i<float> _begin;
    Vec3i<float> _end;

    double _w1;
    double _w2;
};

#endif // TREESEGMENT_H
