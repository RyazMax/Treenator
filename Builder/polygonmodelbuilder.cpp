#include "polygonmodelbuilder.h"

PolygonModelBuilder::PolygonModelBuilder()
{
    _model = std::shared_ptr<PolygonModel>(nullptr);
}

void PolygonModelBuilder::build_model()
{
    _model = std::shared_ptr<PolygonModel>(new PolygonModel());
}

void PolygonModelBuilder::build_polygon(size_t a, size_t b, size_t c, QColor color, bool n_flag)
{
    if (!_model) throw BuilderException("No model to build");
    std::dynamic_pointer_cast<PolygonModel>(_model)->add_polygon(Polygon(_model->vbegin()+a, _model->vbegin()+b, _model->vbegin()+c, color, n_flag));
}

std::shared_ptr<VertixModel> PolygonModelBuilder::build_area(Vec3i<float> center, float rad)
{
    PolygonModelBuilder builder;
    builder.build_model();
    QColor color = Qt::blue;

    double yhigh = 10, ylow = 0;
    int count = 50;
    double step = 2. * M_PI / count;
    double alpha = 0;


    builder.build_vert(center.x(), yhigh, center.z());
    builder.build_vert(center.x(), ylow, center.z());

    size_t high = builder.build_vert(center.x() + cos(alpha) * rad, yhigh, center.z() + sin(alpha) * rad);
    size_t low = builder.build_vert(center.x() + cos(alpha) * rad, ylow, center.z() + sin(alpha) * rad);
    alpha += step;
    for (int i = 0; i < count; ++i) {
        size_t thigh = builder.build_vert(center.x() + cos(alpha) * rad, yhigh, center.z() + sin(alpha) * rad);
        size_t tlow = builder.build_vert(center.x() + cos(alpha) * rad, ylow, center.z() + sin(alpha) * rad);

        // Горизонтальные полигоны
        builder.build_polygon(0, high, thigh, color, true);
        builder.build_polygon(1, low, tlow, color, true);
        // Вертикальные полигоны
        builder.build_polygon(high, low, tlow, color, true);
        builder.build_polygon(high, tlow, thigh, color, true);

        high = thigh;
        low = tlow;
        alpha += step;
    }
    return builder.get_model();
}

std::shared_ptr<PolygonModel> PolygonModelBuilder::build_leaf(size_t id)
{
    switch(id) {
        case 0:
            return build_square_leaf();
        case 1:
            return build_triangle_leaf();
        default:
            return nullptr;
    }
}

std::shared_ptr<PolygonModel> PolygonModelBuilder::build_square_leaf()
{
    PolygonModelBuilder builder;
    builder.build_model();
    QColor color = Qt::white;

    builder.build_vert({1, 0, 0});
    builder.build_vert({1, 0.5, 0.5});
    builder.build_vert({1, 1, 0});
    builder.build_vert({1, 0.5, -0.5});

    builder.build_vert({-1, 0, 0});
    builder.build_vert({-1, 0.5, 0.5});
    builder.build_vert({-1, 1, 0});
    builder.build_vert({-1, 0.5, -0.5});

    builder.build_polygon(0, 1, 2);
    builder.build_polygon(0, 2, 3);
    builder.build_polygon(4, 5, 6);
    builder.build_polygon(4, 6, 7);

    builder.build_polygon(0, 4, 5);
    builder.build_polygon(0, 5, 1);

    builder.build_polygon(1, 5, 6);
    builder.build_polygon(1, 6, 2);

    builder.build_polygon(2, 6, 7);
    builder.build_polygon(2, 7, 3);

    builder.build_polygon(3, 7, 4);
    builder.build_polygon(3, 4, 0);
    return std::dynamic_pointer_cast<PolygonModel>(builder.get_model());
}

std::shared_ptr<PolygonModel> PolygonModelBuilder::build_triangle_leaf()
{
    PolygonModelBuilder builder;
    builder.build_model();
    QColor color = Qt::white;

    builder.build_vert({0, 1, 0});
    builder.build_vert({1, 0, 1});
    builder.build_vert({1, 0, -1});
    builder.build_vert({-1, 0, -1});
    builder.build_vert({-1, 0, 1});

    builder.build_polygon(0, 2, 1);
    builder.build_polygon(0, 3, 2);
    builder.build_polygon(0, 4, 3);
    builder.build_polygon(0, 1, 4);

    builder.build_polygon(1, 2, 3);
    builder.build_polygon(1, 3, 4);
    return std::dynamic_pointer_cast<PolygonModel>(builder.get_model());
}

