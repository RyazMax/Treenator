#ifndef CAMERATRANSFORMATORIMP_H
#define CAMERATRANSFORMATORIMP_H

#include "basetransformatorimp.h"
#include "camera.h"
#include "vec3i.h"
#include "matrix3.h"

class CameraTransformatorImp : public BaseTransformatorImp
{
public:
    CameraTransformatorImp() = default;
    ~CameraTransformatorImp() = default;
    virtual void matrix_transform(std::shared_ptr<Object3D> obj, const Matrix3<float> &m) const override;
    virtual void project(std::shared_ptr<Object3D> obj, double c) const override;
    virtual void rotate(std::shared_ptr<Object3D> obj, Point3D angle) const override;
    virtual void scale(std::shared_ptr<Object3D> obj, Point3D koefs) const override;
    virtual void shift(std::shared_ptr<Object3D> obj, Point3D delta) const override;
};

#endif // CAMERATRANSFORMATORIMP_H
