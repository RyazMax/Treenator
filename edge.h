#ifndef EDGE_H
#define EDGE_H

#include "verticle.h"
#include "Model/modelvertsiterator.h"

class Edge
{
public:
    Edge(const ModelVertsIterator& first, const ModelVertsIterator& second);

    ModelVertsIterator first();
    ModelVertsIterator second();

private:
    ModelVertsIterator _first;
    ModelVertsIterator _second;
};

#endif // EDGE_H
