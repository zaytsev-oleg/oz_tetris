#include "myglass.h"
#include "myfigure.h"
#include "nextfigure.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

NextFigure::NextFigure(QWidget *parent) : QWidget(parent), m_next(nullptr)
{
    this->connect(this, SIGNAL(signal_init()), SLOT(slot_init()), Qt::QueuedConnection);
    emit this->signal_init();
}

void NextFigure::slot_next_figure(MyFigure* next)
{
    this->m_next = next;
    this->repaint();
}

QSize NextFigure::get_size() const
{
    int w = this->m_cols * MyGlass::cell_size;
    int h = this->m_rows * MyGlass::cell_size;

    return QSize(w, h);
}

void NextFigure::slot_init()
{
    this->setFixedSize(this->get_size());
}

void NextFigure::paintEvent(QPaintEvent *)
{
    int cell_size = MyGlass::cell_size;
    QColor default_color = MyGlass::default_color;

    QPainter qPainter(this);

    for(int i = 0; i < this->m_rows; i++)
    {
        for(int j = 0; j < this->m_cols; j++)
        {
            qPainter.fillRect(
                j * cell_size,
                i * cell_size,
                cell_size - 1,
                cell_size - 1,
                default_color);
        }
    }

    if (this->m_next)
    {
        int f_len = MyFigure::m_length;
        int cell_size = MyGlass::cell_size;

        int dx = (this->m_cols / 2) * cell_size;
        int dy = ((this->m_rows - f_len) / 2) * cell_size;

        QPainter qPainter(this);
        qPainter.translate(dx, dy);

        this->m_next->paint_into(qPainter);
    }
}
