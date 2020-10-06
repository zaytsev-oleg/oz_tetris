#include "pausebutton.h"

#include <QDebug>
#include <QString>
#include <QMouseEvent>

bool PauseButton::pause() const
{
    return this->m_counter% 2;
}

void PauseButton::slot_toggle_state()
{
    if (!this->isEnabled())
        return;

    emit this->signal_pause_game(this->pause());
    this->m_counter++;

    this->setText(this->pause() ? QString(tr("Pause")) : QString(tr("Continue")));
}

void PauseButton::slot_btn_enabled(bool isEnabled)
{
    this->m_counter = 1;
    this->setText(QString(tr("Pause")));

    this->setEnabled(isEnabled);
}
