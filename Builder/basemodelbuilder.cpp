#include "basemodelbuilder.h"

BaseModelBuilder::BaseModelBuilder()
{
}

size_t BaseModelBuilder::build_vert(double x, double y, double z)
{
    if (!_model) throw BuilderException("No model to build");
    return _model->add_vert(Verticle(x, y, z));
}

size_t BaseModelBuilder::build_vert(const Vec3i<float> &vert)
{
    if (!_model) throw BuilderException("No model to build");
    return _model->add_vert(Verticle(vert.x(), vert.y(), vert.z()));
}

std::shared_ptr<VertixModel> BaseModelBuilder::get_model()
{
    return _model;
}
