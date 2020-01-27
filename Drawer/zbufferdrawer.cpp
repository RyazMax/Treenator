#include "zbufferdrawer.h"
#include <cassert>

ZBufferDrawer::ZBufferDrawer(std::shared_ptr<BaseDrawerImp> imp) : BaseDrawer(imp)
{
    _zbuffer = std::vector<int>(_imp->width() * _imp->height());
    _cbuffer = std::vector<QColor>(_imp->width() * _imp->height());
}

void ZBufferDrawer::clean()
{
    for (size_t i = 0; i < _zbuffer.size(); ++i) {
        _zbuffer[i] = 20000;
        _cbuffer[i] = QColor(0, 230, 255);
    }
}

void ZBufferDrawer::draw_object(const std::shared_ptr<PolygonModel> model, std::shared_ptr<Light> light)
{
    Vec3i<float> dir = light->dir().normalize();
    Vec3i<float> light_color(light->color());
    light_color = light_color.normalize();
    float light_intensity = light->intens();

    float diffuse_coef = 0.3;
    for (ModelPolygonIterator it = model->pbegin(); it != model->pend(); ++it) {
        Verticle a = it->first();
        Verticle b = it->second();
        Verticle c = it->third();


        Vec3i<float> n = it->normal();
        if (n.len() == 0) {
            continue;
        }
        n = n.normalize();

        float intensity = -(n * dir) * light_intensity;
        if (intensity < 0) intensity = 0;
        {
            QColor color = it->color();
            Vec3i<float> vcolor(color.red(), color.green(), color.blue());
            vcolor = (light_color & vcolor) * intensity * (1 - diffuse_coef) + vcolor * diffuse_coef;
            assert(vcolor.x() <= 255 && vcolor.y() <= 255 && vcolor.z() <= 255);
            triangle(a.point(), b.point(), c.point(), QColor(vcolor.x(), vcolor.y(), vcolor.z()));
        }
    }
}

void ZBufferDrawer::triangle(Vec3i<int> t0, Vec3i<int> t1, Vec3i<int> t2, QColor color) {
    if (t0.y()==t1.y() && t0.y()==t2.y()) return;
    if (t0.y()>t1.y()) std::swap(t0, t1);
    if (t0.y()>t2.y()) std::swap(t0, t2);
    if (t1.y()>t2.y()) std::swap(t1, t2);

    int total_height = t2.y() - t0.y();


    if (t0.y() > _imp->height() || t2.y() < 0) return;

    for (int i=0; i<total_height; i++) {
        if (t0.y() + i > _imp->height() || t0.y() + i < 0) continue;
        bool second_half = i>t1.y()-t0.y() || t1.y() == t0.y();
        int segment_height = second_half ? t2.y()-t1.y() : t1.y()-t0.y();
        float alpha = (float)i/total_height;
        float beta  = (float)(i-(second_half ? t1.y()-t0.y() : 0))/segment_height; // be careful: with above conditions no division by zero here

        Vec3i<int> A = t0 + (t2-t0)*alpha;
        Vec3i<int> B = second_half ? t1 + (t2-t1)*beta : t0 + (t1-t0)*beta;

        if (A.x()>B.x()) std::swap(A, B);
        for (int j=A.x(); j<=B.x(); j++) {
            if (j < 0 || j > _imp->width()) continue;
            float phi = B.x() == A.x() ? 1. : (float)(j - A.x()) / (float)(B.x() - A.x());
            int z = A.z() + (B.z() - A.z()) * phi;
            int idx = j + (t0.y() + i) * _imp->width();
            assert(idx >= 0);
            if (idx > _zbuffer.size()) continue;
            if (_zbuffer[idx] > z && z >= 0) {
                _zbuffer[idx] = z;
                _cbuffer[idx] = color;
            }
        }
    }
}

void ZBufferDrawer::view_triangle(Vec3i<float> a, Vec3i<float> b, Vec3i<float> c, QColor color)
{
    triangle((a * 100).to_vec<int>(), (b * 100).to_vec<int>(), (c * 100).to_vec<int>(), color);
}

void ZBufferDrawer::flush()
{
    for (size_t i = 0; i < _zbuffer.size(); ++i) {
        if (_zbuffer[i] < 20000) {
            int x = i % _imp->width();
            int y = i / _imp->width();
            _imp->draw_point(x, y, _cbuffer[i]);
        }
    }
    _imp->flush();
    _zbuffer.clear();
    _cbuffer.clear();
}
