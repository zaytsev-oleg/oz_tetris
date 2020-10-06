#include "myglass.h"
#include "myfigure.h"

#include <QDebug>

#include <ctime>
#include <cstdint>
#include <algorithm>

MyFigure::MyFigure(int size) : m_x(0), m_y(0), m_size(size)
{
    this->set_colors();
}

QPoint MyFigure::top() const
{
    return QPoint(this->m_x, this->m_y);
}

QPoint MyFigure::bottom() const
{
    return QPoint(this->m_x, this->m_y + this->m_length - 1);
}

int MyFigure::cell_size() const
{
    return this->m_size;
}

void MyFigure::set_pos(QPoint qPoint)
{
    this->m_x = qPoint.x();
    this->m_y = qPoint.y();
}

void MyFigure::rotate_colors(bool up)
{
    if (up)
    {
        QColor first = this->m_colors[0];

        for(int i = 0; i < this->m_length - 1; i++)
        {
            this->m_colors[i] = this->m_colors[i+1];
        }

        this->m_colors[this->m_length - 1] = first;
    }
    else
    {
        QColor last = this->m_colors[this->m_length - 1];

        for(int i = this->m_length - 1; i > 0 ; i--)
        {
            this->m_colors[i] = this->m_colors[i - 1];
        }

        this->m_colors[0] = last;
    }
}

void MyFigure::paint_into(QPainter& qPainter)
{
    for(int i = 0; i < this->m_length; i++)
    {
        qPainter.fillRect(
            this->m_x * this->m_size,
            (this->m_y + i) * this->m_size,
            this->m_size - 1,
            this->m_size - 1,
            this->m_colors[i]);
    }
}

void MyFigure::save_into(MyGlass& myGlass)
{
    for (int i = 0; i < this->m_length; i++)
    {
        myGlass.update_matrix(i + this->m_y, this->m_x, this->m_colors[i]);
    }
}

void MyFigure::set_colors(int shift)
{
    QColor colors[] =
    {
        Qt::black,
        Qt::white,
        Qt::red,
        Qt::green,
        Qt::blue,
        Qt::cyan,
        Qt::magenta,
        Qt::yellow
    };

    srand(time(0));
    int n = sizeof(colors) / sizeof(colors[0]);

    for (int i = 0; i < this->m_length; i++)
    {
        this->m_colors[i] = colors[(shift + rand()) % n];
    }
}

void MyFigure::go_down(int i)
{
    this->m_y += i;
}

void MyFigure::go_left(int i)
{
    this->m_x -= i;
}

void MyFigure::go_right(int i)
{
    this->m_x += i;
}
