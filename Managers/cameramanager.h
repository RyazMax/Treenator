#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "objectmanager.h"
#include "cameratransformatorimp.h"
#include "Object/compobjiterator.h"

class CameraManager : public ObjectManager
{
public:
    CameraManager();
    ~CameraManager() = default;

    virtual void transform(CompObjIterator from, CompObjIterator to, std::shared_ptr<BaseTransformation> t) const override;
};

#endif // CAMERAMANAGER_H
