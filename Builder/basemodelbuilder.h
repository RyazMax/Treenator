#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H

#include <memory>

#include "vec3i.h"
#include "Model/wiremodel.h"
#include "Exceptions/baseexception.h"

class BaseModelBuilder
{
public:
    BaseModelBuilder();
    virtual ~BaseModelBuilder() = default;

    virtual void build_model() = 0;
    size_t build_vert(double x, double y, double z);
    size_t build_vert(const Vec3i<float> &vert);
    std::shared_ptr<VertixModel> get_model();
protected:
    std::shared_ptr<VertixModel> _model;
};

class BuilderException : public BaseException
{
public:
    BuilderException(std::string msg) : BaseException(msg){}
    ~BuilderException() = default;
};

#endif // BASEMODELBUILDER_H
