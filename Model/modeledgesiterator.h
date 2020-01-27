#ifndef MODELEDGESITERATOR_H
#define MODELEDGESITERATOR_H

#include <memory>
#include <vector>

#include "edge.h"
#include "Exceptions/iteratorexception.h"

class ModelEdgesIterator
{
public:
    ModelEdgesIterator(std::vector<Edge>& edges, size_t id = 0);
    ~ModelEdgesIterator() = default;

    Edge& operator*();
    const Edge &operator *() const;
    std::shared_ptr<Edge> operator ->();
    const std::shared_ptr<Edge> operator ->() const;

    bool operator==(const ModelEdgesIterator& other);
    bool operator!=(const ModelEdgesIterator& other);

    ModelEdgesIterator& operator++();
    ModelEdgesIterator& operator++(int);

    ModelEdgesIterator operator+(size_t delta);
    ModelEdgesIterator operator-(size_t delta);
private:
    std::vector<Edge>& _edges;
    size_t _id;
};

#endif // MODELEDGESITERATOR_H
