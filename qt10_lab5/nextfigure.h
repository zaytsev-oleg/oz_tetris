#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include <QSize>

class MyFigure;

class NextFigure : public QWidget
{
    Q_OBJECT

public:
    explicit NextFigure(QWidget *parent = nullptr);

    Q_PROPERTY(int rows READ rows WRITE set_rows)
    Q_PROPERTY(int cols READ cols WRITE set_cols)

    inline int rows() const
    {
        return m_rows;
    }

    inline void set_rows(int rows)
    {
        m_rows = rows;
    }

    inline int cols() const
    {
        return m_cols;
    }

    inline void set_cols(int cols)
    {
        m_cols = cols;
    }

    QSize get_size() const;

public slots:
    void slot_next_figure(MyFigure*);

signals:
    void signal_init();

private slots:
    void slot_init();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    int m_rows;
    int m_cols;

    MyFigure* m_next;
};

#endif // NEXTFIGURE_H
