#include "transformations.h"
#include "matrix3.h"

ShiftTransformation::ShiftTransformation(Point3D delta) : _delta(delta)
{}

void ShiftTransformation::transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp)
{
    imp->shift(obj, _delta);
}

ScaleTransformation::ScaleTransformation(Point3D koef, Point3D center) :
    _koef(koef), _center(center)
{}

void ScaleTransformation::transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp)
{
    imp->shift(obj, _center.inverse());
    imp->scale(obj, _koef);
    imp->shift(obj, _center);
}

RotateTransformation::RotateTransformation(Point3D angle, Point3D center) :
    _angle(angle), _center(center)
{
    _angle.set_x(_angle.get_x() / 180 * M_PI);
    _angle.set_y(_angle.get_y() / 180 * M_PI);
    _angle.set_z(_angle.get_z() / 180 * M_PI);
}

void RotateTransformation::transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp)
{
    imp->shift(obj, _center.inverse());
    imp->rotate(obj, _angle);
    imp->shift(obj, _center);
}

ProjectTransformation::ProjectTransformation(double c) : _c(c)
{

}

void ProjectTransformation::transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp)
{
    imp->project(obj, _c);
}

void CompositeTransformation::transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp)
{
    for (auto it = _trs.begin(); it != _trs.end(); ++it) {
        (*it)->transform(obj, imp);
    }
}

void CompositeTransformation::add(std::shared_ptr<BaseTransformation> tr)
{
    _trs.push_back(tr);
}

MatrixTransformation::MatrixTransformation(const Matrix3<float> &m) : _m(m)
{
}

void MatrixTransformation::transform(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformatorImp> imp)
{
    imp->matrix_transform(obj, _m);
}
