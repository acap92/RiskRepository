#include "gamesetup.h"
#include "ui_gamesetup.h"
#include <string>
#include <iostream>
#include "playerwidget.h"


GameSetup::GameSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSetup)
{
    ui->setupUi(this);
    ui->remove->hide();
    ui->pushButton_2->setDisabled(true);
    QPixmap bg("D:\\FAKULTET\\3. godina\\2. semestar\\Razvoj Softvera\\Project1\\risk\\imgs\\riskStart2.jpeg");
    QPalette p(palette());
    p.setBrush(QPalette::Background, bg);
    setAutoFillBackground(true);
    setPalette(p);

    connect(ui->pushButton_3, SIGNAL(clicked()), parent, SLOT(toStartingWindow()));
//    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT (on_pushButton_2_clicked()));
//    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT (on_pushButton_clicked()));
//    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT (on_lineEdit_textChanged()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT (removePlayer()));
}

GameSetup::~GameSetup()
{
    delete ui;
}

void GameSetup::removePlayer(){
    playSoundEffect();
    m_players.pop_back();
    (*(m_last.rbegin()))->deleteLater();
    m_last.pop_back();
    if(m_players.empty()){
        ui->remove->hide();
    }
    if(m_players.size()<2){
        ui->pushButton_2->setDisabled(true);
    }
}


void GameSetup::on_pushButton_2_clicked()
{
    ui->pushButton_2->setDisabled(true);
    std::cout << "1" << std::endl;
    init(m_players);
    std::cout << "2" << std::endl;
}

void GameSetup::on_pushButton_clicked()
{
    playSoundEffect();
    ui->pushButton->setDisabled(true);
    if(m_players.empty()){
        ui->remove->show();
    }
    if(m_players.size()==1){
        ui->pushButton_2->setDisabled(false);
    }
    std::cout << "3" << std::endl;
    Player *player = new Player(ui->lineEdit->text().toStdString(), "blue");
    m_players.push_back(player);
    PlayerWidget *tmp = new PlayerWidget(this, player);
    m_last.push_back(tmp);
    ui->players->insertWidget(0, tmp);
}

void GameSetup::on_lineEdit_textChanged()
{
    ui->pushButton->setDisabled(false);
}

void GameSetup::playSoundEffect()
{
    QSoundEffect* effect1;
    effect1=new QSoundEffect;
    effect1->setSource(QUrl::fromLocalFile("D:\\FAKULTET\\3. godina\\2. semestar\\Razvoj Softvera\\Project1\\risk\\sounds\\Click1.wav"));
    effect1->setVolume(0.95);
    effect1->play();
}

