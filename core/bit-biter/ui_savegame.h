/********************************************************************************
** Form generated from reading UI file 'savegame.ui'
**
** Created: Sun Apr 1 17:49:57 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEGAME_H
#define UI_SAVEGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SaveGame
{
public:
    QPushButton *save_yes;
    QPushButton *save_no;
    QLabel *label;

    void setupUi(QDialog *SaveGame)
    {
        if (SaveGame->objectName().isEmpty())
            SaveGame->setObjectName(QString::fromUtf8("SaveGame"));
        SaveGame->resize(400, 114);
        save_yes = new QPushButton(SaveGame);
        save_yes->setObjectName(QString::fromUtf8("save_yes"));
        save_yes->setGeometry(QRect(80, 70, 93, 28));
        save_no = new QPushButton(SaveGame);
        save_no->setObjectName(QString::fromUtf8("save_no"));
        save_no->setGeometry(QRect(210, 70, 93, 28));
        label = new QLabel(SaveGame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 401, 31));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(SaveGame);

        QMetaObject::connectSlotsByName(SaveGame);
    } // setupUi

    void retranslateUi(QDialog *SaveGame)
    {
        SaveGame->setWindowTitle(QApplication::translate("SaveGame", "Dialog", 0, QApplication::UnicodeUTF8));
        save_yes->setText(QApplication::translate("SaveGame", "Yes", 0, QApplication::UnicodeUTF8));
        save_no->setText(QApplication::translate("SaveGame", "No", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SaveGame", "Would you like to save the game?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaveGame: public Ui_SaveGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEGAME_H
