#ifndef VIEWERSCENE_H
#define VIEWERSCENE_H

#include <vector>
#include <QColor>

#include "point3d.h"
#include "Object/compositeobject.h"
#include "Object/compobjiterator.h"
#include "Model/polygionmodel.h"
#include "camera.h"
#include "light.h"

class ViewerScene
{
public:
    ViewerScene();
    ~ViewerScene() = default;

    void add_obj(std::shared_ptr<Object3D> obj);
    void remove_obj(CompObjIterator iter);
    void set_camera(CompObjIterator iter);

    std::shared_ptr<Camera> get_camera();
    std::shared_ptr<Light> get_light();

    std::shared_ptr<Object3D> get_area();
    void set_area(std::shared_ptr<Object3D> area);

    CompObjIterator begin();
    CompObjIterator begin() const;
    CompObjIterator end();
    CompObjIterator end() const;

    void clear();

private:
    std::shared_ptr<CompositeObject> _composite;

    std::shared_ptr<Object3D> _create_plane(Point3D a, Point3D b, QColor color);
    std::shared_ptr<Object3D> _area;
    size_t _area_idx;

    std::shared_ptr<Camera> _cur_camera;

    std::shared_ptr<Light> _light;
};

#endif // VIEWERSCENE_H
