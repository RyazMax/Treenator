#include "modeledgesiterator.h"

ModelEdgesIterator::ModelEdgesIterator(std::vector<Edge>& edges, size_t id) :
    _edges(edges), _id(id)
{

}

bool ModelEdgesIterator::operator==(const ModelEdgesIterator &other)
{
    return _id == other._id;
}

bool ModelEdgesIterator::operator !=(const ModelEdgesIterator &other)
{
    return _id != other._id;
}

ModelEdgesIterator &ModelEdgesIterator::operator++()
{
    _id++;
    if (_id > _edges.size()) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

ModelEdgesIterator &ModelEdgesIterator::operator++(int)
{
    ModelEdgesIterator ret(_edges, _id);
    _id++;
    if (_id > _edges.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ret;
}


ModelEdgesIterator ModelEdgesIterator::operator+(size_t delta)
{
    size_t new_id = _id + delta;
    if (new_id > _edges.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ModelEdgesIterator(_edges, new_id);
}

ModelEdgesIterator ModelEdgesIterator::operator-(size_t delta)
{
    size_t new_id = _id - delta;
    if (new_id > _edges.size()) {
        throw IteratorException("Iterator out of range");
    }
    return ModelEdgesIterator(_edges, new_id);
}

Edge& ModelEdgesIterator::operator*()
{
    if (_id >= _edges.size()) {
        throw IteratorException("Iterator out of range");
    }
    return _edges[_id];
}


std::shared_ptr<Edge> ModelEdgesIterator::operator ->()
{
    if (_id >= _edges.size()) {
        throw IteratorException("Iterator out of range");
    }
    return std::shared_ptr<Edge>(&(_edges[_id]));
}

