#include "viewerscene.h"
#include "Builder/polygonmodelbuilder.h"

#include "treepolygonbuilder.h"

ViewerScene::ViewerScene()
{
    srand(time(NULL));
    _composite = std::shared_ptr<CompositeObject>(new CompositeObject());
    _cur_camera = std::shared_ptr<Camera>(new Camera(Point3D(0, 0, 1), Point3D(0, 200, -300), Point3D(0, 1, 0)));
    _light = std::shared_ptr<Light>(new Light(Vec3i<float>(0, 0, 1), Vec3i<float>(0, 0, 1), Qt::white));

    std::shared_ptr<Object3D> plane = _create_plane(Point3D(-400, -100, -100), Point3D(400, 0, 700), Qt::white);
    add_obj(plane);

    std::shared_ptr<HondaFunctionSystem> func(new HondaFunctionSystem(0.75, 0.75));
    TreeSkeletonBuilder sk_builder(func, 2);
    /*TreePolygonBuilder builder(sk_builder, Qt::black);
    std::shared_ptr<Object3D> tree = builder.build(std::shared_ptr<TreeSegment>(new TreeSegment({100, 0, 100}, {100, 100, 100}, 7, 6)));
    add_obj(tree);*/
}

void ViewerScene::add_obj(std::shared_ptr<Object3D> obj)
{
    _composite->add_obj(obj);
}

void ViewerScene::set_camera(CompObjIterator iter)
{
    _cur_camera = std::dynamic_pointer_cast<Camera>(*iter);
}

std::shared_ptr<Camera> ViewerScene::get_camera()
{
    return _cur_camera;
}

std::shared_ptr<Light> ViewerScene::get_light()
{
    return _light;
}

std::shared_ptr<Object3D> ViewerScene::get_area()
{
    return _area;
}

void ViewerScene::set_area(std::shared_ptr<Object3D> area)
{
    if (_area != nullptr) {
        _composite->erase(_area_idx);
    }
    _area_idx = _composite->add_obj(area);
    _area = area;
}

CompObjIterator ViewerScene::begin()
{
    return _composite->begin();
}

CompObjIterator ViewerScene::end()
{
    return _composite->end();
}

void ViewerScene::clear()
{
    int count = _composite->count();
    for (size_t i = 1; i < count; ++i) {
        _composite->erase(i);
    }
    _area_idx = _composite->add_obj(_area);
}

std::shared_ptr<Object3D> ViewerScene::_create_plane(Point3D a, Point3D b, QColor color)
{
    double xs[] = {a.get_x(), b.get_x()};
    double ys[] = {a.get_y(), b.get_y()};
    double zs[] = {a.get_z(), b.get_z()};

    PolygonModelBuilder builder;
    builder.build_model();
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                builder.build_vert(xs[i], ys[j], zs[k]);
            }
        }
    }
    // Боковые
    // Левая
    builder.build_polygon(0, 1, 2, color);
    builder.build_polygon(1, 2, 3, color, false);
    // Правая
    builder.build_polygon(4, 5, 6, color);
    builder.build_polygon(5, 6, 7, color);

    // Передняя
    builder.build_polygon(0, 2, 6, color, false);
    builder.build_polygon(0, 4, 6, color);
    // Задняя
    builder.build_polygon(1, 3, 7, color);
    builder.build_polygon(1, 5, 7, color);

    // Нижняя
    builder.build_polygon(0, 1, 4, color, false);
    builder.build_polygon(1, 4, 5, color);
    // Верхняя
    builder.build_polygon(2, 3, 6, color, false);
    builder.build_polygon(3, 6, 7, color);

    return builder.get_model();
}
