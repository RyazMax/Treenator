#ifndef BASEDRAWERIMP_H
#define BASEDRAWERIMP_H

#include <QColor>

class BaseDrawerImp
{
public:
    BaseDrawerImp() = default;
    virtual ~BaseDrawerImp() = default;

    virtual void draw_point(int x, int y, QColor color = Qt::black) = 0;
    virtual void draw_line(int x1, int y1, int x2, int y2) = 0;

    virtual int width() const = 0;
    virtual int height() const = 0;

    virtual void flush() = 0;
};

#endif // BASEDRAWERIMP_H
