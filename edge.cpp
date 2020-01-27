#include "edge.h"

Edge::Edge(const ModelVertsIterator &first, const ModelVertsIterator &second) :
    _first(first), _second(second)
{

}

ModelVertsIterator Edge::first()
{
    return _first;
}

ModelVertsIterator Edge::second()
{
    return _second;
}

