#include "treepolygonbuilder.h"
#include "matrix3.h"

TreePolygonBuilder::TreePolygonBuilder(TreeSkeletonBuilder builder, TreeParams t, LeafParams l) : _skelet_builder(builder), _color(t.color),
 _leafColor(l.color), _leafSize(l.size), _cap(t.cap), _leafType(l.leaf_type)
{

}

std::shared_ptr<VertixModel> TreePolygonBuilder::build(std::shared_ptr<TreeSegment> segment)
{
    std::shared_ptr<TreeSkeleton> skeleton = _skelet_builder.build(segment);
    _model_builder.build_model();

    for (auto it = skeleton->begin(); it != skeleton->end(); ++it) {
        proccess_layer(*it);
    }

    int count = round(_cap * skeleton->last()->size());
    for (auto it = skeleton->last()->begin(); it != skeleton->last()->end() && count > 0; ++it, --count) {
        proccess_leaf(*it);
    }

    return _model_builder.get_model();
}

void TreePolygonBuilder::proccess_layer(segment_arr_t &layer)
{
    for (auto it = layer.begin(); it != layer.end(); ++it) {
        proccess_segment(*it);
    }
}

void TreePolygonBuilder::proccess_segment(std::shared_ptr<TreeSegment> segment)
{
    Vec3i<float> p1 = segment->begin();
    Vec3i<float> p2 = segment->end();
    Vec3i<float> delta = segment->delta();
    double len = delta.len();
    double w1 = segment->w1();
    double w2 = segment->w2();


    Vec3i<float> y = delta.normalize();
    Vec3i<float> z;
    if (y.z() == 0) {
        z = {0, 0, 1};
    } else {
        z = {1, 0, -y.x() / y.z()};
    }
    z = z.normalize();
    Vec3i<float> x = y ^ z;
    x = x.normalize();

    Matrix3<float> rot(x, y, z);

    int count = 20;
    double step = 2. * M_PI / count;
    double alpha = 0;


    size_t chigh = _model_builder.build_vert(p1 + Vec3i<float>(0, len, 0) * rot);
    size_t clow = _model_builder.build_vert(p1);


    Vec3i<float> vlow(cos(alpha) * w1, 0, sin(alpha) * w1);
    Vec3i<float> vhigh(cos(alpha) * w2, len, sin(alpha) * w2);
    size_t high = _model_builder.build_vert(p1 + vhigh * rot);
    size_t low = _model_builder.build_vert(p1 + vlow * rot);
    alpha += step;
    for (int i = 0; i < count; ++i) {
        vlow = {cos(alpha) * w1, 0, sin(alpha) * w1};
        vhigh = {cos(alpha) * w2, len, sin(alpha) * w2};
        size_t thigh = _model_builder.build_vert(p1 + vhigh * rot);
        size_t tlow = _model_builder.build_vert(p1 + vlow * rot);

        // Горизонтальные полигоны
        _model_builder.build_polygon(chigh, high, thigh, _color, true);
        _model_builder.build_polygon(clow, low, tlow, _color, true);
        // Вертикальные полигоны
        _model_builder.build_polygon(high, low, tlow, _color, true);
        _model_builder.build_polygon(high, tlow, thigh, _color, true);

        high = thigh;
        low = tlow;
        alpha += step;
    }
}

void TreePolygonBuilder::proccess_leaf(std::shared_ptr<TreeSegment> segment)
{
    Vec3i<float> p1 = segment->begin();
    Vec3i<float> p2 = segment->end();
    Vec3i<float> delta = segment->delta();
    double len = delta.len();

    Vec3i<float> y = delta.normalize();
    Vec3i<float> z;
    if (y.z() == 0) {
        z = {0, 0, 1};
    } else {
        z = {1, 0, -y.x() / y.z()};
    }
    z = z.normalize();
    Vec3i<float> x = y ^ z;
    x = x.normalize();

    Matrix3<float> rot(x, y, z);

    size_t last_num = 0;
    std::shared_ptr<PolygonModel> leaf = PolygonModelBuilder::build_leaf(_leafType);
    for (ModelVertsIterator it = leaf->vbegin(); it != leaf->vend(); ++it) {
        Vec3i<float> p(it->point());
        p =  p * rot * _leafSize + p2;
        size_t tmp = _model_builder.build_vert(p);
        if (last_num == 0) {
            last_num = tmp;
        }
    }

    for (ModelPolygonIterator it = leaf->pbegin(); it != leaf->pend(); ++it) {
        _model_builder.build_polygon(last_num + it->fnum(), last_num + it->snum(), last_num + it->tnum(), _leafColor, it->n_flag());
    }
}
