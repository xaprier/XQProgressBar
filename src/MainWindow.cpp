#include "MainWindow.hpp"

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

#include "../design/ui_MainWindow.h"
#include "CircularProgressBar.hpp"
#include "GradientColorEditor.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->progressBar = new xaprier::qt::widgets::CircularProgressBar(this);
    this->progressBar->SetProgressAlignment(Qt::AlignCenter);
    this->progressBar->SetSquare(true);

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

            this->progressBar->SetProgressColor(colorHex);
            this->ui->progressColorButton->setStyleSheet(
                "QPushButton { background-color: " + colorHex + "; }");
        }
    });

    connect(this->ui->cirdularDegreeLE, &QLineEdit::textChanged,
            [&](QString text) {
                try {
                    int degree = text.toInt();
                    this->progressBar->SetCircularDegree(degree);
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

            this->progressBar->SetBgColor(colorHex);
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

            this->progressBar->SetTextColor(colorHex);
            this->ui->textColorButton->setStyleSheet(
                "QPushButton { background-color: " + colorHex + "; }");
        }
    });

    connect(this->ui->valueSlider, &QSlider::valueChanged, [&](int value) {
        this->progressBar->SetValue(value);
    });

    connect(this->ui->textCheck, &QCheckBox::stateChanged,
            [&](bool check) { this->progressBar->SetEnableText(check); });

    connect(this->ui->enableBgCheck, &QCheckBox::stateChanged,
            [&](bool check) { this->progressBar->SetEnableBg(check); });

    connect(this->ui->progressRoundedCheck, &QCheckBox::stateChanged,
            [&](bool check) { this->progressBar->SetProgressRoundedCap(check); });

    connect(this->ui->shadowCheck, &QCheckBox::stateChanged,
            [&](bool check) { this->progressBar->SetShadow(check); });

    connect(this->ui->heightLE, &QLineEdit::textChanged, [&](QString text) {
        try {
            this->progressBar->SetHeight(text.toInt());
        } catch (...) {
            return;
        }
    });

    connect(this->ui->widthLE, &QLineEdit::textChanged, [&](QString text) {
        try {
            this->progressBar->SetWidth(text.toInt());
        } catch (...) {
            return;
        }
    });

    connect(this->ui->maxValueLE, &QLineEdit::textChanged, [&](QString text) {
        try {
            this->progressBar->SetMaxValue(text.toInt());
        } catch (...) {
            return;
        }
    });

    connect(this->ui->progressWidthLE, &QLineEdit::textChanged,
            [&](QString text) {
                try {
                    this->progressBar->SetProgressWidth(text.toInt());
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
            [&](QString text) { this->progressBar->SetSuffix(text); });

    connect(this->ui->squareCheck, &QCheckBox::stateChanged,
            [&](int state) { this->progressBar->SetSquare(state); });

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
        connect(&editor, &GradientColorEditor::gradientChanged, [&](const QMap<qreal, QColor> &map) {
            this->progressBar->SetGradientColors(map);
        });

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
