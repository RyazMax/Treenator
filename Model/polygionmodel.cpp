#include "polygionmodel.h"

PolygonModel::PolygonModel()
{

}

void PolygonModel::add_polygon(const Polygon &polygon)
{
    _polygons.push_back(polygon);
}

ModelPolygonIterator PolygonModel::pbegin()
{
    return ModelPolygonIterator(_polygons);
}

ModelPolygonIterator PolygonModel::pend()
{
    return ModelPolygonIterator(_polygons, _polygons.size());
}

std::shared_ptr<Object3D> PolygonModel::copy()
{
    std::shared_ptr<PolygonModel> toret(new PolygonModel);

    for (auto it = _verts.begin(); it != _verts.end(); ++it) {
        toret->add_vert(*it);
    }

    ModelVertsIterator vit = toret->vbegin();
    for (auto it = _polygons.begin(); it != _polygons.end(); ++it) {
        size_t a = it->fnum();
        size_t b = it->snum();
        size_t c = it->tnum();

        toret->add_polygon(Polygon(vit + a, vit + b, vit + c, it->color(), it->n_flag()));
    }

    return toret;
}
