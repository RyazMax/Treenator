#ifndef POLYGONMODELBUILDER_H
#define POLYGONMODELBUILDER_H

#include "Model/polygionmodel.h"
#include "Builder/basemodelbuilder.h"

class PolygonModelBuilder : public BaseModelBuilder
{
public:
    PolygonModelBuilder();
    virtual ~PolygonModelBuilder() = default;

    virtual void build_model() override;
    void build_polygon(size_t first, size_t second, size_t third, QColor color = Qt::white, bool n_flag = true);

    static std::shared_ptr<VertixModel> build_area(Vec3i<float> center, float rad);

    static std::shared_ptr<PolygonModel> build_leaf(size_t id);
private:
    static std::shared_ptr<PolygonModel> build_square_leaf();
    static std::shared_ptr<PolygonModel> build_triangle_leaf();
};

#endif // POLYGONMODELBUILDER_H
