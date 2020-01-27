#include "modelmanager.h"
#include <climits>
#include "Builder/polygonmodelbuilder.h"

ModelManager::ModelManager() :
    ObjectManager(std::shared_ptr<BaseTransformatorImp>(new ModelTransformatorImp())),
    _camera_transformator(std::shared_ptr<BaseTransformatorImp>(new CameraTransformatorImp))
{

}

void ModelManager::transform(CompObjIterator from, CompObjIterator to, std::shared_ptr<BaseTransformation> t) const
{
    for (auto it = from; it != to; ++it) {
        if (it->is_visible())
            _transformator.exec_transformation(*it, t);
    }
}

void ModelManager::transform_camera(std::shared_ptr<Camera> camera, std::shared_ptr<BaseTransformation> t) const
{
    _camera_transformator.exec_transformation(camera, t);
}

void ModelManager::change_area(ViewerScene &scene, Vec3i<float> center, float rad)
{
    scene.set_area(PolygonModelBuilder::build_area(center, rad));
}

void ModelManager::generate_trees(ViewerScene &scene, TreeParams t, LeafParams l, AreaParams a)
{
    std::shared_ptr<BaseFunctionSystem> func;
    switch (t.branch_type) {
    case 0:
        func = std::shared_ptr<BaseFunctionSystem>(new HondaFunctionSystem(0.707, 0.78));
        break;
    case 1:
        func = std::shared_ptr<BaseFunctionSystem>(new TernaryFunctionSystem(0.61, 0.78));
        break;
    }
    TreeSkeletonBuilder sk(func, t.iter_count);
    TreePolygonBuilder pb(sk, t, l);

    for (int i = 0; i < a.count; i++) {
        int rad = rand() % a.rad;
        float alpha = (float)rand() / RAND_MAX * 2 * M_PI;
        Vec3i<float> offset(cos(alpha) * rad, 0, sin(alpha) * rad);
        Vec3i<float> start = a.center + offset;
        Vec3i<float> stop = start + Vec3i<float>(0, t.height, 0);
        scene.add_obj(pb.build(std::shared_ptr<TreeSegment>(new TreeSegment(start, stop, t.width, t.width))));
    }
}
