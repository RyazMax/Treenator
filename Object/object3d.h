#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <memory>

class Object3D
{
public:
    Object3D() = default;
    explicit Object3D(const Object3D &other) = default;
    virtual ~Object3D() = default;
    virtual bool is_visible() = 0;

    virtual std::shared_ptr<Object3D> copy() = 0;
};

#endif // OBJECT3D_H
