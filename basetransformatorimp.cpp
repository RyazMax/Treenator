#include "basetransformatorimp.h"

void BaseTransformatorImp::project_point(Point3D &point, double c) const
{
    double z = point.get_z();
    point.set_x(point.get_x() / (1 - z/c));
    point.set_y(point.get_y() / (1 - z/c));
    point.set_z(z / (1 - z / c));
}

void BaseTransformatorImp::rotate_point(Point3D &point, Point3D angle) const
{
    rotate_x(point, angle.get_x());
    rotate_y(point, angle.get_y());
    rotate_z(point, angle.get_z());
}

void BaseTransformatorImp::scale_point(Point3D &point, Point3D koef) const
{
    point.set_x(koef.get_x() * point.get_x());
    point.set_y(koef.get_y() * point.get_y());
    point.set_z(koef.get_z() * point.get_z());
}

void BaseTransformatorImp::shift_point(Point3D &point, Point3D delta) const
{
    point.matrix() += delta.matrix();
}

void BaseTransformatorImp::rotate_x(Point3D &point, double angle) const
{
    double x = point.get_x(), y = point.get_y(), z = point.get_z();
    point.set_y(y * cos(angle) + z * sin(angle));
    point.set_z(-y * sin(angle) + z * cos(angle));
}

void BaseTransformatorImp::rotate_y(Point3D &point, double angle) const
{
    double x = point.get_x(), y = point.get_y(), z = point.get_z();
    point.set_x(x * cos(angle) - z * sin(angle));
    point.set_z(x * sin(angle) + z * cos(angle));

}

void BaseTransformatorImp::rotate_z(Point3D &point, double angle) const
{
    double x = point.get_x(), y = point.get_y(), z = point.get_z();
    point.set_x(x * cos(angle) + y * sin(angle));
    point.set_y(-x * sin(angle) + y * cos(angle));
}
