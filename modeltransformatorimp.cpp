#include "modeltransformatorimp.h"
#include "vec3i.h"

void ModelTransformatorImp::matrix_transform(std::shared_ptr<Object3D> obj, const Matrix3<float> &m) const
{
    std::shared_ptr<VertixModel> model = std::dynamic_pointer_cast<VertixModel>(obj);
    for (auto it = model->vbegin(); it != model->vend(); ++it) {
        Vec3i<float> v(it->point());
        v = v * m;
        it->set_point(Point3D(v.x(), v.y(), v.z()));
    }
}

void ModelTransformatorImp::project(std::shared_ptr<Object3D> obj, double c) const
{
    std::shared_ptr<VertixModel> model = std::dynamic_pointer_cast<VertixModel>(obj);
    for (auto it = model->vbegin(); it != model->vend(); ++it) {
        project_verticle(*it, c);
    }
}

void ModelTransformatorImp::rotate(std::shared_ptr<Object3D> obj, Point3D angle) const
{
    std::shared_ptr<VertixModel> model = std::dynamic_pointer_cast<VertixModel>(obj);
    for (auto it = model->vbegin(); it != model->vend(); ++it) {
        rotate_verticle(*it, angle);
    }
}

void ModelTransformatorImp::scale(std::shared_ptr<Object3D> obj, Point3D koefs) const
{
    std::shared_ptr<VertixModel> model = std::dynamic_pointer_cast<VertixModel>(obj);
    for (auto it = model->vbegin(); it != model->vend(); ++it) {
        scale_verticle(*it, koefs);
    }
}

void ModelTransformatorImp::shift(std::shared_ptr<Object3D> obj, Point3D delta) const
{
    std::shared_ptr<VertixModel> model = std::dynamic_pointer_cast<VertixModel>(obj);
    for (auto it = model->vbegin(); it != model->vend(); ++it) {
        shift_verticle(*it, delta);
    }
}

void ModelTransformatorImp::project_verticle(Verticle &vert, double c) const
{
    Point3D new_point = vert.point();
    project_point(new_point, c);
    vert.set_point(new_point);
}

void ModelTransformatorImp::rotate_verticle(Verticle &vert, Point3D angle) const
{
    Point3D new_point = vert.point();
    rotate_point(new_point, angle);
    vert.set_point(new_point);
}

void ModelTransformatorImp::scale_verticle(Verticle &vert, Point3D koef) const
{
    Point3D new_point = vert.point();
    scale_point(new_point, koef);
    vert.set_point(new_point);
}

void ModelTransformatorImp::shift_verticle(Verticle &vert, Point3D delta) const
{
    Point3D new_point = vert.point();
    shift_point(new_point, delta);
    vert.set_point(new_point);
}
