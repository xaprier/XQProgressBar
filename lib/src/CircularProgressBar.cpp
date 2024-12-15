#include "CircularProgressBar.hpp"

#include <qevent.h>
#include <qgraphicseffect.h>

#include <iostream>

namespace xaprier {
namespace qt {
namespace widgets {
CircularProgressBar::CircularProgressBar(QWidget *parent)
    : QWidget(parent),
      m_superClass(parent) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    resize(m_width, m_height);
    updateGeometry();
}

CircularProgressBar::~CircularProgressBar() {
    // delete m_painter;
}

void CircularProgressBar::SetCircularDegree(const int &value) {
    if (m_circularDegree != value) {
        m_circularDegree = value;
        emit si_CircularDegreeChanged(value);
        update();
        repaint();
    }
}

void CircularProgressBar::SetValue(const int &value) {
    if (m_value != value) {
        m_value = value;
        emit si_ValueChanged(value);
        update();
        repaint();
    }
}

void CircularProgressBar::SetWidth(const int &width) {
    if (m_width != width) {
        m_width = width;
        emit si_WidthChanged(width);
        QResizeEvent event(this->size(), this->size());
        this->resizeEvent(&event);
        update();
        repaint();
    }
}

void CircularProgressBar::SetHeight(const int &height) {
    if (m_height != height) {
        m_height = height;
        emit si_HeightChanged(height);
        QResizeEvent event(this->size(), this->size());
        this->resizeEvent(&event);
        update();
        repaint();
    }
}

void CircularProgressBar::SetMargin(const int &x, const int &y) {
    if (m_marginX != x || m_marginY != y) {
        m_marginX = x;
        m_marginY = y;
        emit si_MarginChanged(x, y);
        update();
        repaint();
    }
}

void CircularProgressBar::SetMarginX(const int &x) {
    if (m_marginX != x) {
        m_marginX = x;
        emit si_MarginXChanged(x);
        update();
        repaint();
    }
}

void CircularProgressBar::SetMarginY(const int &y) {
    if (m_marginY != y) {
        m_marginY = y;
        emit si_MarginYChanged(y);
        update();
        repaint();
    }
}

void CircularProgressBar::SetProgressWidth(const int &width) {
    if (m_progressWidth != width) {
        m_progressWidth = width;
        emit si_ProgressWidthChanged(width);
        update();
        repaint();
    }
}

void CircularProgressBar::SetMaxValue(const int &value) {
    if (value <= 0) {
        std::cerr << "Invalid Maximum Value: " << value << '\n';
        return;
    }

    //? Current value is lesser than new maximum
    if (value < m_value) {
        m_value = value;
    }

    this->m_maxValue = value;

    emit si_MaxValueChanged(value);
    update();
    repaint();
}

void CircularProgressBar::SetSquare(const bool &enable) {
    if (m_square != enable) {
        m_square = enable;
        emit si_SquareChanged(enable);
        QResizeEvent event(this->size(), this->size());
        this->resizeEvent(&event);
        update();
        repaint();
    }
}

void CircularProgressBar::SetShadow(const bool &enable) {
    if (m_shadow != enable) {
        if (enable) {
            auto *shadow = new QGraphicsDropShadowEffect();
            shadow->setBlurRadius(15);
            shadow->setXOffset(0);
            shadow->setYOffset(0);
            shadow->setColor(QColor(0, 0, 0, 80));
            setGraphicsEffect(shadow);
        } else {
            setGraphicsEffect(nullptr);
        }
        m_shadow = enable;
        emit si_ShadowChanged(enable);
        update();
    }
}

void CircularProgressBar::SetProgressRoundedCap(const bool &enable) {
    if (m_progressRoundedCap != enable) {
        m_progressRoundedCap = enable;
        emit si_ProgressRoundedCapChanged(enable);
        update();
        repaint();
    }
}

void CircularProgressBar::SetEnableBg(const bool &enable) {
    if (m_enableBg != enable) {
        m_enableBg = enable;
        emit si_EnableBgChanged(enable);
        update();
        repaint();
    }
}

void CircularProgressBar::SetGradient(const bool &enable) {
    if (m_gradient != enable) {
        m_gradient = enable;
        emit si_GradientChanged(enable);
        update();
        repaint();
    }
}

void CircularProgressBar::SetEnableText(const bool &enable) {
    if (m_enableText != enable) {
        m_enableText = enable;
        emit si_EnableTextChanged(enable);
        update();
        repaint();
    }
}

void CircularProgressBar::SetTextAlignment(const Qt::Alignment &alignment) {
    if (m_textAlignment != alignment) {
        m_textAlignment = alignment;
        emit si_TextAlignmentChanged(alignment);
        update();
        repaint();
    }
}

void CircularProgressBar::SetProgressAlignment(const Qt::Alignment &alignment) {
    if (m_progressAlignment != alignment) {
        m_progressAlignment = alignment;
        emit si_ProgressAlignmentChanged(alignment);
        update();
        repaint();
    }
}

void CircularProgressBar::SetBgColor(const QColor &color) {
    if (m_bgColor != color) {
        m_bgColor = color;
        emit si_BgColorChanged(color);
        update();
        repaint();
    }
}

void CircularProgressBar::SetProgressColor(const QColor &color) {
    if (m_progressColor != color) {
        m_progressColor = color;
        emit si_ProgressColorChanged(color);
        update();
        repaint();
    }
}

void CircularProgressBar::SetTextColor(const QColor &color) {
    if (m_textColor != color) {
        m_textColor = color;
        emit si_TextColorChanged(color);
        update();
        repaint();
    }
}

void CircularProgressBar::SetGradientColors(const QMap<qreal, QColor> &map) {
    if (m_gradientColors != map) {
        m_gradientColors = map;
        emit si_GradientColorsChanged(map);
        update();
        repaint();
    }
}

void CircularProgressBar::SetGradientColor(const qreal &value, const QColor &color) {
    if (m_gradientColors[value] != color) {
        m_gradientColors[value] = color;
        emit si_GradientColorChanged(value, color);
        update();
        repaint();
    }
}

void CircularProgressBar::SetFont(const QFont &family) {
    if (m_font != family) {
        m_font = family;
        emit si_FontChanged(family);
        update();
        repaint();
    }
}

void CircularProgressBar::SetSuffix(const QString &suffix) {
    if (m_suffix != suffix) {
        m_suffix = suffix;
        emit si_SuffixChanged(suffix);
        update();
        repaint();
    }
}

void CircularProgressBar::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    auto pnwidth = m_width - m_progressWidth;
    auto pnheight = m_height - m_progressWidth;
    auto margin = m_progressWidth / 2;
    auto pnvalue = (m_value * m_circularDegree / m_maxValue);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setFont(m_font);

