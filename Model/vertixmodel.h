#ifndef VERTIXMODEL_H
#define VERTIXMODEL_H

#include "Model/modelvertsiterator.h"
#include "Object/visibleobject.h"
#include "verticle.h"

class VertixModel : public VisibleObject
{
public:
    VertixModel();
    VertixModel(VertixModel& other) = delete;
    VertixModel(const VertixModel& other) = delete;
    ~VertixModel() = default;

    size_t add_vert(const Verticle& vert);

    ModelVertsIterator vbegin();
    ModelVertsIterator vbegin() const;
    ModelVertsIterator vend();
    ModelVertsIterator vend() const;
protected:
    std::vector<Verticle> _verts;
};

#endif // VERTIXMODEL_H
