#include "mediator.h"

void Mediator::add_object(std::shared_ptr<Object3D> obj)
{
    _scene.add_obj(obj);
}

ViewerScene &Mediator::get_viewer_scene()
{
    return _scene;
}

const ModelManager &Mediator::get_model_manager()
{
    return _model_manager;
}

const CameraManager &Mediator::get_camera_manager()
{
    return _camera_manager;
}

const DrawManager &Mediator::get_draw_manager()
{
    return _draw_manager;
}

const UploadManager &Mediator::get_upload_manager()
{
    return _upload_manager;
}
