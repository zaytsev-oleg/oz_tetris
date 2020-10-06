#include "myfigure.h"
#include "myglass.h"

#include "windows.h"

const QColor MyGlass::default_color = Qt::gray;

MyGlass::MyGlass(QWidget *parent) : QWidget(parent),
    m_rows(0), m_cols(0), m_status(STATUS::FINISHED), m_score(0), m_timer(0)
{
    this->m_fig_1 = new MyFigure(this->cell_size);
    this->m_fig_2 = new MyFigure(this->cell_size);

    this->connect(this, SIGNAL(signal_init()), SLOT(slot_init()), Qt::QueuedConnection);
    emit this->signal_init();
}

MyGlass::~MyGlass()
{
    delete this->m_fig_1;
    delete this->m_fig_2;

    this->kill_timer();
}

void MyGlass::slot_init()
{
    this->m_matrix = QVector(this->m_rows, QVector(this->m_cols, this->default_color));
    this->setFixedSize(this->get_size());
}

void MyGlass::slot_start_game()
{
    this->kill_timer();

    this->clear_matrix();

    this->m_fig_1->set_colors();
    this->m_fig_1->set_pos(this->entry_pos());

    this->m_fig_2->set_colors(5);
    this->m_fig_2->set_pos(QPoint(0, 0));

    emit this->signal_next_figure(m_fig_2);

    this->setFocus();

    this->set_score(0);

    this->m_status = STATUS::ACTIVE;
    emit this->signal_pause_btn_enabled(true);

    this->repaint();

    this->start_timer();
}

void MyGlass::slot_pause_game(bool isPaused)
{
    if (isPaused)
    {
        this->kill_timer();
        this->m_status = STATUS::PAUSED;
    }
    else
    {
        this->m_status = STATUS::ACTIVE;
        this->start_timer();
    }

    this->setFocus();
}

void MyGlass::timerEvent(QTimerEvent *)
{
    QPoint p0(this->m_fig_1->bottom());

    if(p0.y() < this->m_rows - 1 && this->is_empty_pos(p0.y() + 1, p0.x()))
    {
        this->m_fig_1->go_down();
        this->repaint();
    }
    else
    {
        this->kill_timer();

        this->m_fig_1->save_into(*this);
        this->repaint(); // посмотреть потом

        int score = this->analyse_matrix();

        if (score)
        {
            this->set_score(this->m_score + score);
        }

        if (this->has_free_space())
        {
            MyFigure* temp = this->m_fig_1;
            this->m_fig_1  = this->m_fig_2;
            this->m_fig_1->set_pos(this->entry_pos());

            this->m_fig_2  = temp;
            this->m_fig_2->set_colors();
            this->m_fig_2->set_pos(QPoint(0, 0));

            this->repaint();
            emit this->signal_next_figure(this->m_fig_2);

            this->start_timer();
        }
        else
        {
            this->m_status = STATUS::FINISHED;

            emit this->signal_pause_btn_enabled(false);
            emit this->signal_game_over(this->m_score);
        }
    }
}

void MyGlass::keyPressEvent(QKeyEvent *event)
{
    if (this->m_status != STATUS::ACTIVE)
    {
        QWidget::keyPressEvent(event);
        return;
    }

    switch(event->key())
    {
        case Qt::Key_Left:
        {
            if (this->is_valid_pos(this->m_fig_1->top() - QPoint(1, 0)))
            {
                this->m_fig_1->go_left();
            }
            break;
        }
        case Qt::Key_Right:
        {
            if (this->is_valid_pos(this->m_fig_1->top() + QPoint(1, 0)))
            {
                this->m_fig_1->go_right();
            }
            break;
        }
        case Qt::Key_Space:
        {
            int i = 0;
            QPoint qPoint(this->m_fig_1->top());

            while(this->is_valid_pos(qPoint += QPoint(0, 1)))
            {
                i++;
            }

            this->m_fig_1->go_down(i);
            break;
        }
        case Qt::Key_Up:
        {
            this->m_fig_1->rotate_colors(true);
            break;
        }
        case Qt::Key_Down:
        {
            this->m_fig_1->rotate_colors(false);
            break;
        }
        default:
            QWidget::keyPressEvent(event);
    }
}

void MyGlass::paintEvent(QPaintEvent *)
{
    QPainter qPainter(this);

    int i = 0;
    int j = 0;

    for(auto& row : this->m_matrix)
    {
        for(auto& qColor : row)
        {
            qPainter.fillRect(
                i * this->cell_size,
                j * this->cell_size,
                this->cell_size - 1,
                this->cell_size - 1,
                qColor);

            i++;
        }

        j++;
        i = 0;
    }

    if (this->m_status == STATUS::ACTIVE || this->m_status == STATUS::PAUSED)
    {
        this->m_fig_1->paint_into(qPainter);
    }
}

