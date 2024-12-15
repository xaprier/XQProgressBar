# XQCircularProgressBar
CircularProgressBar is a circular progress bar written in C++ using Qt Widgets. This progress bar offers a range of features and customization options, making it a versatile choice for various applications.

You can use QtQuick but if you don't want you can use my project which is produced by QPainter.

The progress bar is under namespace xaprier::qt::widgets and it has multiple props as QProgressBar but more!

## Features
- Circular Design: The progress bar adopts a circular layout, providing a visually appealing representation of progress.
- Extensive Properties: CircularProgressBar includes properties similar to QProgressBar but with additional features for enhanced customization.
- Namespace: All components are encapsulated within the <b>xaprier::qt::widgets</b> namespace for better organization and to avoid naming conflicts.
- Signals and Slots: The progress bar emits signals on every property change, providing flexibility in handling updates. Corresponding slots are available for convenient interaction.
- Setter Functions: A set of setter functions allow easy adjustment of various properties, enabling dynamic updates to the progress bar.
- Getter Functions: Access current property values using getter functions, ensuring encapsulation of private properties.

## Usage
To use <b>CircularProgressBar</b> in your project, follow these steps:
### Link to your project
If you add this repository as submodule of your project, add this project's directory as subdirectory to CMake determine this project. Then you can link to your CMake project by
```cmake
target_link_libraries(YOUR_PROJECT PRIVATE XQCircularProgressBar)
```
### Include Header:
Include the necessary header files in your project to access the CircularProgressBar functionalities.
```cpp
#include "CircularProgressBar.hpp"
```
### Instantiate the Progress Bar:
Create an instance of CircularProgressBar in your application.
```cpp
xaprier::qt::widgets::CircularProgressBar progressBar;
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
```cpp
void si_CircularDegreeChanged(int value);
void si_ValueChanged(int value);
void si_WidthChanged(int width);
void si_HeightChanged(int height);
void si_MarginChanged(int x, int y);
void si_MarginXChanged(int x);
void si_MarginYChanged(int y);
void si_ProgressWidthChanged(int width);
void si_MaxValueChanged(int value);
void si_SquareChanged(bool enable);
void si_ShadowChanged(bool enable);
void si_ProgressRoundedCapChanged(bool enable);
void si_EnableBgChanged(bool enable);
void si_GradientChanged(bool enable);
void si_EnableTextChanged(bool enable);
void si_TextAlignmentChanged(Qt::Alignment alignment);
void si_ProgressAlignmentChanged(Qt::Alignment alignment);
void si_BgColorChanged(QColor color);
void si_ProgressColorChanged(QColor color);
void si_TextColorChanged(QColor color);
void si_GradientColorsChanged(QMap<qreal, QColor> map);
void si_GradientColorChanged(qreal value, QColor color);
void si_FontChanged(QFont font);
void si_SuffixChanged(QString suffix);
```

### Setter functions
* Set the current value and update the progress bar
```cpp
void SetCircularDegree(const int &value = 270);
void SetValue(const int &value = 0);
void SetWidth(const int &width = 200);
void SetHeight(const int &height = 200);
void SetMargin(const int &x = 0, const int &y = 0);
void SetMarginX(const int &x = 0);
void SetMarginY(const int &y = 0);
void SetProgressWidth(const int &width = 10);
void SetMaxValue(const int &value = 100);
void SetSquare(const bool &enable = false);
void SetShadow(const bool &enable = true);
void SetProgressRoundedCap(const bool &enable = true);
void SetEnableBg(const bool &enable = true);
void SetGradient(const bool &enable = false);
void SetEnableText(const bool &enable = true);
void SetTextAlignment(const Qt::Alignment &alignment = Qt::AlignCenter);
void SetProgressAlignment(const Qt::Alignment &alignment = Qt::AlignCenter);
void SetBgColor(const QColor &color = "#44475a");
void SetProgressColor(const QColor &color = "#498BD1");
void SetTextColor(const QColor &color = "#498BD1");
void SetGradientColors(const QMap<qreal, QColor> &map);
void SetGradientColor(const qreal &value, const QColor &color);
void SetFont(const QFont &family = QFont("Segoe UI", 12));
void SetSuffix(const QString &suffix = "%");
```
### Getter functions 
* Accessing current value(all props are under private construction, so use getter for access it)
```cpp
int GetCircularDegree() const;
int GetValue() const;
int GetWidth() const;
int GetHeight() const;
int GetMarginX() const;
int GetMarginY() const;
int GetProgressWidth() const;
int GetMaxValue() const;
bool GetSquare() const;
bool GetShadow() const;
bool GetProgressRoundedCap() const;
bool GetEnableBg() const;
bool GetGradient() const;
bool GetEnableText() const;
Qt::Alignment GetTextAlignment() const;
Qt::Alignment GetProgressAlignment() const;
QColor GetBgColor() const;
QColor GetProgressColor() const;
QColor GetTextColor() const;
QColor GetGradientColor(qreal value) const;
QFont GetFont() const;
QString GetSuffix() const;
QMap<qreal, QColor> GetGradientColors() const;

```

# An example MainWindow for testing these features
- All the implementation can be tested with created MainWindow class.
- Picture of MainWindow
![MainWindow](https://raw.githubusercontent.com/xaprier/XQCircularProgressBar/main/assets/MainWindow.png)
