#ifndef MYGLASS_H
#define MYGLASS_H

#include <QDebug>
#include <QWidget>
#include <QVector>
#include <QColor>
#include <QSize>
#include <QPoint>
#include <QPainter>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QTimerEvent>

class MyFigure;

class MyGlass : public QWidget
{
    Q_OBJECT

    enum struct STATUS { ACTIVE, PAUSED, FINISHED };

public:
    explicit MyGlass(QWidget *parent = nullptr);
    ~MyGlass();

    static const int cell_size      = 20;
    static const int timer_interval = 500;
    static const int min_count      = 3;

    static const QColor default_color;

    Q_PROPERTY(int rows READ rows WRITE set_rows)
    Q_PROPERTY(int cols READ cols WRITE set_cols)

    inline int rows() const
    {
        return this->m_rows;
    }

    inline void set_rows(int rows)
    {
        this->m_rows = rows;
    }

    inline int cols() const
    {
        return this->m_cols;
    }

    inline void set_cols(int cols)
    {
        this->m_cols = cols;
    }

    QSize get_size() const;
    void update_matrix(int, int, QColor);

private:
    // Основные
    int  analyse_matrix();
    int  calculate_hScore(QVector<QPoint>* = nullptr);
    int  calculate_vScore(QVector<QPoint>* = nullptr);
    bool rebuild_matrix();

    // Вспомогательные
    bool has_free_space() const;
    void clear_matrix();
    void clear_matrix(QVector<QPoint>&);
    void set_score(int);
    QPoint entry_pos() const;
    QColor get_pos(int, int) const;
    QColor set_pos(int, int, QColor);
    QColor clear_pos(int, int);
    bool is_valid_pos(QPoint) const;
    bool is_empty_pos(int, int) const;

    // Служебные
    void kill_timer();
    void start_timer();

protected:
    virtual void timerEvent(QTimerEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

signals:
    void signal_init();
    void signal_next_figure(MyFigure*);
    void signal_set_score(int);
    void signal_pause_btn_enabled(bool);
    void signal_game_over(int);

private slots:
    void slot_init();
    void slot_start_game();
    void slot_pause_game(bool);

private:
    int  m_rows;
    int  m_cols;
    STATUS m_status;
    int  m_score;
    int  m_timer;

    MyFigure* m_fig_1;
    MyFigure* m_fig_2;

    QVector<QVector<QColor>> m_matrix;
};

#endif // MYGLASS_H
