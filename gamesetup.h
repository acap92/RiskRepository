#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <QWidget>
#include "global.h"
#include <list>
#include "player.h"
#include "playerwidget.h"
#include <QSoundEffect>

namespace Ui {
class GameSetup;
}

class GameSetup : public QWidget
{
    Q_OBJECT

public:
    explicit GameSetup(QWidget *parent = 0);
    ~GameSetup();

    void playSoundEffect();

private slots:
    void removePlayer();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_textChanged();

private:
    Ui::GameSetup *ui;
    std::list<Player*> m_players;
    std::list<PlayerWidget*> m_last;
};

#endif // GAMESETUP_H
