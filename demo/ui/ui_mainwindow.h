/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainWindowGridLayout;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QGroupBox *s_drawGB;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSlider *seed;
    QLabel *label_3;
    QSlider *resolution;
    QSpinBox *terrain;
    QCheckBox *m_rotating;
    QSlider *frequency;
    QLabel *label;
    QSlider *amplitude;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QSlider *range;
    QPushButton *material;
    QLabel *label_6;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QStringLiteral("s_mainWindowGridLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer_6, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer_5, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 1, 5, 1, 1);

        s_drawGB = new QGroupBox(centralwidget);
        s_drawGB->setObjectName(QStringLiteral("s_drawGB"));
        gridLayout_2 = new QGridLayout(s_drawGB);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(s_drawGB);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 15, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 2, 1, 2);

        label_4 = new QLabel(s_drawGB);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 8, 1, 1, 1);

        seed = new QSlider(s_drawGB);
        seed->setObjectName(QStringLiteral("seed"));
        seed->setMinimum(1);
        seed->setMaximum(100);
        seed->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(seed, 7, 1, 1, 1);

        label_3 = new QLabel(s_drawGB);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 6, 1, 1, 1);

        resolution = new QSlider(s_drawGB);
        resolution->setObjectName(QStringLiteral("resolution"));
        resolution->setMinimum(2);
        resolution->setMaximum(60);
        resolution->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(resolution, 9, 1, 1, 1);

        terrain = new QSpinBox(s_drawGB);
        terrain->setObjectName(QStringLiteral("terrain"));
        terrain->setMaximum(4);

        gridLayout_2->addWidget(terrain, 13, 1, 1, 1);

        m_rotating = new QCheckBox(s_drawGB);
        m_rotating->setObjectName(QStringLiteral("m_rotating"));
        m_rotating->setEnabled(true);
        m_rotating->setTristate(false);

        gridLayout_2->addWidget(m_rotating, 1, 1, 1, 1);

        frequency = new QSlider(s_drawGB);
        frequency->setObjectName(QStringLiteral("frequency"));
        frequency->setMaximum(100);
        frequency->setSingleStep(1);
        frequency->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(frequency, 3, 1, 1, 1);

        label = new QLabel(s_drawGB);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 1, 1, 1);

        amplitude = new QSlider(s_drawGB);
        amplitude->setObjectName(QStringLiteral("amplitude"));
        amplitude->setEnabled(true);
        amplitude->setAcceptDrops(false);
        amplitude->setMinimum(-60);
        amplitude->setMaximum(60);
        amplitude->setOrientation(Qt::Horizontal);
        amplitude->setInvertedAppearance(false);
        amplitude->setInvertedControls(false);
        amplitude->setTickPosition(QSlider::TicksAbove);

        gridLayout_2->addWidget(amplitude, 5, 1, 1, 1);

        label_2 = new QLabel(s_drawGB);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 16, 1, 1, 1);

        label_5 = new QLabel(s_drawGB);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 10, 1, 1, 1);

        range = new QSlider(s_drawGB);
        range->setObjectName(QStringLiteral("range"));
        range->setMinimum(2);
        range->setMaximum(60);
        range->setSingleStep(1);
        range->setSliderPosition(60);
        range->setTracking(true);
        range->setOrientation(Qt::Horizontal);
        range->setInvertedAppearance(false);
        range->setInvertedControls(false);

        gridLayout_2->addWidget(range, 11, 1, 1, 1);

        material = new QPushButton(s_drawGB);
        material->setObjectName(QStringLiteral("material"));

        gridLayout_2->addWidget(material, 0, 1, 1, 1);

        label_6 = new QLabel(s_drawGB);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 12, 1, 1, 1);


        s_mainWindowGridLayout->addWidget(s_drawGB, 0, 5, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Terrain", Q_NULLPTR));
        s_drawGB->setTitle(QString());
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Information</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">W : wireframe </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">S : solid </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Terrain 0 : Basic Mountains</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Terrain 1 : Canyons and Caves</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Terrain 2 : Canyons and Caves</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Terrain 3 : Canyon</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Terrain 4 : Islands on Sea</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Resolution", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Seed ", Q_NULLPTR));
        m_rotating->setText(QApplication::translate("MainWindow", "Rotating", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Frequency", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Amplitude             ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Range", Q_NULLPTR));
        material->setText(QApplication::translate("MainWindow", "Material", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Change Type of Terrain (function)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
