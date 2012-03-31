/********************************************************************************
** Form generated from reading UI file 'gameform.ui'
**
** Created: Fri Mar 30 21:12:24 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFORM_H
#define UI_GAMEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameForm
{
public:
    QPushButton *game_reset;
    QLCDNumber *time_left;
    QLCDNumber *score;

    void setupUi(QWidget *GameForm)
    {
        if (GameForm->objectName().isEmpty())
            GameForm->setObjectName(QString::fromUtf8("GameForm"));
        GameForm->resize(399, 455);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameForm->sizePolicy().hasHeightForWidth());
        GameForm->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        GameForm->setFont(font);
        GameForm->setCursor(QCursor(Qt::ArrowCursor));
        GameForm->setFocusPolicy(Qt::StrongFocus);
        game_reset = new QPushButton(GameForm);
        game_reset->setObjectName(QString::fromUtf8("game_reset"));
        game_reset->setGeometry(QRect(150, 400, 91, 41));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        game_reset->setFont(font1);
        game_reset->setStyleSheet(QString::fromUtf8("QPushButton {    \n"
"    min-height: 1.5em;    \n"
"    font: 1em;   \n"
"    margin: 0 1px 0 1px;   \n"
"    color: white;    \n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #000000, stop: 1 #CCCCCC);\n"
"    \n"
"    border-style: outset;    \n"
"    border-radius: 10px;\n"
"    border-width: 2px;   \n"
"    border-color: #000000;\n"
"}\n"
" \n"
"\n"
"QPushButton:pressed {    \n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #CCCCCC, stop: 1 #000000);\n"
"}"));
        time_left = new QLCDNumber(GameForm);
        time_left->setObjectName(QString::fromUtf8("time_left"));
        time_left->setGeometry(QRect(280, 400, 71, 41));
        score = new QLCDNumber(GameForm);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(40, 400, 71, 41));

        retranslateUi(GameForm);

        QMetaObject::connectSlotsByName(GameForm);
    } // setupUi

    void retranslateUi(QWidget *GameForm)
    {
        GameForm->setWindowTitle(QApplication::translate("GameForm", "Bit-Biter", 0, QApplication::UnicodeUTF8));
        game_reset->setText(QApplication::translate("GameForm", "Restart", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameForm: public Ui_GameForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFORM_H
