#ifndef QTIMAGEDRAWERIMP_H
#define QTIMAGEDRAWERIMP_H

#include <memory>

#include <QImage>
#include <QLabel>

#include "Drawer/basedrawerimp.h"

class QtImageDrawerImp : public BaseDrawerImp
{
public:
    QtImageDrawerImp(QImage &image, QLabel *canvas);
    explicit QtImageDrawerImp(const QtImageDrawerImp &other);
    ~QtImageDrawerImp() = default;

    void draw_point(int x, int y, QColor color = Qt::black) override;
    void draw_line(int x1, int y1, int x2, int y2) override;

    int width() const override;
    int height() const override;

    void flush() override;
private:
    QImage _image;
    QLabel *_canvas;
};

#endif // QTIMAGEDRAWERIMP_H
