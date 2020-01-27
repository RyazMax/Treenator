#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "basemanager.h"
#include "basetransformator.h"
#include "basetransformatorimp.h"
#include "Object/compobjiterator.h"

class ObjectManager : public BaseManager
{
public:
    ObjectManager(std::shared_ptr<BaseTransformatorImp> _imp);
    ~ObjectManager() = default;

    virtual void transform(CompObjIterator from, CompObjIterator to, std::shared_ptr<BaseTransformation> t) const = 0;
protected:
    BaseTransformator _transformator;
};

#endif // OBJECTMANAGER_H
