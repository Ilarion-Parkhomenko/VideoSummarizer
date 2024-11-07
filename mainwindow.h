#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSlider>
#include <QLabel>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadVideoButton_clicked();
    void on_playPauseButton_clicked();
    void on_muteButton_clicked();
    void on_volumeSlider_valueChanged(int value);
    void on_timeSliderMoved(int position);
    void on_positionChanged(qint64 position);
    void on_durationChanged(qint64 duration);
    void on_fastForwardButton_clicked();
    void on_rewindButton_clicked();
    void on_addBookmarkButton_clicked();
    void on_bookmarkList_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    QAudioOutput *audioOutput;
    QSlider *timeSlider;
    QLabel *currentTimeLabel;
    QLabel *totalTimeLabel;
    QVector<qint64> bookmarks;
    bool isMuted;
};

#endif // MAINWINDOW_H
