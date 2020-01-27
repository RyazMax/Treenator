#ifndef BASETRANSFORMATORIMP_H
#define BASETRANSFORMATORIMP_H

#include <memory>
#include <cmath>

#include "Object/object3d.h"
#include "point3d.h"
#include "matrix3.h"

class BaseTransformatorImp
{
public:
    BaseTransformatorImp() = default;
    virtual ~BaseTransformatorImp() = default;

    virtual void project(std::shared_ptr<Object3D> obj, double c) const = 0;
    virtual void rotate(std::shared_ptr<Object3D> obj, Point3D angle) const = 0;
    virtual void scale(std::shared_ptr<Object3D> obj, Point3D koefs) const = 0;
    virtual void shift(std::shared_ptr<Object3D> obj, Point3D delta) const = 0;
    virtual void matrix_transform(std::shared_ptr<Object3D> obj, const Matrix3<float>& m) const = 0;
protected:
    void project_point(Point3D &point, double c) const;
    void rotate_point(Point3D &point, Point3D angle) const;
    void scale_point(Point3D &point, Point3D koef) const;
    void shift_point(Point3D &point, Point3D delta) const;
private:
    void rotate_x(Point3D &point, double angle) const;
    void rotate_y(Point3D &point, double angle) const;
    void rotate_z(Point3D &point, double angle) const;
};

#endif // BASETRANSFORMATORIMP_H
