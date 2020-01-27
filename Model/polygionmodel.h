#ifndef POLYGIONMODEL_H
#define POLYGIONMODEL_H

#include "polygon.h"
#include "Model/vertixmodel.h"
#include "Model/modelpolygoniterator.h"

class PolygonModel : public VertixModel
{
public:
    PolygonModel();
    PolygonModel(PolygonModel& other) = delete;
    PolygonModel(const PolygonModel& other) = delete;
    ~PolygonModel() = default;

    void add_polygon(const Polygon& polygon);

    ModelPolygonIterator pbegin();
    ModelPolygonIterator pbegin() const;
    ModelPolygonIterator pend();
    ModelPolygonIterator pend() const;

    std::shared_ptr<Object3D> copy() override;
private:
    std::vector<Polygon> _polygons;

    size_t _curPolygon;
};

#endif // POLYGIONMODEL_H
