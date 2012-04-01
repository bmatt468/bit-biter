/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created: Fri Mar 30 21:18:43 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *body;
    QPushButton *food;
    QPushButton *death;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(258, 285);
        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-110, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        body = new QPushButton(Options);
        body->setObjectName(QString::fromUtf8("body"));
        body->setGeometry(QRect(50, 20, 141, 51));
        food = new QPushButton(Options);
        food->setObjectName(QString::fromUtf8("food"));
        food->setGeometry(QRect(50, 80, 141, 51));
        death = new QPushButton(Options);
        death->setObjectName(QString::fromUtf8("death"));
        death->setGeometry(QRect(50, 140, 141, 51));

        retranslateUi(Options);
        QObject::connect(buttonBox, SIGNAL(accepted()), Options, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Options, SLOT(reject()));

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Game Options", 0, QApplication::UnicodeUTF8));
        body->setText(QApplication::translate("Options", "Set Body Color", 0, QApplication::UnicodeUTF8));
        food->setText(QApplication::translate("Options", "Set Food Color", 0, QApplication::UnicodeUTF8));
        death->setText(QApplication::translate("Options", "Set Death Color", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
