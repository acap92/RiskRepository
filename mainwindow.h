#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QSoundEffect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void playMusic();
    void playSoundEffect();
private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
private slots:
    void goToSetup();
    void exitP();
    void toStartingWindow();\
};


#endif // MAINWINDOW_H
