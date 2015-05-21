#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startingwindow.h"
#include "gamesetup.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stackedWidget(new QStackedWidget)
{

    playMusic();

    StartingWindow *start = new StartingWindow(this);
    GameSetup *setup = new GameSetup(this);

    stackedWidget->insertWidget(0, start);
    stackedWidget->insertWidget(1, setup);

    //connect(start->ui,SIGNAL(clicked()), stackedWidget, SLOT(setCurrentWidget(setup)));

    this->setCentralWidget(stackedWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::goToSetup(){
    playSoundEffect();
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::toStartingWindow(){
    playSoundEffect();
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::playMusic(){
    QMediaPlayer* music;
    music=new QMediaPlayer;
    music->setMedia(QUrl::fromLocalFile("D:\\FAKULTET\\3. godina\\2. semestar\\Razvoj Softvera\\Project1\\risk\\sounds\\mainTheme.wav"));
    music->setVolume(50);
    music->play();
}

void MainWindow::playSoundEffect(){
    QSoundEffect* effect;
    effect=new QSoundEffect;
    effect->setSource(QUrl::fromLocalFile("D:\\FAKULTET\\3. godina\\2. semestar\\Razvoj Softvera\\Project1\\risk\\sounds\\Click.wav"));
    effect->setVolume(0.95);
    effect->play();
}

void MainWindow::exitP(){
    exit(1);
}


//void MainWindow::toFullScreen(){
//    this->s
//}
