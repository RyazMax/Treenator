#include "compositeobject.h"

CompositeObject::CompositeObject()
{
    _visible_count = 0;
    _invisible_count = 0;
}

void CompositeObject::erase(size_t num)
{
    _objects.erase(_objects.begin() + num);
}

size_t CompositeObject::count() const
{
    return _objects.size();
}

size_t CompositeObject::add_obj(std::shared_ptr<Object3D> obj)
{
    if (obj->is_visible()) {
        _visible_count++;
    } else {
        _invisible_count++;
    }
    _objects.push_back(obj);
    return _objects.size() - 1;
}

bool CompositeObject::is_visible()
{
    return false;
}

std::shared_ptr<Object3D> CompositeObject::copy()
{

}

CompObjIterator CompositeObject::begin()
{
    return CompObjIterator(_objects);
}

CompObjIterator CompositeObject::end()
{
    return CompObjIterator(_objects, _objects.size());
}
