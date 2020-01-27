#include "basetransformator.h"

BaseTransformator::BaseTransformator(std::shared_ptr<BaseTransformatorImp> imp) :
    _imp(imp)
{

}

void BaseTransformator::exec_transformation(std::shared_ptr<Object3D> obj, std::shared_ptr<BaseTransformation> t) const
{
    t->transform(obj, _imp);
}
