#include "modeldrawer.h"

void SimpleObjectDrawer::flush()
{

}

void SimpleObjectDrawer::clean()
{

}

SimpleObjectDrawer::SimpleObjectDrawer(std::shared_ptr<BaseDrawerImp> _imp) : BaseDrawer(_imp)
{

}

void SimpleObjectDrawer::triangle(Point3D t0, Point3D t1, Point3D t2) {
    if (t0.get_y()==t1.get_y() && t0.get_y()==t2.get_y()) return; // i dont care about degenerate triangles
    if (t0.get_y()>t1.get_y()) std::swap(t0, t1);
    if (t0.get_y()>t2.get_y()) std::swap(t0, t2);
    if (t1.get_y()>t2.get_y()) std::swap(t1, t2);
    int total_height = t2.get_y() - t0.get_y();
    for (int i=0; i<total_height; i++) {
        bool second_half = i>t1.get_y()-t0.get_y() || t1.get_y() == t0.get_y();
        int segment_height = second_half ? t2.get_y()-t1.get_y() : t1.get_y()-t0.get_y();
        float alpha = (float)i/total_height;
        float beta  = (float)(i-(second_half ? t1.get_y()-t0.get_y() : 0))/segment_height; // be careful: with above conditions no division by zero here
        int x = t0.get_x() + (t2.get_x()-t0.get_x())*alpha;
        int y = t0.get_y() + (t2.get_y()-t0.get_y())*alpha;
        int z = t0.get_z() + (t2.get_z()-t0.get_z())*alpha;
        Point3D A(x, y, z);
        if (second_half) {
            x = t1.get_x() + (t2.get_x() - t1.get_x())*beta;
            y = t1.get_y() + (t2.get_y() - t1.get_y())*beta;
            z = t1.get_z() + (t2.get_z() - t1.get_z())*beta;
        } else {
            x = t0.get_x() + (t1.get_x() - t0.get_x())*beta;
            y = t0.get_y() + (t1.get_y() - t0.get_y())*beta;
            z = t0.get_z() + (t1.get_z() - t0.get_z())*beta;
        }
        Point3D B(x, y, z);
        if (A.get_x()>B.get_x()) std::swap(A, B);
        for (int j=A.get_x(); j<=B.get_x(); j++) {
            _imp->draw_point(j, t0.get_y()+i, QColor(255 / (j+1), 255 / (j+1), 255 / (j+1)));
        }
    }
}

void SimpleObjectDrawer::draw_object(std::shared_ptr<PolygonModel> model)
{
    for (ModelPolygonIterator it = model->pbegin(); it != model->pend(); ++it) {
        Verticle a = it->first();
        Verticle b = it->second();
        Verticle c = it->third();
        triangle(a.point(), b.point(), c.point());
    }
}

