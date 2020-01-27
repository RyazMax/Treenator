#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "basemanager.h"
#include "viewerscene.h"
#include "Drawer/basedrawerimp.h"
#include "Drawer/zbufferdrawer.h"
#include "Drawer/modeldrawer.h"
#include "basetransformator.h"
#include "modeltransformatorimp.h"
#include "transformations.h"

#include "treepolygonbuilder.h"

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void draw_scene(ViewerScene &scene, std::shared_ptr<BaseDrawerImp> drawer) const;
};

#endif // DRAWMANAGER_H
