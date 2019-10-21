#include "player.h"
#include <QToolButton>


Player::Player(QWidget *parent) : QWidget(parent)
{
    creatWidgets();
    creatShortcuts();
    creatJumpList();
    creatTaskbar();
    creatThumbnailToolBar();

//    connect(&mediaPlayer, QOverload<QMediaPlayer::Error>::of(QMediaPlayer::error),
//            this, &Player::updateState);
//    connect(&mediaPlayer, &QMediaPlayer::positionChanged, this, &Player::updatePosition);

}

void Player::creatWidgets()
{
    playButton = new QToolButton(this);
    playButton->setEnabled(false);
    playButton->setToolTip(tr("Play"));
    connect(playButton, &QAbstractButton::clicked, this, &Player::togglePlayback);

    QAbstractButton *openButton = new QToolButton(this);
    openButton->setText(tr("..."));
    openButton->setToolTip(tr("Open a file"));
    openButton->setFixedSize(playButton->sizeHint());
    connect(openButton, &QAbstractButton::clicked, this, &Player::openFile);

    positionSlider = new QSlider(Qt::Horizontal, this);
    positionSlider->setEnabled(false);
    positionSlider->setToolTip(tr("Seek"));
//    connect(positionSlider, &QAbstractSlider::valueChanged, this, &Player::setPosition);

}
