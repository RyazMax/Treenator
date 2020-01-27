#ifndef MODELPOINTSITERATOR_H
#define MODELPOINTSITERATOR_H

#include <memory>
#include <vector>

#include "verticle.h"
#include "Exceptions/iteratorexception.h"

class ModelVertsIterator
{
public:
    ModelVertsIterator(std::vector<Verticle>& verts, size_t id = 0);
    ~ModelVertsIterator() = default;

    Verticle& operator*();
    Verticle* operator ->();

    const Verticle *operator ->() const;

    ModelVertsIterator &operator++();
    ModelVertsIterator &operator++(int);

    bool operator==(const ModelVertsIterator& other) const;
    bool operator!=(const ModelVertsIterator& other) const;

    size_t id() const;

    ModelVertsIterator operator+(size_t delta);
    ModelVertsIterator operator-(size_t delta);
private:
    std::vector<Verticle>& _verts;
    size_t _id;
};

#endif // MODELPOINTSITERATOR_H
