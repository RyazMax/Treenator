#ifndef LIGHT_H
#define LIGHT_H

#include <QColor>

#include "Object/invisibleobject.h"
#include "vec3i.h"

class Light : public InvisibleObject
{
public:
    Light();
    Light(Vec3i<float> pos, Vec3i<float> dir, QColor color);
    Light(const Light &other);
    ~Light() = default;

    Vec3i<float> pos() const;
    Vec3i<float> dir() const;
    QColor color() const;
    double intens() const;

    void set_pos(const Vec3i<float> &pos);
    void set_dir(const Vec3i<float> &dir);
    void set_color(QColor color);
    void set_intens(double val);

    std::shared_ptr<Object3D> copy() override;
private:
    Vec3i<float> _pos;
    Vec3i<float> _dir;
    double _intens;
    QColor _color;
};

#endif // LIGHT_H
