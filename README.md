# XQProgressBar
A circular progressbar written with C++ &amp; Qt Widgets!

You can use QtQuick but if you don't want you can use my project which is produced by QPainter

The progress bar is under namespace XQt and it has multiple props as QProgressBar but more!

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
- Picture of MainWindow: [https://github.com/xaprier/XQProgressBar/blob/main/assets/MainWindow.png](https://github.com/xaprier/XQProgressBar/blob/main/assets/MainWindow.png?raw=true)https://github.com/xaprier/XQProgressBar/blob/main/assets/MainWindow.png?raw=true
