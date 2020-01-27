#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "objectmanager.h"
#include "Object/compobjiterator.h"
#include "basetransformator.h"
#include "modeltransformatorimp.h"
#include "cameratransformatorimp.h"
#include "transformations.h"
#include "viewerscene.h"
#include "params.h"
#include "treepolygonbuilder.h"

class ModelManager : public ObjectManager
{
public:
    ModelManager();
    ~ModelManager() = default;

    virtual void transform(CompObjIterator from, CompObjIterator to, std::shared_ptr<BaseTransformation> t) const override;
    virtual void transform_camera(std::shared_ptr<Camera> camera, std::shared_ptr<BaseTransformation> t) const;

    void change_area(ViewerScene &scene, Vec3i<float> center, float rad);
    void generate_trees(ViewerScene &scene, TreeParams params, LeafParams, AreaParams);


private:
    BaseTransformator _model_transformator;
    BaseTransformator _camera_transformator;
};

#endif // MODELMANAGER_H
