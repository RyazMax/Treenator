#ifndef MODELDRAWER_H
#define MODELDRAWER_H

#include <memory>

#include "basedrawer.h"
#include "basedrawerimp.h"
#include "Model/polygionmodel.h"


class SimpleObjectDrawer : public BaseDrawer
{
public:
    SimpleObjectDrawer(std::shared_ptr<BaseDrawerImp> _imp);
    ~SimpleObjectDrawer() = default;

    void draw_object(std::shared_ptr<PolygonModel> model);
    void flush() override;
    void clean() override;
private:
    void triangle(Point3D a, Point3D b, Point3D c);
};

#endif // MODELDRAWER_H
