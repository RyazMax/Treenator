#ifndef MODELPOLYGONITERATOR_H
#define MODELPOLYGONITERATOR_H

#include "polygon.h"

class ModelPolygonIterator
{
public:
    ModelPolygonIterator(std::vector<Polygon>& polygons, size_t id = 0);
    ~ModelPolygonIterator() = default;

    Polygon& operator*();
    Polygon* operator ->();

    ModelPolygonIterator &operator++();
    ModelPolygonIterator &operator++(int);

    bool operator==(const ModelPolygonIterator& other) const;
    bool operator!=(const ModelPolygonIterator& other) const;

    ModelPolygonIterator operator+(size_t delta);
    ModelPolygonIterator operator-(size_t delta);
private:
    std::vector<Polygon>& _polygons;
    size_t _id;
};

#endif // MODELPOLYGONITERATOR_H
