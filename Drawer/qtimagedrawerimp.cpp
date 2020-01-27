#include "qtimagedrawerimp.h"

QtImageDrawerImp::QtImageDrawerImp(QImage &image, QLabel *canvas) :
    _image(image), _canvas(canvas)
{
}

QtImageDrawerImp::QtImageDrawerImp(const QtImageDrawerImp &other) :
    _image(other._image), _canvas(other._canvas)
{

}

void QtImageDrawerImp::draw_point(int x, int y, QColor color)
{
    if (x > 0 && x < _image.width() && y > 0 && y < _image.height()){
        _image.setPixelColor(x, _image.height() - y, color);
    }
}

void QtImageDrawerImp::draw_line(int x1, int y1, int x2, int y2)
{
    throw std::exception();
}

int QtImageDrawerImp::width() const
{
    return _image.width();
}

int QtImageDrawerImp::height() const
{
    return _image.height();
}

void QtImageDrawerImp::flush()
{
    _canvas->setPixmap(QPixmap::fromImage(_image));
}
