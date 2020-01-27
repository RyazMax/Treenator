#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "object3d.h"
#include "point3d.h"

class VisibleObject : public Object3D
{
public:
    VisibleObject();
    explicit VisibleObject(const VisibleObject& other) = default;
    ~VisibleObject() = default;

    bool is_visible() override {return true;}
};

#endif // VISIBLEOBJECT_H
