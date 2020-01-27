#include "basefunctionsystem.h"
#include <QDebug>
#include <iostream>

HondaFunctionSystem::HondaFunctionSystem(double kw, double kh)
 : _kw(kw), _kh(kh)
{

}

segment_arr_t HondaFunctionSystem::transform(std::shared_ptr<TreeSegment> segment) const
{
    segment_arr_t res;
    segment->set_w2(segment->w1() * _kw);

    // Рост вперед
    Vec3i<float> end = segment->end() + segment->delta() * _kh;
    std::shared_ptr<TreeSegment> new_seg(new TreeSegment(segment->end(), end, segment->w2(), segment->is_parent()));
    res.push_back(new_seg);

    // Ответвление для основного ствола
    if (segment->is_parent()) {
        float alpha = get_alpha();
        float omega = (float)rand() / RAND_MAX * 2 * M_PI;

        double r = segment->delta().len() * _kh * _kh;
        end = segment->end() + Vec3i<float>(r * sin(alpha) * cos(omega), r * cos(alpha), r * sin(alpha) * sin(omega));
        std::shared_ptr<TreeSegment> side_seg(new TreeSegment(segment->end(), end, segment->w2() * _kw, false));
        res.push_back(side_seg);
    } else {
        Vec3i<float> y = segment->delta().normalize();
        Vec3i<float> z;
        if (y.z() == 0) {
            z = {0, 0, 1};
        } else {
            z = {1, 0, -y.x() / y.z()};
        }
        z = z.normalize();
        Vec3i<float> x = y ^ z;
        x = x.normalize();

        Matrix3<float> rot(x, y, z);

        float alpha = get_alpha();
        double r = segment->delta().len() * _kh * _kh;
        end = Vec3i<float>(0, r * cos(alpha), r * sin(alpha)) * rot + segment->end();
        std::shared_ptr<TreeSegment> side_seg(new TreeSegment(segment->end(), end, segment->w2() * _kw, false));
        res.push_back(side_seg);
    }
    return res;
}

float HondaFunctionSystem::get_alpha() const
{
    float alpha = (float)rand() / RAND_MAX * M_PI / 4 + M_PI / 8;
    if (rand() & 1) alpha = -alpha;
    return alpha;
}

TernaryFunctionSystem::TernaryFunctionSystem(double kw, double kh) : _kw(kw), _kh(kh)
{

}

segment_arr_t TernaryFunctionSystem::transform(std::shared_ptr<TreeSegment> segment) const
{
    segment_arr_t res;
    segment->set_w2(segment->w1() * _kw);

    // Рост вперед
    Vec3i<float> end = segment->end() + segment->delta() * _kh;
        Vec3i<float> y = segment->delta().normalize();
        Vec3i<float> z;
        if (y.z() == 0) {
            z = {0, 0, 1};
        } else {
            z = {1, 0, -y.x() / y.z()};
        }
        z = z.normalize();
        Vec3i<float> x = y ^ z;
        x = x.normalize();

        Matrix3<float> rot(x, y, z);

        float alpha = get_alpha();
        float omega = (float)rand() / RAND_MAX * 2 * M_PI;
        double r = segment->delta().len() * _kh;
        end = Vec3i<float>(r * sin(omega) * sin(alpha), r * cos(alpha), r * sin(alpha) * cos(omega)) * rot + segment->end();
        std::shared_ptr<TreeSegment> side_seg(new TreeSegment(segment->end(), end, segment->w2(), false));
        res.push_back(side_seg);

        alpha = get_alpha();
        omega = omega = (float)rand() / RAND_MAX * 2 * M_PI;
        end = Vec3i<float>(r * sin(omega) * sin(alpha), r * cos(alpha), r * sin(alpha)* cos(omega)) * rot + segment->end();
        std::shared_ptr<TreeSegment> side_seg2(new TreeSegment(segment->end(), end, segment->w2(), false));
        res.push_back(side_seg2);

        alpha = get_alpha();
        omega = omega = (float)rand() / RAND_MAX * 2 * M_PI;
        end = Vec3i<float>(r * sin(omega) * sin(alpha), r * cos(alpha), r * sin(alpha)* cos(omega)) * rot + segment->end();
        std::shared_ptr<TreeSegment> side_seg3(new TreeSegment(segment->end(), end, segment->w2() * _kw, false));
        res.push_back(side_seg3);

    //}
    return res;
}

float TernaryFunctionSystem::get_alpha() const
{
    float alpha = (float)rand() / RAND_MAX * M_PI / 4 + M_PI / 8;
    if (rand() & 1) alpha = -alpha;
    return alpha;
}
