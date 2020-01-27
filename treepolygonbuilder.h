#ifndef TREEPOLYGONBUILDER_H
#define TREEPOLYGONBUILDER_H

#include "treeskeletonbuilder.h"
#include "Model/polygionmodel.h"
#include "Builder/polygonmodelbuilder.h"
#include "params.h"

class TreePolygonBuilder
{
public:
    TreePolygonBuilder(TreeSkeletonBuilder sk_builder, TreeParams t, LeafParams l);
    ~TreePolygonBuilder() = default;

    std::shared_ptr<VertixModel> build(std::shared_ptr<TreeSegment> segment);
private:
    void proccess_layer(segment_arr_t &layer);
    void proccess_segment(std::shared_ptr<TreeSegment> segment);
    void proccess_leaf(std::shared_ptr<TreeSegment> segment);

    TreeSkeletonBuilder _skelet_builder;
    PolygonModelBuilder _model_builder;
    QColor _color;
    QColor _leafColor;
    double _leafSize;
    double _cap;
    int _leafType;
};

#endif // TREEPOLYGONBUILDER_H
