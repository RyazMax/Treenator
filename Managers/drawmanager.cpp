#include "drawmanager.h"

void DrawManager::draw_scene(ViewerScene &scene, std::shared_ptr<BaseDrawerImp> drawer) const
{
    ZBufferDrawer model_drawer(drawer);
    //SimpleObjectDrawer model_drawer(drawer);
    model_drawer.clean();
    std::shared_ptr<Camera> camera = scene.get_camera();
    std::shared_ptr<Light> light = std::dynamic_pointer_cast<Light>(scene.get_light()->copy());
    Vec3i<float> y(camera->up());
    Vec3i<float> z(camera->get_angle3d());
    Vec3i<float> x = y ^ z;
    y = y.normalize();
    z = z.normalize();
    x = x.normalize();

    Matrix3<float> change_matrix(x, y, z);
    change_matrix = change_matrix ^ -1;

    // Смещаем свет
    light->set_dir(light->dir() * change_matrix);
    light->set_pos(light->pos() + Vec3i<float>(camera->point().inverse()));

    BaseTransformator tr(std::shared_ptr<BaseTransformatorImp>(new ModelTransformatorImp));
    std::shared_ptr<CompositeTransformation> prepare(new CompositeTransformation);
    prepare->add(std::shared_ptr<BaseTransformation>(new ScaleTransformation(Point3D(3, 3, 3), Point3D(0, 0, 0))));
    prepare->add(std::shared_ptr<BaseTransformation>(new ShiftTransformation(camera->point().inverse())));
    prepare->add(std::shared_ptr<BaseTransformation>(new MatrixTransformation(change_matrix)));
    prepare->add(std::shared_ptr<BaseTransformation>(new ProjectTransformation(-10500)));
    prepare->add(std::shared_ptr<BaseTransformation>(new ShiftTransformation(Point3D(drawer->width() / 2, drawer->height() / 2, 0))));

    for (auto it = scene.begin(); it != scene.end(); ++it) {
            std::shared_ptr<PolygonModel> m = std::dynamic_pointer_cast<PolygonModel>((*it)->copy());
            tr.exec_transformation(m, prepare);
            model_drawer.draw_object(m, light);
    }
    model_drawer.flush();
}
