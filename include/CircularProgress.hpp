#ifndef CIRCULARPROGRESS_H
#define CIRCULARPROGRESS_H

#include <qnamespace.h>

#include <QGraphicsDropShadowEffect>
#include <QMap>
#include <QPainter>
#include <QTimer>
#include <QWidget>

namespace XQt {
class CircularProgress : public QWidget {
    Q_OBJECT
  public:
    /**
     * @brief Construct a new Circular Progress object
     *
     * @param parent Parent widget
     */
    CircularProgress(QWidget *parent = nullptr);
    ~CircularProgress();

    /**
     * @brief Setter functions for the widget
     *
     * @param value
     */
    void setCircularDegree(const int &value = 270);
    void setValue(const int &value = 0);
    void setSquare(const bool &enable = false);
    void setGradient(const bool &enable = false);
    void setGradientValues(const QMap<qreal, QColor> &map);
    void setMargin(const int &x = 0, const int &y = 0);
    void setTextAlignment(const Qt::Alignment &alignment = Qt::AlignCenter);
    void setProgressAlignment(const Qt::Alignment &alignment = Qt::AlignCenter);
    void setShadow(const bool &enable = true);
    void setWidth(const int &width = 200);
    void setHeight(const int &height = 200);
    void setProgressWidth(const int &width = 10);
    void setProgressRoundedCap(const bool &enable = true);
    void setEnableBg(const bool &enable = true);
    void setBgColor(const QColor &color = "#44475a");
    void setProgressColor(const QColor &color = "#498BD1");
    void setEnableText(const bool &enable = true);
    void setMaxValue(const int &value = 100);
    void setFont(const QFont &family = QFont("Segoe UI", 12));
    void setSuffix(const QString &suffix = "%");
    void setTextColor(const QColor &color = "#498BD1");

    /**
     * @brief Getter functions for the widget
     */
    int getCircularDegree() const { return this->circularDegree; };
    int getValue() const { return this->value; };
    int getMarginX() const { return this->marginX; };
    int getMarginY() const { return this->marginY; };
    int getWidth() const { return this->width; };
    bool getSquared() const { return this->square; };
    bool getGradient() const { return this->gradient; };
    QMap<qreal, QColor> getGradientValues() const {
        return this->gradient_colors;
    };
    int getHeight() const { return this->height; };
    int getProgressWidth() const { return this->progress_width; };
    Qt::Alignment getTextAlignment() const { return this->textAlignment; };
    Qt::Alignment getProgressAlignment() const {
        return this->progressAlignment;
    };
    bool getShadow() const { return this->shadow; };
    bool getProgressRoundedCap() const { return this->progress_rounded_cap; };
    bool getEnableBg() const { return this->enable_bg; };
    QColor getBgColor() const { return this->bg_color; };
    QColor getProgressColor() const { return this->progress_color; };
    bool getEnableText() const { return this->enable_text; };
    int getMaxValue() const { return this->max_value; };
    QFont getFont() const { return this->font; };
    QString getSuffix() const { return this->suffix; };
    QColor getTextColor() const { return this->text_color; };

  signals:
    void SI_circularDegreeChanged(int value);
    void SI_valueChanged(int value);
    void SI_shadowChanged(bool enable);
    void SI_squareChanged(bool enable);
    void SI_marginChanged(int x, int y);
    void SI_widthChanged(int width);
    void SI_gradientChanged(bool enable);
    void SI_gradientValuesChanged(QMap<qreal, QColor> map);
    void SI_heightChanged(int height);
    void SI_textAlignmentChanged(Qt::Alignment alignment);
    void SI_progressAlignmentChanged(Qt::Alignment alignment);
    void SI_progressWidthChanged(int width);
    void SI_progressCapChanged(bool enable);
    void SI_backgroundChanged(bool enable);
    void SI_backgroundColorChanged(QColor color);
    void SI_progressColorChanged(QColor color);
    void SI_textEnableChanged(bool enable);
    void SI_maxValueChanged(int value);
    void SI_fontChanged(QFont font);
    void SI_suffixChanged(QString suffix);
    void SI_textColorChanged(QColor color);

  public slots:
    void SL_setCircularDegree(int value) { setCircularDegree(value); }
    void SL_setValue(int value) { setValue(value); }
    void SL_setSquare(bool enable) { setSquare(enable); }
    void SL_setShadow(bool enable) { setShadow(enable); }
    void SL_setGradient(bool enable) { setGradient(enable); }
    void SL_setMargin(int x, int y) { setMargin(x, y); }
    void SL_setWidth(int width) { setWidth(width); }
    void SL_setTextAlignment(Qt::Alignment alignment) {
        setTextAlignment(alignment);
    }
    void SL_setProgressAlignment(Qt::Alignment alignment) {
        setProgressAlignment(alignment);
    }
    void SL_setGradientValues(QMap<qreal, QColor> map) { setGradientValues(map); }
    void SL_setHeight(int height) { setHeight(height); }
    void SL_setProgressWidth(int width) { setProgressWidth(width); }
    void SL_setProgressRoundedCap(bool enable) { setProgressRoundedCap(enable); }
    void SL_setEnableBg(bool enable) { setEnableBg(enable); }
    void SL_setBgColor(QColor color) { setBgColor(color); }
    void SL_setProgressColor(QColor color) { setProgressColor(color); }
    void SL_setEnableText(bool enable) { setEnableText(enable); }
    void SL_setMaxValue(int value) { setMaxValue(value); }
    void SL_setFont(QFont font) { setFont(font); }
    void SL_setSuffix(QString suffix) { setSuffix(suffix); }
    void SL_setTextColor(QColor color) { setTextColor(color); }

  private:
    QPainter *paint = nullptr;
    QWidget *SuperClass = nullptr;
    bool square = false;
    int circularDegree = 270;  // default degree of circular
    int value = 0;
    int width = 200;
    int marginX = 0;
    int marginY = 0;
    int height = 200;
    int progress_width = 10;
    bool shadow = false;
    bool progress_rounded_cap = true;
    bool enable_bg = true;
    bool gradient = false;
    Qt::Alignment textAlignment = Qt::AlignCenter;
    Qt::Alignment progressAlignment = Qt::AlignCenter;
    QColor bg_color = "#44475a";
    QColor progress_color = "#498BD1";
    bool enable_text = true;
    int max_value = 100;
    QFont font = QFont("Segoe UI", 12);
    QString suffix = "%";
    QColor text_color = "#498BD1";
    QMap<qreal, QColor> gradient_colors;

  protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
};
}  // namespace XQt

#endif  // CIRCULARPROGRESS_H
