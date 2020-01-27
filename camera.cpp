#include "camera.h"

Camera::Camera(Point3D angle, Point3D point, Point3D up) : _angle(angle), _point(point), _up(up)
{
}

Point3D Camera::get_angle3d()
{
    return _angle;
}

Point3D Camera::point()
{
    return _point;
}

Point3D Camera::up()
{
    return _up;
}

void Camera::set_angle(Point3D angle)
{
    _angle = angle;
}

void Camera::set_point(Point3D point)
{
    _point = point;
}

void Camera::set_up(const Point3D &point)
{
    _up = point;
}

std::shared_ptr<Object3D> Camera::copy()
{

}
