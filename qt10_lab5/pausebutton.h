#ifndef PAUSEBUTTON_H
#define PAUSEBUTTON_H

#include <QPushButton>

class PauseButton : public QPushButton
{
    Q_OBJECT

    using QPushButton::QPushButton;

signals:
    void signal_pause_game(bool);

private slots:
    void slot_btn_enabled(bool);
    void slot_toggle_state();

private:
    bool pause() const;
    int m_counter{1};
};

#endif // PAUSEBUTTON_H
