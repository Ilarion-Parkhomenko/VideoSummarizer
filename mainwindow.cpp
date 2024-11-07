#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QAudioOutput>
#include <QProcess>
#include <QMessageBox>
#include <QTime>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isMuted(false)
{
    ui->setupUi(this);

    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    audioOutput = new QAudioOutput(this);

    mediaPlayer->setAudioOutput(audioOutput);
    mediaPlayer->setVideoOutput(videoWidget);
    ui->verticalLayout->addWidget(videoWidget);


    timeSlider = new QSlider(Qt::Horizontal, this);
    currentTimeLabel = new QLabel("00:00", this);
    totalTimeLabel = new QLabel("00:00", this);


    currentTimeLabel->setFixedSize(40, 20);
    totalTimeLabel->setFixedSize(40, 20);


    QHBoxLayout *timeLayout = new QHBoxLayout;


    timeLayout->addWidget(currentTimeLabel);


    timeLayout->addWidget(timeSlider);
    timeSlider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred); // Allow the slider to expand


    timeLayout->addWidget(totalTimeLabel);


    ui->verticalLayout->addLayout(timeLayout);

    ui->volumeSlider->setValue(100);


    connect(timeSlider, &QSlider::sliderMoved, this, &MainWindow::on_timeSliderMoved);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);

    connect(ui->rewindButton, &QPushButton::clicked, this, &MainWindow::on_rewindButton_clicked);
    connect(ui->fastForwardButton, &QPushButton::clicked, this, &MainWindow::on_fastForwardButton_clicked);
    connect(ui->addBookmarkButton, &QPushButton::clicked, this, &MainWindow::on_addBookmarkButton_clicked);
    connect(ui->bookmarkList, &QListWidget::itemClicked, this, &MainWindow::on_bookmarkList_itemClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadVideoButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Video"), "", tr("Video Files (*.mp4 *.avi *.mkv)"));
    if (!fileName.isEmpty()) {
        mediaPlayer->setSource(QUrl::fromLocalFile(fileName));
        mediaPlayer->play();
    }
}

void MainWindow::on_playPauseButton_clicked()
{
    if (mediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        mediaPlayer->pause();
    } else {
        mediaPlayer->play();
    }
}

void MainWindow::on_muteButton_clicked()
{
    isMuted = !isMuted;
    audioOutput->setMuted(isMuted);
}

void MainWindow::on_volumeSlider_valueChanged(int value)
{
    audioOutput->setVolume(value / 100.0);
}

void MainWindow::on_timeSliderMoved(int position)
{
    mediaPlayer->setPosition(position);
}

void MainWindow::on_positionChanged(qint64 position)
{
    timeSlider->setValue(position);
    QTime currentTime(0, (position / 60000) % 60, (position / 1000) % 60);
    currentTimeLabel->setText(currentTime.toString("mm:ss"));
}

void MainWindow::on_durationChanged(qint64 duration)
{
    timeSlider->setMaximum(duration);
    QTime totalTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    totalTimeLabel->setText(totalTime.toString("mm:ss"));
}

void MainWindow::on_fastForwardButton_clicked()
{
    mediaPlayer->setPosition(mediaPlayer->position() + 10000);
}

void MainWindow::on_rewindButton_clicked()
{
    mediaPlayer->setPosition(mediaPlayer->position() - 10000);
}

void MainWindow::on_addBookmarkButton_clicked()
{

    ui->addBookmarkButton->setEnabled(false);

    qint64 position = mediaPlayer->position();
    bookmarks.append(position);
    QString bookmarkText = QTime(0, (position / 60000) % 60, (position / 1000) % 60).toString("mm:ss");
    ui->bookmarkList->addItem(bookmarkText);



}


void MainWindow::on_bookmarkList_itemClicked(QListWidgetItem *item)
{
    int index = ui->bookmarkList->row(item);
    mediaPlayer->setPosition(bookmarks[index]);
}
