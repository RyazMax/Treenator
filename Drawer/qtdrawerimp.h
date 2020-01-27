#ifndef QTDRAWERIMP_H
#define QTDRAWERIMP_H

#include <QPainter>

#include <memory>

#include "basedrawerimp.h"

class QtDrawerImp : public BaseDrawerImp
{
public:
    QtDrawerImp(std::shared_ptr<QPainter> painter, int width, int height);
    ~QtDrawerImp() = default;

    virtual void draw_line(int x1, int y1, int x2, int y2) override;
    virtual void draw_point(int x, int y, QColor color) override;

    int width() const override;
    int height() const override;

    void flush() override;
private:
    std::shared_ptr<QPainter> _painter;

    int _width;
    int _height;
};

#endif // QTDRAWERIMP_H
