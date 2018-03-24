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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainWindowGridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *s_drawGB;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *material;
    QSpacerItem *verticalSpacer;
    QPushButton *generate;
    QCheckBox *m_rotating;
    QSpacerItem *horizontalSpacer_3;
    QSlider *frequency;
    QLabel *label;
    QSlider *amplitude;
    QSlider *seed;
    QLabel *label_3;
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
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer_6, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer_5, 0, 3, 1, 1);

        s_drawGB = new QGroupBox(centralwidget);
        s_drawGB->setObjectName(QStringLiteral("s_drawGB"));
        gridLayout_2 = new QGridLayout(s_drawGB);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(s_drawGB);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 5, 1, 1, 1);

        material = new QPushButton(s_drawGB);
        material->setObjectName(QStringLiteral("material"));

        gridLayout_2->addWidget(material, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 9, 1, 1, 1);

        generate = new QPushButton(s_drawGB);
        generate->setObjectName(QStringLiteral("generate"));

        gridLayout_2->addWidget(generate, 0, 1, 1, 1);

        m_rotating = new QCheckBox(s_drawGB);
        m_rotating->setObjectName(QStringLiteral("m_rotating"));
        m_rotating->setEnabled(true);
        m_rotating->setTristate(false);

        gridLayout_2->addWidget(m_rotating, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        frequency = new QSlider(s_drawGB);
        frequency->setObjectName(QStringLiteral("frequency"));
        frequency->setMaximum(100);
        frequency->setSingleStep(1);
        frequency->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(frequency, 4, 1, 1, 1);

        label = new QLabel(s_drawGB);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 3, 1, 1, 1);

        amplitude = new QSlider(s_drawGB);
        amplitude->setObjectName(QStringLiteral("amplitude"));
        amplitude->setEnabled(true);
        amplitude->setMaximum(100);
        amplitude->setOrientation(Qt::Horizontal);
        amplitude->setInvertedAppearance(false);
        amplitude->setInvertedControls(false);

        gridLayout_2->addWidget(amplitude, 6, 1, 1, 1);

        seed = new QSlider(s_drawGB);
        seed->setObjectName(QStringLiteral("seed"));
        seed->setMinimum(1);
        seed->setMaximum(100);
        seed->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(seed, 8, 1, 1, 1);

        label_3 = new QLabel(s_drawGB);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 7, 1, 1, 1);


        s_mainWindowGridLayout->addWidget(s_drawGB, 2, 5, 1, 1);

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
        label_2->setText(QApplication::translate("MainWindow", "Amplitude", Q_NULLPTR));
        material->setText(QApplication::translate("MainWindow", "Material", Q_NULLPTR));
        generate->setText(QApplication::translate("MainWindow", "Generate", Q_NULLPTR));
        m_rotating->setText(QApplication::translate("MainWindow", "Rotating", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Frequency", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Seed ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
