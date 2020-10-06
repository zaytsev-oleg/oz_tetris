#ifndef MYFIGURE_H
#define MYFIGURE_H

#include <QColor>
#include <QPainter>
#include <QPoint>

class MyGlass;

class MyFigure
{
public:
    MyFigure(int = 0);
    static const int m_length = 4;

    QPoint top() const;
    QPoint bottom() const;

    int cell_size() const;
    void set_pos(QPoint);
    void set_colors(int = 0);
    void rotate_colors(bool = true);
    void paint_into(QPainter&);
    void save_into(MyGlass&);

    void go_down(int  = 1);
    void go_left(int  = 1);
    void go_right(int = 1);

private:
    QColor m_colors[m_length];

    // координаты первой клетки
    int m_x;
    int m_y;

    int m_size;
};

#endif // MYFIGURE_H
