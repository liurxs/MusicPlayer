#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QAbstractButton>
#include <QSlider>
#include <QLabel>
#include <QPoint>
#include <QString>

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);

public slots:
    void openFile();
    void playUrl(const QUrl& url);
    void togglePlayback();
    void seekForware();
    void seekBackWard();

protected:
    bool event(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void stylize();

private:
    void creatWidgets();
    void creatShortcuts();
    void creatJumpList();
    void creatTaskbar();
    void creatThumbnailToolBar();

    QMediaPlayer mediaPlayer;
    QAbstractButton *playButton = nullptr;
//    VolumeButton *volumeButton = nulllptr;
    QSlider *positionSlider = nullptr;
    QLabel *infoLabel = nullptr;
    QLabel *posotionLabel = nullptr;
    QPoint *offset;
    QString fileName;

};

#endif // PLAYER_H