    // create rect
    auto rect = QRect(std::abs(m_marginX - margin), std::abs(m_marginY - margin),
                      m_width, m_height);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect);

    // pen
    auto pen = QPen();
    pen.setWidth(m_progressWidth);

    // bg pen
    auto penny = QPen();
    penny.setWidth(m_progressWidth);

    // set round cap
    if (m_progressRoundedCap) {
        pen.setCapStyle(Qt::RoundCap);
        penny.setCapStyle(Qt::RoundCap);
    }

    if (m_enableBg) {
        painter.setPen(penny);
        painter.drawArc(m_marginX + margin, m_marginY + margin, pnwidth, pnheight,
                        -((180 - (360 - m_circularDegree)) / 2.0) * 16,
                        m_circularDegree * 16);
    }

    // create arc/circular progress
    if (m_gradient) {
        int angle = -((180 - (360 - m_circularDegree)) / 2.0);

        if (m_progressRoundedCap)
            m_circularDegree == 360 ? angle += 1 : angle -= 1;

        QConicalGradient gradient(
            QPointF(m_marginX + m_width / 2, m_marginY + m_height / 2), angle);  // NOLINT

        for (auto it = m_gradientColors.begin(); it != m_gradientColors.end(); ++it) {
            qreal value = it.key();
            QColor color = it.value();
            gradient.setColorAt(value, color);
        }

        pen.setBrush(gradient);
    } else {
        pen.setColor(m_progressColor);
    }

    painter.setPen(pen);
    painter.drawArc(m_marginX + margin, m_marginY + margin, pnwidth, pnheight,
                    -((180 + (360 - m_circularDegree)) / 2.0) * 16, -pnvalue * 16);

    // create text
    if (m_enableText) {
        pen.setColor(m_textColor);
        painter.setPen(pen);
        painter.drawText(rect, m_textAlignment,
                         QString::number((double)m_value / m_maxValue * 100.0) +
                             m_suffix);
    }

    // end
    painter.end();
}

void CircularProgressBar::resizeEvent(QResizeEvent *event) {
    QSize size;
    if (event->size().width() > m_width + m_marginX * 2)  // expand
        size.setWidth(qMax(event->size().width(), m_width + m_marginX * 2));
    else  // shrink
        size.setWidth(qMin(event->size().width(), m_width + m_marginX * 2));

    if (event->size().height() > m_height + m_marginY * 2)  // expand
        size.setHeight(qMax(event->size().height(), m_height + m_marginY * 2));
    else  // shrink
        size.setHeight(qMin(event->size().height(), m_height + m_marginY * 2));

    if (m_square) {
        this->m_width = qMin(size.width(), size.height());
        this->m_height = qMin(size.width(), size.height());
        if (m_progressAlignment & Qt::AlignCenter) {
            this->m_marginX = (size.width() - this->m_width) / 2;
            this->m_marginY = (size.height() - this->m_height) / 2;
        } else {
            if (m_progressAlignment & Qt::AlignHCenter) {
                this->m_marginX = (size.width() - this->m_width) / 2;
            } else if (m_progressAlignment & Qt::AlignRight) {
                this->m_marginX = (size.width() - this->m_width);
            } else if (m_progressAlignment & Qt::AlignLeft) {
                this->m_marginX = 0;
            }

            if (m_progressAlignment & Qt::AlignVCenter) {
                this->m_marginY = (size.height() - this->m_height) / 2;
            } else if (m_progressAlignment & Qt::AlignBottom) {
                this->m_marginY = (size.height() - this->m_height);
            } else if (m_progressAlignment & Qt::AlignTop) {
                this->m_marginY = 0;
            }
        }
    } else {
        this->m_width = size.width();
        this->m_height = size.height();
        this->m_marginX = 0;
        this->m_marginY = 0;
    }

    update();
}

}  // namespace widgets
}  // namespace qt
}  // namespace xaprier