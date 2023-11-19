#include "mainwindow.h"

#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qprogressbar.h>
#include <qpushbutton.h>

#include <QColorDialog>
#include <QFontDialog>
#include <QLayout>
#include <QSpinBox>

#include "../design/ui_mainwindow.h"
#include "CircularProgressBar.hpp"
#include "GradientColorEditor.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->progressBar = new XQt::CircularProgressBar(this);
    this->progressBar->setProgressAlignment(Qt::AlignRight | Qt::AlignTop);
    this->progressBar->setSquare(true);

    this->ui->gridLayout->addWidget(this->progressBar);
    connect(this->ui->progressColorButton, &QPushButton::clicked, [&]() {
        QColorDialog colorDialog;

        // Pencere başlangıçta görünecek olan renk
        colorDialog.setCurrentColor(Qt::red);

        // Renk seçildiğinde gerçekleştirilecek işlemler
        if (colorDialog.exec()) {
            // Kullanıcı bir renk seçti
            QColor selectedColor = colorDialog.selectedColor();
            QString colorHex = selectedColor.name();  // Renk değerini al

            this->progressBar->setProgressColor(colorHex);
            this->ui->progressColorButton->setStyleSheet(
                "QPushButton { background-color: " + colorHex + "; }");
        }
    });

    connect(this->ui->cirdularDegreeLE, &QLineEdit::textChanged,
            [&](QString text) {
                try {
                    int degree = text.toInt();
                    this->progressBar->setCircularDegree(degree);
                } catch (...) {
                    this->ui->cirdularDegreeLE->setText("0");
                    return;
                }
            });

    connect(this->ui->backgroundColorButton, &QPushButton::clicked, [&]() {
        QColorDialog colorDialog;

        // Pencere başlangıçta görünecek olan renk
        colorDialog.setCurrentColor(Qt::red);

        // Renk seçildiğinde gerçekleştirilecek işlemler
        if (colorDialog.exec()) {
            // Kullanıcı bir renk seçti
            QColor selectedColor = colorDialog.selectedColor();
            QString colorHex = selectedColor.name();  // Renk değerini al

            this->progressBar->setBgColor(colorHex);
            this->ui->backgroundColorButton->setStyleSheet(
                "QPushButton { background-color: " + colorHex + "; }");
        }
    });

    connect(this->ui->textColorButton, &QPushButton::clicked, [&]() {
        QColorDialog colorDialog;

        // Pencere başlangıçta görünecek olan renk
        colorDialog.setCurrentColor(Qt::red);

        // Renk seçildiğinde gerçekleştirilecek işlemler
        if (colorDialog.exec()) {
            // Kullanıcı bir renk seçti
            QColor selectedColor = colorDialog.selectedColor();
            QString colorHex = selectedColor.name();  // Renk değerini al

            this->progressBar->setTextColor(colorHex);
            this->ui->textColorButton->setStyleSheet(
                "QPushButton { background-color: " + colorHex + "; }");
        }
    });

    connect(this->ui->valueSlider, &QSlider::valueChanged, this->progressBar,
            &XQt::CircularProgressBar::SL_setValue);

    connect(this->ui->textCheck, &QCheckBox::stateChanged,
            [&](bool check) { this->progressBar->setEnableText(check); });

    connect(this->ui->enableBgCheck, &QCheckBox::stateChanged,
            [&](bool check) { this->progressBar->setEnableBg(check); });

    connect(this->ui->progressRoundedCheck, &QCheckBox::stateChanged,
            [&](bool check) { this->progressBar->setProgressRoundedCap(check); });

    connect(this->ui->shadowCheck, &QCheckBox::stateChanged,
            [&](bool check) { this->progressBar->setShadow(check); });

    connect(this->ui->heightLE, &QLineEdit::textChanged, [&](QString text) {
        try {
            this->progressBar->setHeight(text.toInt());
        } catch (...) {
            return;
        }
    });

    connect(this->ui->widthLE, &QLineEdit::textChanged, [&](QString text) {
        try {
            this->progressBar->setWidth(text.toInt());
        } catch (...) {
            return;
        }
    });

    connect(this->ui->maxValueLE, &QLineEdit::textChanged, [&](QString text) {
        try {
            this->progressBar->setMaxValue(text.toInt());
        } catch (...) {
            return;
        }
    });

    connect(this->ui->progressWidthLE, &QLineEdit::textChanged,
            [&](QString text) {
                try {
                    this->progressBar->setProgressWidth(text.toInt());
                } catch (...) {
                    return;
                }
            });

    connect(this->ui->fontFamilyButton, &QPushButton::clicked, [&]() {
        QFontDialog dialog;
        dialog.exec();
        this->progressBar->setFont(dialog.selectedFont());
    });

    connect(this->ui->suffixLE, &QLineEdit::textChanged,
            [&](QString text) { this->progressBar->setSuffix(text); });

    connect(this->ui->squareCheck, &QCheckBox::stateChanged,
            [&](int state) { this->progressBar->setSquare(state); });

    connect(this->ui->gradientCheck, &QCheckBox::stateChanged,
            [&](int state) { this->ui->gradientButton->setEnabled(state); });

    connect(this->ui->gradientButton, &QPushButton::clicked, [&]() {
        QDialog dialog(this);
        GradientColorEditor editor(&dialog);
        QPushButton deleteButton("Delete Item", &dialog);
        QPushButton insertButton("Insert Item", &dialog);

        connect(&deleteButton, &QPushButton::clicked, &editor,
                &GradientColorEditor::deleteSelectedItem);
        connect(&insertButton, &QPushButton::clicked, &editor,
                &GradientColorEditor::insertNewItem);
        connect(&editor, &GradientColorEditor::gradientChanged, this->progressBar,
                &XQt::CircularProgressBar::SL_setGradientValues);

        QGridLayout layout;
        layout.addWidget(qobject_cast<QWidget *>(&editor));
        layout.addWidget(&deleteButton);
        layout.addWidget(&insertButton);
        dialog.setLayout(&layout);
        dialog.resize(400, 400);

        dialog.exec();
    });
}

MainWindow::~MainWindow() { delete ui; }
