/********************************************************************************
** Form generated from reading UI file 'gameform.ui'
**
** Created: Fri Mar 30 08:05:01 2012
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameForm
{
public:

    void setupUi(QWidget *GameForm)
    {
        if (GameForm->objectName().isEmpty())
            GameForm->setObjectName(QString::fromUtf8("GameForm"));
        GameForm->resize(399, 400);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameForm->sizePolicy().hasHeightForWidth());
        GameForm->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("LLPixel"));
        font.setPointSize(72);
        GameForm->setFont(font);
        GameForm->setCursor(QCursor(Qt::BlankCursor));
        GameForm->setFocusPolicy(Qt::StrongFocus);

        retranslateUi(GameForm);

        QMetaObject::connectSlotsByName(GameForm);
    } // setupUi

    void retranslateUi(QWidget *GameForm)
    {
        GameForm->setWindowTitle(QApplication::translate("GameForm", "Bit-Biter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameForm: public Ui_GameForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFORM_H
