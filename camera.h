#ifndef CAMERA_H
#define CAMERA_H

#include "point3d.h"
#include "Object/invisibleobject.h"

class Camera : public InvisibleObject
{
public:
    Camera(Point3D angle = Point3D(0, 0, 1), Point3D pos = Point3D(0, 0, 0), Point3D up = Point3D(0, 1, 0));
    ~Camera() = default;

    Point3D get_angle3d();
    Point3D point();
    Point3D up();

    void set_angle(Point3D angle);
    void set_point(Point3D point);
    void set_up(const Point3D &point);

    std::shared_ptr<Object3D> copy();
private:
    Point3D _angle;
    Point3D _point;
    Point3D _up;
};

#endif // CAMERA_H
