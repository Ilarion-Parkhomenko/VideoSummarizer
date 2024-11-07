/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loadVideoButton;
    QPushButton *muteButton;
    QSlider *volumeSlider;
    QPushButton *playPauseButton;
    QPushButton *rewindButton;
    QPushButton *fastForwardButton;
    QPushButton *addBookmarkButton;
    QListWidget *bookmarkList;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1368, 949);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMaximumSize(QSize(1368, 870));
        loadVideoButton = new QPushButton(centralwidget);
        loadVideoButton->setObjectName("loadVideoButton");
        loadVideoButton->setGeometry(QRect(0, 0, 91, 21));
        muteButton = new QPushButton(centralwidget);
        muteButton->setObjectName("muteButton");
        muteButton->setGeometry(QRect(0, 840, 28, 24));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeHigh));
        muteButton->setIcon(icon);
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(30, 850, 84, 16));
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);
        playPauseButton = new QPushButton(centralwidget);
        playPauseButton->setObjectName("playPauseButton");
        playPauseButton->setGeometry(QRect(620, 840, 28, 24));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        playPauseButton->setIcon(icon1);
        rewindButton = new QPushButton(centralwidget);
        rewindButton->setObjectName("rewindButton");
        rewindButton->setGeometry(QRect(550, 840, 51, 24));
        fastForwardButton = new QPushButton(centralwidget);
        fastForwardButton->setObjectName("fastForwardButton");
        fastForwardButton->setGeometry(QRect(670, 840, 51, 24));
        addBookmarkButton = new QPushButton(centralwidget);
        addBookmarkButton->setObjectName("addBookmarkButton");
        addBookmarkButton->setGeometry(QRect(800, 840, 121, 24));
        bookmarkList = new QListWidget(centralwidget);
        bookmarkList->setObjectName("bookmarkList");
        bookmarkList->setGeometry(QRect(1330, 0, 41, 811));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 20, 1311, 791));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        muteButton->raise();
        volumeSlider->raise();
        playPauseButton->raise();
        loadVideoButton->raise();
        rewindButton->raise();
        fastForwardButton->raise();
        addBookmarkButton->raise();
        verticalLayoutWidget->raise();
        bookmarkList->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1368, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadVideoButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\262\320\270\320\264\320\265\320\276", nullptr));
        muteButton->setText(QString());
        playPauseButton->setText(QString());
        rewindButton->setText(QCoreApplication::translate("MainWindow", "<< 10s", nullptr));
        fastForwardButton->setText(QCoreApplication::translate("MainWindow", "10s >>", nullptr));
        addBookmarkButton->setText(QCoreApplication::translate("MainWindow", "Add Bookmark", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
