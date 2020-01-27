#include "qtdrawerimp.h"

QtDrawerImp::QtDrawerImp(std::shared_ptr<QPainter> painter, int width, int height)
    : _painter(painter), _width(width), _height(height)
{

}

void QtDrawerImp::draw_line(int x1, int y1, int x2, int y2)
{
    _painter->drawLine(x1, y1, x2, y2);
}

void QtDrawerImp::draw_point(int x, int y, QColor color)
{
    _painter->setPen(color);
    _painter->drawPoint(x, _height - y);
}

int QtDrawerImp::width() const
{
    return _width;
}

int QtDrawerImp::height() const
{
    return _height;
}

void QtDrawerImp::flush()
{
}
