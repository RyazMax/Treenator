#ifndef ZBUFFERDRAWER_H
#define ZBUFFERDRAWER_H

#include "Drawer/modeldrawer.h"
#include "light.h"
#include "vec3i.h"

class ZBufferDrawer : BaseDrawer
{
public:
    ZBufferDrawer(std::shared_ptr<BaseDrawerImp> _imp = nullptr);
    ~ZBufferDrawer() = default;

    void draw_object(const std::shared_ptr<PolygonModel> model, std::shared_ptr<Light> light);

    void set_imp(std::shared_ptr<BaseDrawerImp> imp);
    void flush() override;
    void clean() override;
private:
    void triangle(Vec3i<int> a, Vec3i<int> b, Vec3i<int> c, QColor color);
    void view_triangle(Vec3i<float> a, Vec3i<float> b, Vec3i<float> c, QColor color);

    std::vector<int> _zbuffer;
    std::vector<QColor> _cbuffer;
};

#endif // ZBUFFERDRAWER_H
