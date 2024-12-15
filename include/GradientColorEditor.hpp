#ifndef GRADIENTCOLOREDITOR_H
#define GRADIENTCOLOREDITOR_H

#include <QListWidget>

#include "../include/CircularProgressBar.hpp"

QT_BEGIN_NAMESPACE
class QColor;
class QWidget;
QT_END_NAMESPACE

class GradientColorEditor : public QListWidget {
    Q_OBJECT

  public:
    GradientColorEditor(QWidget *widget = nullptr);

  signals:
    void gradientChanged(const QMap<qreal, QColor> &map);
  public slots:
    void itemDoubleClicked(QListWidgetItem *item);
    void deleteSelectedItem(bool clicked);
    void insertNewItem(bool clicked);

  private:
    void updateRepresentation();
    QMap<qreal, QColor> gradientColors;
    QList<QColor> colors;
    QList<qreal> values;
};
//! [0]
#endif  // GRADIENTCOLOREDITOR_H