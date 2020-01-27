#include "cameramanager.h"

CameraManager::CameraManager() : ObjectManager(std::shared_ptr<BaseTransformatorImp>(new CameraTransformatorImp()))
{

}

void CameraManager::transform(CompObjIterator from, CompObjIterator to, std::shared_ptr<BaseTransformation> t) const
{
    for (auto it = from; it != to; ++it) {
        if (!it->is_visible())
            _transformator.exec_transformation(*it, t);
    }
}
