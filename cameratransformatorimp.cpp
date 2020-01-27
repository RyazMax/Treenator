#include "cameratransformatorimp.h"

void CameraTransformatorImp::matrix_transform(std::shared_ptr<Object3D> obj, const Matrix3<float> &m) const
{

}

void CameraTransformatorImp::project(std::shared_ptr<Object3D> obj, double c) const
{
    throw "Not implemented";
}

void CameraTransformatorImp::rotate(std::shared_ptr<Object3D> obj, Point3D angle) const
{
    std::shared_ptr<Camera> camera = std::dynamic_pointer_cast<Camera>(obj);
    Vec3i<double> dir(camera->get_angle3d());
    Vec3i<double> up(camera->up());
    Vec3i<double> side = (up ^ dir).normalize();

    Vec3i<double> axis;
    double omega = 0;
    if (angle.get_x() != 0) {
        axis = side;
        omega = angle.get_x();
    } else if (angle.get_y() != 0) {
        axis = up;
        omega = angle.get_y();
    } else if (angle.get_z() != 0) {
        axis = dir;
        omega = angle.get_z();
    }
    double x = axis.x(), y = axis.y(), z = axis.z();
    Vec3i<double> first(cos(omega) + (1 - cos(omega)) * x * x,
                        (1 - cos(omega)) * x * y - sin(omega) * z,
                        (1 - cos(omega)) * x * z + sin(omega) * y);
    Vec3i<double> second((1 - cos(omega)) * y * x + sin(omega) * z,
                         cos(omega) + (1 - cos(omega)) * y * y,
                         (1 - cos(omega)) * y * z - sin(omega)*x);
    Vec3i<double> third((1 - cos(omega)) * z * x - sin(omega) * y,
                        (1 - cos(omega)) * z * y + sin(omega) * x,
                        cos(omega) + (1 - cos(omega)) * z * z);

    Matrix3<double> mat(first, second, third);
    dir = (dir * mat).normalize();
    up = (up * mat).normalize();

    camera->set_angle(Point3D(dir.x(), dir.y(), dir.z()));
    camera->set_up(Point3D(up.x(), up.y(), up.z()));
}

void CameraTransformatorImp::scale(std::shared_ptr<Object3D> obj, Point3D koefs) const
{
    throw "Not implemented";
}

void CameraTransformatorImp::shift(std::shared_ptr<Object3D> obj, Point3D delta) const
{
    std::shared_ptr<Camera> camera = std::dynamic_pointer_cast<Camera>(obj);
    Point3D point = camera->point();
    Vec3i<double> dir(camera->get_angle3d());
    Vec3i<double> up(camera->up());
    up = up.normalize();
    dir = dir.normalize();
    Vec3i<double> side = up ^ dir;
    dir = dir * delta.get_x() + side.normalize() * delta.get_y() + up * delta.get_z();

    shift_point(point, Point3D(dir.x(), dir.y(), dir.z()));
    camera->set_point(point);
}
