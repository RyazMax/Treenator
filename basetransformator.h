#ifndef BASETRANSFORMATOR_H
#define BASETRANSFORMATOR_H

#include <memory>

#include "Object/object3d.h"
#include "basetransformatorimp.h"
#include "transformations.h"

class BaseTransformator
{
public:
    BaseTransformator() = default;
    BaseTransformator(std::shared_ptr<BaseTransformatorImp> imp);
    virtual ~BaseTransformator() = default;

    virtual void exec_transformation(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformation> t) const;
protected:
    std::shared_ptr<BaseTransformatorImp> _imp;
};

#endif // BASETRANSFORMATOR_H
