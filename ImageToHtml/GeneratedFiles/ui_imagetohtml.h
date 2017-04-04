/********************************************************************************
** Form generated from reading UI file 'imagetohtml.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGETOHTML_H
#define UI_IMAGETOHTML_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageToHtmlClass
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QSpinBox *spinBox;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *ImageToHtmlClass)
    {
        if (ImageToHtmlClass->objectName().isEmpty())
            ImageToHtmlClass->setObjectName(QStringLiteral("ImageToHtmlClass"));
        ImageToHtmlClass->resize(360, 175);
        lineEdit = new QLineEdit(ImageToHtmlClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(310, 20, 30, 25));
        label = new QLabel(ImageToHtmlClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 20, 40, 25));
        label_2 = new QLabel(ImageToHtmlClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 50, 25));
        lineEdit_2 = new QLineEdit(ImageToHtmlClass);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 20, 160, 25));
        label_3 = new QLabel(ImageToHtmlClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 55, 25));
        lineEdit_3 = new QLineEdit(ImageToHtmlClass);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(70, 60, 160, 25));
        pushButton = new QPushButton(ImageToHtmlClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 60, 75, 25));
        label_4 = new QLabel(ImageToHtmlClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 55, 25));
        lineEdit_4 = new QLineEdit(ImageToHtmlClass);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(70, 100, 160, 25));
        pushButton_2 = new QPushButton(ImageToHtmlClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 100, 75, 25));
        label_5 = new QLabel(ImageToHtmlClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 140, 80, 25));
        spinBox = new QSpinBox(ImageToHtmlClass);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(90, 140, 31, 25));
        label_6 = new QLabel(ImageToHtmlClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 70, 25));
        spinBox_2 = new QSpinBox(ImageToHtmlClass);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(210, 140, 40, 25));
        pushButton_3 = new QPushButton(ImageToHtmlClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 140, 75, 25));
        pushButton_4 = new QPushButton(ImageToHtmlClass);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(340, 0, 20, 20));

        retranslateUi(ImageToHtmlClass);

        QMetaObject::connectSlotsByName(ImageToHtmlClass);
    } // setupUi

    void retranslateUi(QWidget *ImageToHtmlClass)
    {
        ImageToHtmlClass->setWindowTitle(QApplication::translate("ImageToHtmlClass", "ImageToHtml", 0));
        label->setText(QApplication::translate("ImageToHtmlClass", "\345\241\253\345\205\205\345\255\227", 0));
        label_2->setText(QApplication::translate("ImageToHtmlClass", "\347\275\221\351\241\265\346\240\207\351\242\230", 0));
        label_3->setText(QApplication::translate("ImageToHtmlClass", "\347\224\237\346\210\220\346\226\207\344\273\266", 0));
        pushButton->setText(QApplication::translate("ImageToHtmlClass", "\351\200\211\346\213\251\350\267\257\345\276\204", 0));
        label_4->setText(QApplication::translate("ImageToHtmlClass", "\345\233\276\347\211\207\350\267\257\345\276\204", 0));
        pushButton_2->setText(QApplication::translate("ImageToHtmlClass", "\351\200\211\346\213\251\345\233\276\347\211\207", 0));
        label_5->setText(QApplication::translate("ImageToHtmlClass", "\347\233\256\346\240\207\347\275\221\351\241\265\345\256\275\345\272\246", 0));
        label_6->setText(QApplication::translate("ImageToHtmlClass", "\345\255\227\344\275\223\345\244\247\345\260\217(px)", 0));
        pushButton_3->setText(QApplication::translate("ImageToHtmlClass", "\345\274\200\345\247\213\347\224\237\346\210\220", 0));
        pushButton_4->setText(QApplication::translate("ImageToHtmlClass", "x", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageToHtmlClass: public Ui_ImageToHtmlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGETOHTML_H
