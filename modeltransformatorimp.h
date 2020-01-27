#ifndef MODELTRANSFORMATORIMP_H
#define MODELTRANSFORMATORIMP_H

#include <cmath>

#include "Model/wiremodel.h"
#include "verticle.h"
#include "basetransformatorimp.h"

class ModelTransformatorImp : public BaseTransformatorImp
{
public:
    ModelTransformatorImp() = default;
    ~ModelTransformatorImp() = default;

    virtual void matrix_transform(std::shared_ptr<Object3D> obj, const Matrix3<float>& m) const override;
    virtual void project(std::shared_ptr<Object3D> obj, double c) const override;
    virtual void rotate(std::shared_ptr<Object3D> obj, Point3D angle) const override;
    virtual void scale(std::shared_ptr<Object3D> obj, Point3D koefs) const override;
    virtual void shift(std::shared_ptr<Object3D> obj, Point3D delta) const override;
private:
    void project_verticle(Verticle &vert, double c) const;
    void rotate_verticle(Verticle &vert, Point3D angle) const;
    void scale_verticle(Verticle &vert, Point3D koef) const;
    void shift_verticle(Verticle &vert, Point3D delta) const;
};

#endif // MODELTRANSFORMATORIMP_H
