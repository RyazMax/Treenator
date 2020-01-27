#include "compobjiterator.h"

CompObjIterator::CompObjIterator(std::vector<std::shared_ptr<Object3D> > &objs, size_t id) :
    _objs(objs), _id(id)
{

}

std::shared_ptr<Object3D> CompObjIterator::operator*()
{
    if (_id >= _objs.size()) throw IteratorException("Iterator out of range");
    return _objs[_id];
}

std::shared_ptr<Object3D> CompObjIterator::operator ->()
{
    if (_id >= _objs.size()) throw IteratorException("Iterator out of range");
    return _objs[_id];
}

const std::shared_ptr<Object3D> CompObjIterator::operator->() const
{
    if (_id >= _objs.size()) throw IteratorException("Iterator out of range");
    return _objs[_id];
}

CompObjIterator &CompObjIterator::operator++()
{
    _id++;
    if (_id > _objs.size()) throw IteratorException("Iterator out of range");
    return *this;
}

CompObjIterator CompObjIterator::operator++(int)
{
    CompObjIterator to_ret = *this;
    _id++;
    if (_id > _objs.size()) throw IteratorException("Iterator out of range");;
    return to_ret;
}

bool CompObjIterator::operator==(const CompObjIterator &other) const
{
    return _id == other._id;
}

bool CompObjIterator::operator!=(const CompObjIterator &other) const
{
    return _id != other._id;
}

CompObjIterator CompObjIterator::operator+(size_t delta) const
{
    size_t new_id = _id + delta;
    if (_id > _objs.size()) throw IteratorException("Iterator out of range");;
    return CompObjIterator(_objs, new_id);
}
