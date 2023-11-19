#include "../include/GradientColorEditor.hpp"

#include <qboxlayout.h>
#include <qcolordialog.h>
#include <qgridlayout.h>
#include <qlayoutitem.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qprogressbar.h>

#include <QColorDialog>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLayout>
#include <algorithm>

GradientColorEditor::GradientColorEditor(QWidget *parent)
    : QListWidget{parent} {
    this->insertItem(0, "0.0");
    connect(this, &QListWidget::itemDoubleClicked, this,
            &GradientColorEditor::itemDoubleClicked);
    this->values.append(0.0);
    this->colors.append(this->item(0)->background().color());
    this->updateRepresentation();
}

void GradientColorEditor::itemDoubleClicked(QListWidgetItem *item) {
    QColorDialog dialog;
    QLineEdit value;
    value.setText(item->text());
    QLabel label("Gradient Value");
    QHBoxLayout layout;
    layout.addWidget(&label);
    layout.addWidget(&value);

    QVBoxLayout *dialogLayout = qobject_cast<QVBoxLayout *>(dialog.layout());
    dialogLayout->insertLayout(dialogLayout->count() - 1, &layout);

    dialog.exec();

    item->setText(value.text());
    item->setBackground(QBrush(dialog.selectedColor()));
    this->values.replace(this->currentRow(), value.text().toDouble());
    this->colors.replace(this->currentRow(), dialog.selectedColor());
    this->updateRepresentation();
}

void GradientColorEditor::deleteSelectedItem(bool clicked) {
    this->values.removeAt(this->currentRow());
    this->colors.removeAt(this->currentRow());
    if (this->currentItem() != nullptr) {
        this->takeItem(this->currentRow());
        this->setCurrentRow(0);
        this->setCurrentItem(this->item(0));
    }
    this->updateRepresentation();
}

void GradientColorEditor::insertNewItem(bool clicked) {
    this->insertItem(this->count(), "0.0");
    this->values.append(0.0);
    this->colors.append(this->item(this->count() - 1)->background().color());
    this->setCurrentRow(this->count() - 1);
    this->setCurrentItem(this->item(this->count() - 1));
    this->itemDoubleClicked(this->item(this->count() - 1));
}

void GradientColorEditor::updateRepresentation() {
    QMap<qreal, QColor> gradients;
    for (int i = 0; i < this->values.size(); i++) {
        qDebug() << this->values[i] << this->colors[i];
        gradients.insert(this->values[i], this->colors[i]);
    }
    emit gradientChanged(gradients);
}