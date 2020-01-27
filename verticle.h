#ifndef VERTICLE_H
#define VERTICLE_H

#include "point3d.h"
#include "Object/visibleobject.h"

class Verticle
{
public:
    Verticle(const Point3D& point);
    Verticle(double x, double y, double z);
    Verticle(const Verticle&);
    ~Verticle() = default;

    double get_x() const;
    double get_y() const;
    double get_z() const;
    Point3D point() const;

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);
    void set_point(Point3D);
private:
    Point3D _point;
};

#endif // VERTICLE_H
