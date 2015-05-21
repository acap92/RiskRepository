#include "playerwidget.h"
#include "ui_playerwidget.h"
#include "gamesetup.h"

PlayerWidget::PlayerWidget(QWidget *parent, Player *player) :
    QWidget(parent),
    ui(new Ui::PlayerWidget),
    m_player(player)
{
//    setPalette(new QPalette::set);
    QPalette p(palette());
    QColor black = Qt::black;
    black.setAlpha(68);
    p.setColor(QPalette::Background,black);
//    p.setColor(QPalette::Background,Qt::transparent);
//    p.setBrush(QPalette::Background, "rgba(0, 0, 0, 68)");
    setAutoFillBackground(true);
    this->setPalette(p);
    ui->setupUi(this);
    ui->color->setText(QString::fromStdString(player->color()));
    ui->name->setText(QString::fromStdString(player->name()));
//    ui->setupUi(this);

//    connect(ui->remove, SIGNAL(clicked()), this, SLOT(on_remove_clicked()));
//    connect(ui->remove, SIGNAL(clicked()), parent, SLOT(removePlayer));

}

PlayerWidget::~PlayerWidget()
{
    delete ui;
}

//void PlayerWidget::on_remove_clicked()
//{
//    this->deleteLater();
//}
