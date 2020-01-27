#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "object3d.h"

class InvisibleObject : public Object3D
{
public:
    InvisibleObject();
    InvisibleObject(InvisibleObject &other) = delete;
    InvisibleObject(const InvisibleObject &other) = delete;
    ~InvisibleObject() = default;

    bool is_visible() override {return false;}
};

#endif // INVISIBLEOBJECT_H
