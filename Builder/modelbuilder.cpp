#include "modelbuilder.h"

ModelBuilder::ModelBuilder()
{
    _model = std::shared_ptr<WireModel>(nullptr);
}

void ModelBuilder::build_model()
{
    _model = std::shared_ptr<WireModel>(new WireModel());
}

void ModelBuilder::build_edge(size_t first, size_t second)
{
    if (!_model) throw BuilderException("No model to build");
    std::dynamic_pointer_cast<WireModel>(_model)->add_edge(Edge(_model->vbegin() + first, _model->vbegin() + second));
}
