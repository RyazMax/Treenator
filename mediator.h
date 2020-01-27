#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Managers/modelmanager.h"
#include "Managers/cameramanager.h"
#include "Managers/drawmanager.h"
#include "Managers/uploadmanager.h"
#include "viewerscene.h"

class Mediator
{
public:
    Mediator() = default;
    ~Mediator() = default;

    void add_object(std::shared_ptr<Object3D> obj);
    void remove_object(CompObjIterator iter);

    ViewerScene &get_viewer_scene();

    const ModelManager &get_model_manager();
    const CameraManager &get_camera_manager();
    const DrawManager &get_draw_manager();
    const UploadManager &get_upload_manager();

private:
    ModelManager _model_manager;
    CameraManager _camera_manager;
    DrawManager _draw_manager;
    UploadManager _upload_manager;

    ViewerScene _scene;
};

#endif // MEDIATOR_H
