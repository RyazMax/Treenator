#include "commands.h"

CompositeCommand::CompositeCommand(std::initializer_list<std::shared_ptr<BaseCommand> > lst)
{
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        _cmds.push_back(*it);
    }
}

void CompositeCommand::execute(Mediator &mediator)
{
    for (auto it = _cmds.begin(); it != _cmds.end(); ++it) {
        (*it)->execute(mediator);
    }
}

void CompositeCommand::add_command(std::shared_ptr<BaseCommand> cmd)
{
    _cmds.push_back(cmd);
}

UploadCommand::UploadCommand(const char *name)
{
    _filename = name;
}

void UploadCommand::execute(Mediator &mediator)
{
    mediator.add_object(mediator.get_upload_manager().load_model(_filename));
}

DrawSceneCommand::DrawSceneCommand(std::shared_ptr<BaseDrawerImp> drawer) : _drawer(drawer)
{

}

void DrawSceneCommand::execute(Mediator &mediator)
{
    mediator.get_draw_manager().draw_scene(mediator.get_viewer_scene(), _drawer);
}

ShiftCommand::ShiftCommand(const Point3D &delta, size_t obj_id) : _delta(delta), _obj_id(obj_id)
{
}

void ShiftCommand::execute(Mediator &mediator)
{
    std::shared_ptr<BaseTransformation> t(new ShiftTransformation(_delta));
    ViewerScene& scene = mediator.get_viewer_scene();
    mediator.get_model_manager().transform(scene.begin() + _obj_id, scene.begin() + _obj_id + 1, t);
}

ScaleCommand::ScaleCommand(const Point3D &koefs, const Point3D &center, size_t obj_id) :
    _koefs(koefs), _center(center), _obj_id(obj_id)
{
}

void ScaleCommand::execute(Mediator &mediator)
{
    std::shared_ptr<BaseTransformation> t(new ScaleTransformation(_koefs, _center));
    ViewerScene& scene = mediator.get_viewer_scene();
    mediator.get_model_manager().transform(scene.begin() + _obj_id, scene.begin() + _obj_id + 1, t);
}

RotateCommand::RotateCommand(const Point3D &angle, const Point3D &center, size_t obj_id) :
    _angle(angle), _center(center), _obj_id(obj_id)
{
}

void RotateCommand::execute(Mediator &mediator)
{
    std::shared_ptr<BaseTransformation> t(new RotateTransformation(_angle, _center));
    ViewerScene& scene = mediator.get_viewer_scene();
    mediator.get_model_manager().transform(scene.begin() + _obj_id, scene.begin() + _obj_id + 1, t);
}

ShiftCameraCommand::ShiftCameraCommand(const Point3D &delta) : _delta(delta)
{

}

void ShiftCameraCommand::execute(Mediator &mediator)
{
    std::shared_ptr<Camera> camera = mediator.get_viewer_scene().get_camera();
    std::shared_ptr<BaseTransformation> t(new ShiftTransformation(_delta));
    mediator.get_model_manager().transform_camera(camera, t);
}

RotateCameraCommand::RotateCameraCommand(const Point3D &angle) : _angle(angle)
{

}

void RotateCameraCommand::execute(Mediator &mediator)
{
    std::shared_ptr<Camera> camera = mediator.get_viewer_scene().get_camera();
    std::shared_ptr<BaseTransformation> t(new RotateTransformation(_angle, camera->point()));
    mediator.get_model_manager().transform_camera(camera, t);
}

ChangeLightCommand::ChangeLightCommand(Vec3i<float> dir, QColor color, double intens) :
    _dir(dir), _color(color), _intens(intens)
{

}

void ChangeLightCommand::execute(Mediator &mediator)
{
    std::shared_ptr<Light> light = mediator.get_viewer_scene().get_light();
    light->set_color(_color);
    light->set_intens(_intens);
    light->set_dir(_dir);
}

DrawAreaCommand::DrawAreaCommand(Vec3i<float> center, float rad) : _center(center), _rad(rad)
{

}

void DrawAreaCommand::execute(Mediator &mediator)
{
    ModelManager m = mediator.get_model_manager();
    m.change_area(mediator.get_viewer_scene(), _center, _rad);
}

GenerateTreeCommand::GenerateTreeCommand(TreeParams tParams, LeafParams lParams, AreaParams aParams) :
    _t(tParams), _l(lParams), _a(aParams)
{

}

void GenerateTreeCommand::execute(Mediator &mediator)
{
    ModelManager m = mediator.get_model_manager();
    m.generate_trees(mediator.get_viewer_scene(), _t, _l, _a);
}

void CleanSceneCommand::execute(Mediator &mediator)
{
    mediator.get_viewer_scene().clear();
}
