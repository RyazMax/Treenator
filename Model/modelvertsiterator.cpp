#include "modelvertsiterator.h"

ModelVertsIterator::ModelVertsIterator(std::vector<Verticle>& verts, size_t id) :
    _verts(verts), _id(id)
{

}

ModelVertsIterator ModelVertsIterator::operator+(size_t delta)
{
    size_t new_id = _id + delta;
    if (new_id > _verts.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ModelVertsIterator(_verts, new_id);
}

ModelVertsIterator ModelVertsIterator::operator-(size_t delta)
{
    size_t new_id = _id - delta;
    if (new_id > _verts.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ModelVertsIterator(_verts, new_id);
}

Verticle& ModelVertsIterator::operator*()
{
    if (_id >= _verts.size()) {
        throw IteratorException("Iterator out of range");
    }
    return _verts[_id];
}

Verticle* ModelVertsIterator::operator ->()
{
    if (_id >= _verts.size()) {
        throw IteratorException("Iterator out of range");
    }
    return &_verts[_id];
}

const Verticle *ModelVertsIterator::operator ->() const
{
    if (_id >= _verts.size()) {
        throw IteratorException("Iterator out of range");
    }
    return &_verts[_id];
}

ModelVertsIterator &ModelVertsIterator::operator++()
{
    _id++;
    if (_id > _verts.size()) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

ModelVertsIterator &ModelVertsIterator::operator++(int)
{
    ModelVertsIterator ret(_verts, _id);
    _id++;
    if (_id > _verts.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ret;
}

bool ModelVertsIterator::operator==(const ModelVertsIterator &other) const
{
    return _id == other._id;
}

bool ModelVertsIterator::operator!=(const ModelVertsIterator &other) const
{
    return _id != other._id;
}

size_t ModelVertsIterator::id() const
{
    return _id;
}