int MyGlass::analyse_matrix() // анализируем матрицу
{
    int score = 0;
    bool res  = true;

    while(res)
    {
        QVector<QPoint> vPoints;

        int hScore = this->calculate_hScore(&vPoints);
        int vScore = this->calculate_vScore(&vPoints);

        int tScore = hScore + vScore;

        if (tScore)
        {
            score += tScore;

            this->clear_matrix(vPoints);
            this->rebuild_matrix();
        }
        else
        {
            res = false;
        }
    }

    return score;
}

int MyGlass::calculate_hScore(QVector<QPoint>* items) // подсчёт очков по горизонтали
{
    int score = 0;

    for(int i = 0; i < this->m_rows; i++)
    {
        for(int j = 0; j < this->m_cols;)
        {
            if (this->is_empty_pos(i, j))
            {
                j++;
                continue;
            }

            int k = 1;

            while((j + k) < this->m_cols && this->get_pos(i, j + k) == this->get_pos(i, j))
            {
                k++;
            }

            if (k >= this->min_count)
            {
                Beep(493, 750); // нота SI
                score += k;

                if (items)
                {
                    for(int m = 0; m < k; m++)
                    {
                        items->push_back(QPoint(j + m, i));
                    }
                }
            }

            j += k;
        }
    }

    return score;
}

int MyGlass::calculate_vScore(QVector<QPoint>* items) // подсчёт очков по вертикали
{
    int score = 0;

    for(int i = 0; i < this->m_cols; i++)
    {
        for(int j = 0; j < this->m_rows;)
        {
            if (this->is_empty_pos(j, i))
            {
                j++;
                continue;
            }

            int k = 1;

            while((j + k) < this->m_rows && this->get_pos(j + k, i) == this->get_pos(j, i))
            {
                k++;
            }

            if (k >= this->min_count)
            {
                Beep(493, 750); // нота SI
                score += k;

                if (items)
                {
                     for(int m = 0; m < k; m++)
                    {
                        items->push_back(QPoint(i, j + m));
                    }
                }
            }

            j += k;
        }
    }

    return score;
}

bool MyGlass::rebuild_matrix() // перестроение матрицы
{
    bool res = false;

    for(int i = this->m_rows - 1; i > 0 ; i--)
    {
        for(int j = 0; j < this->m_cols; j++)
        {
            if (!this->is_empty_pos(i, j))
                continue;

            // находим первый непустой квадрат в столбце j
            int k = i - 1;

            while(k >= 0 && this->is_empty_pos(k, j))
            {
                k--;
            }

            // если нашли, то осуществляем перемещение
            if (k + 1)
            {
                int n = 0;

                while(k - n >= 0)
                {
                    this->set_pos(i - n, j, this->get_pos(k - n, j));
                    this->clear_pos(k - n, j);

                    n++;
                }
            }
        }
    }

    return res;
}

QSize MyGlass::get_size() const
{
    int w = this->m_cols * this->cell_size;
    int h = this->m_rows * this->cell_size;

    return QSize(w, h);
}

bool MyGlass::has_free_space() const
{
    QPoint qPoint = this->entry_pos() + QPoint(0, MyFigure::m_length - 1);
    return this->is_empty_pos(qPoint.y(), qPoint.x());
}

void MyGlass::clear_matrix() // сброс матрицы
{
    for(auto& row : this->m_matrix)
    {
        for(auto& cell : row)
        {
            cell = this->default_color;
        }
    }
}

void MyGlass::clear_matrix(QVector<QPoint>& vPoints) // сброс массива точек
{
    for(auto& p : vPoints)
    {
        this->clear_pos(p.y(), p.x());
    }
}

void MyGlass::set_score(int score)
{
    emit this->signal_set_score(this->m_score = score);
}

QPoint MyGlass::entry_pos() const
{
    return QPoint(this->m_cols / 2, 0);
}

QColor MyGlass::get_pos(int row, int col) const
{
    return this->m_matrix[row][col];
}

QColor MyGlass::set_pos(int row, int col, QColor color)
{
    QColor res = this->get_pos(row, col);
    this->m_matrix[row][col] = color;

    return res;
}

void MyGlass::update_matrix(int row, int col, QColor color)
{
    this->set_pos(row, col, color);
}

QColor MyGlass::clear_pos(int row, int col)
{
    return this->set_pos(row, col, this->default_color);
}

bool MyGlass::is_valid_pos(QPoint pos) const
{
    int len = MyFigure::m_length;
    bool is_valid = pos.x() >= 0 && pos.x() < this->m_cols && (pos.y() + len - 1) < this->m_rows;

    for (int i = 0; is_valid && i < len; i++)
    {
        is_valid = this->is_empty_pos(pos.y() + i, pos.x());
    }

    return is_valid;
}

bool MyGlass::is_empty_pos(int row, int col) const
{
    return this->get_pos(row, col) == this->default_color;
}

void MyGlass::start_timer()
{
    this->m_timer = this->startTimer(this->timer_interval);
}

void MyGlass::kill_timer()
{
    if (this->m_timer)
    {
        this->killTimer(this->m_timer);
        this->m_timer = 0;
    }
}
