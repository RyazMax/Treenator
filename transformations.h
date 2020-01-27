#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <cmath>

#include "Object/object3d.h"
#include "matrix3.h"
#include "basetransformatorimp.h"

class BaseTransformation
{
public:
    BaseTransformation() = default;
    virtual ~BaseTransformation() = default;

    virtual void transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp) = 0;
};

class ShiftTransformation : public BaseTransformation
{
public:
    ShiftTransformation(Point3D delta);
    ~ShiftTransformation() = default;

    virtual void transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp) override;
private:
    Point3D _delta;
};

class MatrixTransformation : public BaseTransformation
{
public:
    MatrixTransformation(const Matrix3<float> &m);
    ~MatrixTransformation() = default;

    virtual void transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp) override;
private:
    Matrix3<float> _m;
};

class ScaleTransformation : public BaseTransformation
{
public:
    ScaleTransformation(Point3D koef, Point3D center);
    ~ScaleTransformation() = default;

    virtual void transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp) override;
private:
    Point3D _koef;
    Point3D _center;
};

class RotateTransformation : public BaseTransformation
{
public:
    RotateTransformation(Point3D angle, Point3D center);
    ~RotateTransformation() = default;

    virtual void transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp) override;
private:
    Point3D _angle;
    Point3D _center;
};

class ProjectTransformation : public BaseTransformation
{
public:
    ProjectTransformation(double _c);
    ~ProjectTransformation() = default;

    virtual void transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp) override;
private:
    double _c;
};

class CompositeTransformation  : public BaseTransformation
{
public:
    CompositeTransformation() = default;
    ~CompositeTransformation() = default;

    virtual void transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp) override;
    void add(std::shared_ptr<BaseTransformation> tr);
private:
    std::vector<std::shared_ptr<BaseTransformation>> _trs;
};

#endif // TRANSFORMATIONS_H
