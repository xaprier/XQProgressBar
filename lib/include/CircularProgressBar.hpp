#ifndef CIRCULARPROGRESSBAR_HPP
#define CIRCULARPROGRESSBAR_HPP

#include <qobjectdefs.h>

#include <QColor>
#include <QFont>
#include <QMap>
#include <QPaintEvent>
#include <QPainter>
#include <QResizeEvent>
#include <QWidget>

namespace xaprier {
namespace qt {
namespace widgets {
class CircularProgressBar : public QWidget {
    Q_OBJECT
    Q_PROPERTY(int circularDegree MEMBER m_circularDegree READ GetCircularDegree WRITE SetCircularDegree NOTIFY si_CircularDegreeChanged)
    Q_PROPERTY(int value MEMBER m_value READ GetValue WRITE SetValue NOTIFY si_ValueChanged)
    Q_PROPERTY(int width MEMBER m_width READ GetWidth WRITE SetWidth NOTIFY si_WidthChanged)
    Q_PROPERTY(int height MEMBER m_height READ GetHeight WRITE SetHeight NOTIFY si_HeightChanged)
    Q_PROPERTY(int marginX MEMBER m_marginX READ GetMarginX WRITE SetMarginX NOTIFY si_MarginXChanged)
    Q_PROPERTY(int marginY MEMBER m_marginY READ GetMarginY WRITE SetMarginY NOTIFY si_MarginYChanged)
    Q_PROPERTY(int progressWidth MEMBER m_progressWidth READ GetProgressWidth WRITE SetProgressWidth NOTIFY si_ProgressWidthChanged)
    Q_PROPERTY(int maxValue MEMBER m_maxValue READ GetMaxValue WRITE SetMaxValue NOTIFY si_MaxValueChanged)

    Q_PROPERTY(bool square MEMBER m_square READ GetSquare WRITE SetSquare NOTIFY si_SquareChanged)
    Q_PROPERTY(bool shadow MEMBER m_shadow READ GetShadow WRITE SetShadow NOTIFY si_ShadowChanged)
    Q_PROPERTY(bool progressRoundedCap MEMBER m_progressRoundedCap READ GetProgressRoundedCap WRITE SetProgressRoundedCap NOTIFY si_ProgressRoundedCapChanged)
    Q_PROPERTY(bool enableBg MEMBER m_enableBg READ GetEnableBg WRITE SetEnableBg NOTIFY si_EnableBgChanged)
    Q_PROPERTY(bool gradient MEMBER m_gradient READ GetGradient WRITE SetGradient NOTIFY si_GradientChanged)
    Q_PROPERTY(bool enableText MEMBER m_enableText READ GetEnableText WRITE SetEnableText NOTIFY si_EnableTextChanged)

    Q_PROPERTY(Qt::Alignment textAlignment MEMBER m_textAlignment READ GetTextAlignment WRITE SetTextAlignment NOTIFY si_TextAlignmentChanged)
    Q_PROPERTY(Qt::Alignment progressAlignment MEMBER m_progressAlignment READ GetProgressAlignment WRITE SetProgressAlignment NOTIFY si_ProgressAlignmentChanged)

    Q_PROPERTY(QColor bgColor MEMBER m_bgColor READ GetBgColor WRITE SetBgColor NOTIFY si_BgColorChanged)
    Q_PROPERTY(QColor progressColor MEMBER m_progressColor READ GetProgressColor WRITE SetProgressColor NOTIFY si_ProgressColorChanged)
    Q_PROPERTY(QColor textColor MEMBER m_textColor READ GetTextColor WRITE SetTextColor NOTIFY si_TextColorChanged)
    Q_PROPERTY(QFont font MEMBER m_font READ GetFont WRITE SetFont NOTIFY si_FontChanged)

    Q_PROPERTY(QString suffix MEMBER m_suffix READ GetSuffix WRITE SetSuffix)

    Q_PROPERTY(QMap<qreal, QColor> gradientColors MEMBER m_gradientColors READ GetGradientColors WRITE SetGradientColors NOTIFY si_GradientColorsChanged)

  public:
    /**
     * @brief Construct a new Circular Progress object
     *
     * @param parent Parent widget
     */
    CircularProgressBar(QWidget *parent = nullptr);
    ~CircularProgressBar();

    ///< SETTERS
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

    ///< GETTERS
    int GetCircularDegree() const { return m_circularDegree; }
    int GetValue() const { return m_value; }
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    int GetMarginX() const { return m_marginX; }
    int GetMarginY() const { return m_marginY; }
    int GetProgressWidth() const { return m_progressWidth; }
    int GetMaxValue() const { return m_maxValue; }

    bool GetSquare() const { return m_square; }
    bool GetShadow() const { return m_shadow; }
    bool GetProgressRoundedCap() const { return m_progressRoundedCap; }
    bool GetEnableBg() const { return m_enableBg; }
    bool GetGradient() const { return m_gradient; }
    bool GetEnableText() const { return m_enableText; }

    Qt::Alignment GetTextAlignment() const { return m_textAlignment; }
    Qt::Alignment GetProgressAlignment() const { return m_progressAlignment; }

    QColor GetBgColor() const { return m_bgColor; }
    QColor GetProgressColor() const { return m_progressColor; }
    QColor GetTextColor() const { return m_textColor; }
    QColor GetGradientColor(qreal value) const {
        if (m_gradientColors.contains(value)) return m_gradientColors[value];
        return QColor();
    }

    QFont GetFont() const { return m_font; }

    QString GetSuffix() const { return m_suffix; }

    QMap<qreal, QColor> GetGradientColors() const { return m_gradientColors; }

  signals:
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

  protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

  private:
    QWidget *m_superClass = nullptr;
    int m_circularDegree = 270;  //> default degree of circular
    int m_value = 0;
    int m_width = 200;
    int m_height = 200;
    int m_marginX = 0;
    int m_marginY = 0;
    int m_progressWidth = 10;
    int m_maxValue = 100;
    bool m_square = false;  //> square progress bar
    bool m_shadow = false;
    bool m_progressRoundedCap = true;
    bool m_enableBg = true;
    bool m_gradient = false;
    bool m_enableText = true;
    Qt::Alignment m_textAlignment = Qt::AlignCenter;
    Qt::Alignment m_progressAlignment = Qt::AlignCenter;
    QColor m_bgColor = "#44475a";
    QColor m_progressColor = "#498BD1";
    QColor m_textColor = "#498BD1";
    QFont m_font = QFont("Segoe UI", 12);
    QString m_suffix = "%";
    QMap<qreal, QColor> m_gradientColors;
};

}  // namespace widgets
}  // namespace qt
}  // namespace xaprier

#endif  // CIRCULARPROGRESSBAR_HPP