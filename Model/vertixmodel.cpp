#include "vertixmodel.h"
VertixModel::VertixModel()
{

}

size_t VertixModel::add_vert(const Verticle& vert)
{
    _verts.push_back(vert);
    return _verts.size() - 1;
}

ModelVertsIterator VertixModel::vbegin()
{
    return ModelVertsIterator(_verts);
}

ModelVertsIterator VertixModel::vend()
{
    return ModelVertsIterator(_verts, _verts.size());
}
