# XQProgressBar
XQt::CircularProgressBar is a circular progress bar written in C++ using Qt Widgets. This progress bar offers a range of features and customization options, making it a versatile choice for various applications.

You can use QtQuick but if you don't want you can use my project which is produced by QPainter

The progress bar is under namespace XQt and it has multiple props as QProgressBar but more!

## Features
- Circular Design: The progress bar adopts a circular layout, providing a visually appealing representation of progress.
- Extensive Properties: XQt::CircularProgressBar includes properties similar to QProgressBar but with additional features for enhanced customization.
- Namespace: All components are encapsulated within the XQt namespace for better organization and to avoid naming conflicts.
- Signals and Slots: The progress bar emits signals on every property change, providing flexibility in handling updates. Corresponding slots are available for convenient interaction.
- Setter Functions: A set of setter functions allow easy adjustment of various properties, enabling dynamic updates to the progress bar.
- Getter Functions: Access current property values using getter functions, ensuring encapsulation of private properties.

## Usage
To use XQt::CircularProgressBar in your project, follow these steps:
### Include Header:
Include the necessary header files in your project to access the XQt::CircularProgressBar functionalities.
```cpp
#include "CircularProgressBar.hpp"
```
### Instantiate the Progress Bar:
Create an instance of XQt::CircularProgressBar in your application.
```cpp
XQt::CircularProgressBar progressBar;
```
### Customize and Update:
Utilize the setter functions to customize the progress bar according to your requirements. Connect signals to slots for dynamic updates.
```cpp
progressBar.setCircularDegree(180);
progressBar.setWidth(300);
// ... add more customization
```
### Integrate with Qt Widgets:
Integrate the progress bar into your Qt Widgets application effortlessly.
```cpp
// Example of setting up a layout and adding the progress bar
QVBoxLayout* layout = new QVBoxLayout;
layout->addWidget(&progressBar);
setLayout(layout);
```
## Properties
### Signals
* The signals will be emitted on every setter function works.
  - void SI_circularDegreeChanged(int value);
  - void SI_valueChanged(int value);
  - void SI_shadowChanged(bool enable);
  - void SI_squareChanged(bool enable);
  - void SI_marginChanged(int x, int y);
  - void SI_widthChanged(int width);
  - void SI_gradientChanged(bool enable);
  - void SI_gradientValuesChanged(QMap<qreal, QColor> map);
  - void SI_heightChanged(int height);
  - void SI_textAlignmentChanged(Qt::Alignment alignment);
  - void SI_progressAlignmentChanged(Qt::Alignment alignment);
  - void SI_progressWidthChanged(int width);
  - void SI_progressCapChanged(bool enable);
  - void SI_backgroundChanged(bool enable);
  - void SI_backgroundColorChanged(QColor color);
  - void SI_progressColorChanged(QColor color);
  - void SI_textEnableChanged(bool enable);
  - void SI_maxValueChanged(int value);
  - void SI_fontChanged(QFont font);
  - void SI_suffixChanged(QString suffix);
  - void SI_textColorChanged(QColor color);
### Slots
* You can use the signals with implemented these slots:
  - void SL_setCircularDegree(int value);
  - void SL_setValue(int value);
  - void SL_setSquare(bool enable);
  - void SL_setShadow(bool enable);
  - void SL_setGradient(bool enable);
  - void SL_setMargin(int x, int y);
  - void SL_setWidth(int width);
  - void SL_setTextAlignment(Qt::Alignment alignment);
  - void SL_setProgressAlignment(Qt::Alignment alignment);
  - void SL_setGradientValues(QMap<qreal, QColor> map);
  - void SL_setHeight(int height);
  - void SL_setProgressWidth(int width);
  - void SL_setProgressRoundedCap(bool enable);
  - void SL_setEnableBg(bool enable);
  - void SL_setBgColor(QColor color);
  - void SL_setProgressColor(QColor color);
  - void SL_setEnableText(bool enable);
  - void SL_setMaxValue(int value);
  - void SL_setFont(QFont font);
  - void SL_setSuffix(QString suffix);
  - void SL_setTextColor(QColor color);,
### Setter functions
* Set the current value and update the progress bar
  - void setCircularDegree(const int &value = 270);
  - void setValue(const int &value = 0);
  - void setSquare(const bool &enable = false);
  - void setGradient(const bool &enable = false);
  - void setGradientValues(const QMap<qreal, QColor> &map);
  - void setMargin(const int &x = 0, const int &y = 0);
  - void setTextAlignment(const Qt::Alignment &alignment = Qt::AlignCenter);
  - void setProgressAlignment(const Qt::Alignment &alignment = Qt::AlignCenter);
  - void setShadow(const bool &enable = true);
  - void setWidth(const int &width = 200);
  - void setHeight(const int &height = 200);
  - void setProgressWidth(const int &width = 10);
  - void setProgressRoundedCap(const bool &enable = true);
  - void setEnableBg(const bool &enable = true);
  - void setBgColor(const QColor &color = "#44475a");
  - void setProgressColor(const QColor &color = "#498BD1");
  - void setEnableText(const bool &enable = true);
  - void setMaxValue(const int &value = 100);
  - void setFont(const QFont &family = QFont("Segoe UI", 12));
  - void setSuffix(const QString &suffix = "%");
  - void setTextColor(const QColor &color = "#498BD1");
### Getter functions 
* Accessing current value(all props are under private construction, so use getter for access it)
  - int getCircularDegree() const;
  - int getValue() const;
  - int getMarginX() const;
  - int getMarginY() const;
  - int getWidth() const;
  - bool getSquared() const;
  - bool getGradient() const;
  - QMap<qreal, QColor> getGradientValues() const;
  - int getHeight() const;
  - int getProgressWidth() const;
  - Qt::Alignment getTextAlignment() const;
  - Qt::Alignment getProgressAlignment() const;
  - bool getShadow() const;
  - bool getProgressRoundedCap() const;
  - bool getEnableBg() const;
  - QColor getBgColor() const;
  - QColor getProgressColor() const;
  - bool getEnableText() const;
  - int getMaxValue() const;
  - QFont getFont() const;
  - QString getSuffix() const;
  - QColor getTextColor() const;

# An example MainWindow for testing these features
- All the implementation can be tested with created MainWindow class.
- Picture of MainWindow
![MainWindow](https://raw.githubusercontent.com/xaprier/XQProgressBar/main/assets/MainWindow.png)
