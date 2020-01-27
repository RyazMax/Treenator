#ifndef POINT3D_H
#define POINT3D_H

#include <matrix.h>

class Point3D
{
public:
    Point3D(double x, double y, double z);
    ~Point3D() = default;

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

    Point3D& operator=(const Point3D &other);

    Point3D inverse() const;

    Matrix &matrix();
private:
    Matrix _mtrx;
};

#endif // POINT3D_H
