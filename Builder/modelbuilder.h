#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "basemodelbuilder.h"

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder();
    ~ModelBuilder() = default;

    virtual void build_model() override;
    void build_edge(size_t first, size_t second);
};

#endif // MODELBUILDER_H
