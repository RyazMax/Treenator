#include "wiremodel.h"

WireModel::WireModel()
{

}

void WireModel::add_edge(const Edge& edge)
{
    _edges.push_back(edge);
}

ModelEdgesIterator WireModel::ebegin()
{
    return ModelEdgesIterator(_edges);
}

ModelEdgesIterator WireModel::eend()
{
    return ModelEdgesIterator(_edges, _edges.size());
}

std::shared_ptr<Object3D> WireModel::copy()
{
    std::shared_ptr<WireModel> res = std::shared_ptr<WireModel>(new WireModel());
    for (auto it = this->vbegin(); it != this->vend(); ++it) {
        res->add_vert(*it);
    }

    for (auto it = this->ebegin(); it != this->eend(); ++it) {
        res->add_edge(*it);
    }
    return res;
}
