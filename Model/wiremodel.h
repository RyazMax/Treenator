#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "modelvertsiterator.h"
#include "modeledgesiterator.h"
#include "Model/vertixmodel.h"
#include "verticle.h"
#include "edge.h"

class WireModel : public VertixModel
{
public:
    WireModel();
    WireModel(WireModel& other) = delete;
    WireModel(const WireModel& other) = delete;
    ~WireModel() = default;

    void add_edge(const Edge& edge);

    ModelEdgesIterator ebegin();
    ModelEdgesIterator ebegin() const;
    ModelEdgesIterator eend();
    ModelEdgesIterator eend() const;

    std::shared_ptr<Object3D> copy() override;

private:
    std::vector<Edge> _edges;

    size_t _curEdge;
};

#endif // MODEL_H
