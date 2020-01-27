#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H

#include <vector>
#include <memory>

#include "compobjiterator.h"
#include "object3d.h"

class CompositeObject : public Object3D
{
public:
    CompositeObject();
    ~CompositeObject() = default;

    size_t add_obj(std::shared_ptr<Object3D> obj);
    void erase(size_t num);

    size_t count() const;

    virtual bool is_visible() override;

    std::shared_ptr<Object3D> copy() override;

    CompObjIterator begin();
    CompObjIterator begin() const;
    CompObjIterator end();
    CompObjIterator end() const;

private:
    size_t _visible_count;
    size_t _invisible_count;
    std::vector<std::shared_ptr<Object3D>> _objects;
};

#endif // COMPOSITEOBJECT_H
