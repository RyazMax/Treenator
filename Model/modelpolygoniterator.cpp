#include "modelpolygoniterator.h"

ModelPolygonIterator::ModelPolygonIterator(std::vector<Polygon> &polygons, size_t id) : _polygons(polygons), _id(id)
{

}

ModelPolygonIterator ModelPolygonIterator::operator+(size_t delta)
{
    size_t new_id = _id + delta;
    if (new_id > _polygons.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ModelPolygonIterator(_polygons, new_id);
}

ModelPolygonIterator ModelPolygonIterator::operator-(size_t delta)
{
    size_t new_id = _id - delta;
    if (new_id > _polygons.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ModelPolygonIterator(_polygons, new_id);
}

Polygon& ModelPolygonIterator::operator*()
{
    if (_id >= _polygons.size()) {
        throw IteratorException("Iterator out of range");
    }
    return _polygons[_id];
}

Polygon* ModelPolygonIterator::operator ->()
{
    if (_id >= _polygons.size()) {
        throw IteratorException("Iterator out of range");
    }
    return &(_polygons[_id]);
}

ModelPolygonIterator &ModelPolygonIterator::operator++()
{
    _id++;
    if (_id > _polygons.size()) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

ModelPolygonIterator &ModelPolygonIterator::operator++(int)
{
    ModelPolygonIterator ret(_polygons, _id);
    _id++;
    if (_id > _polygons.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ret;
}

bool ModelPolygonIterator::operator==(const ModelPolygonIterator &other) const
{
    return _id == other._id;
}

bool ModelPolygonIterator::operator!=(const ModelPolygonIterator &other) const
{
    return _id != other._id;
}

