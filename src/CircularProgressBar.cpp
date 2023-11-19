#include "CircularProgressBar.hpp"

#include <qboxlayout.h>
#include <qglobal.h>
#include <qnamespace.h>
#include <qpainter.h>

#include <QResizeEvent>
#include <QVBoxLayout>
#include <iostream>

namespace XQt {
CircularProgressBar::CircularProgressBar(QWidget *parent)
    : QWidget(parent), SuperClass(parent) {
    this->paint = new QPainter();
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    resize(width, height);
    updateGeometry();
}

CircularProgressBar::~CircularProgressBar() { delete this->paint; }

void CircularProgressBar::resizeEvent(QResizeEvent *event) {
    QSize size;
    if (event->size().width() > width + marginX * 2)  // expand
        size.setWidth(qMax(event->size().width(), width + marginX * 2));
    else  // shrink
        size.setWidth(qMin(event->size().width(), width + marginX * 2));

    if (event->size().height() > height + marginY * 2)  // expand
        size.setHeight(qMax(event->size().height(), height + marginY * 2));
    else  // shrink
        size.setHeight(qMin(event->size().height(), height + marginY * 2));

    if (square) {
        this->width = qMin(size.width(), size.height());
        this->height = qMin(size.width(), size.height());
        if (progressAlignment & Qt::AlignCenter) {
            this->marginX = (size.width() - this->width) / 2;
            this->marginY = (size.height() - this->height) / 2;
        } else {
            if (progressAlignment & Qt::AlignHCenter) {
                this->marginX = (size.width() - this->width) / 2;
            } else if (progressAlignment & Qt::AlignRight) {
                this->marginX = (size.width() - this->width);
            } else if (progressAlignment & Qt::AlignLeft) {
                this->marginX = 0;
            }

            if (progressAlignment & Qt::AlignVCenter) {
                this->marginY = (size.height() - this->height) / 2;
            } else if (progressAlignment & Qt::AlignBottom) {
                this->marginY = (size.height() - this->height);
            } else if (progressAlignment & Qt::AlignTop) {
                this->marginY = 0;
            }
        }
    } else {
        this->width = size.width();
        this->height = size.height();
        this->marginX = 0;
        this->marginY = 0;
    }

    update();
}
void CircularProgressBar::paintEvent(QPaintEvent *event) {
    auto pnwidth = width - progress_width;
    auto pnheight = height - progress_width;
    auto margin = progress_width / 2;
    auto pnvalue =
        (value * circularDegree / max_value);  // 270 degree circular progress

    // painter
    paint->begin(this);
    paint->setRenderHint(QPainter::Antialiasing);
    paint->setFont(font);

    // create rect
    auto rect = QRect(std::abs(marginX - margin), std::abs(marginY - margin),
                      width, height);
    paint->setPen(Qt::NoPen);
    paint->drawRect(rect);

    // pen
    auto pen = QPen();
    pen.setWidth(progress_width);

    // bg pen
    auto penny = QPen();
    penny.setWidth(progress_width);

    // set round cap
    if (progress_rounded_cap) {
        pen.setCapStyle(Qt::RoundCap);
        penny.setCapStyle(Qt::RoundCap);
    }

    if (enable_bg) {
        paint->setPen(penny);
        paint->drawArc(marginX + margin, marginY + margin, pnwidth, pnheight,
                       -((180 - (360 - circularDegree)) / 2.0) * 16,
                       circularDegree * 16);
    }

    // create arc/circular progress
    if (true) {
        int angle = -((180 - (360 - circularDegree)) / 2.0);

        if (progress_rounded_cap)
            circularDegree == 360 ? angle += 1 : angle -= 1;

        QConicalGradient gradient(
            QPointF(marginX + width / 2, marginY + height / 2), angle);

        for (auto it = gradient_colors.begin(); it != gradient_colors.end(); ++it) {
            qreal value = it.key();
            QColor color = it.value();
            gradient.setColorAt(value, color);

            // Burada value ve color ile işlemler yapabilirsiniz
            // qDebug() << "Value:" << value << ", Color:" << color.name();
        }

        // gradient.setColorAt(0.0, Qt::darkRed);
        // gradient.setColorAt(0.1, Qt::red);
        // gradient.setColorAt(0, Qt::yellow);
        // gradient.setColorAt(1, Qt::green);
        pen.setBrush(gradient);
    } else {
        pen.setColor(progress_color);
    }

    paint->setPen(pen);
    paint->drawArc(marginX + margin, marginY + margin, pnwidth, pnheight,
                   -((180 + (360 - circularDegree)) / 2.0) * 16, -pnvalue * 16);

    // create text
    if (enable_text) {
        pen.setColor(text_color);
        paint->setPen(pen);
        paint->drawText(rect, textAlignment,
                        QString::number((double)value / max_value * 100.0) +
                            suffix);
    }

    // end
    paint->end();
}

void CircularProgressBar::setCircularDegree(const int &value) {
    this->circularDegree = value;
    repaint();
    emit this->SI_circularDegreeChanged(value);
}

void CircularProgressBar::setValue(const int &value) {
    this->value = value;
    if (value > max_value)
        this->value = max_value;
    repaint();  // render progress bar after value is changed
    emit SI_valueChanged(value);
}

void CircularProgressBar::setMargin(const int &x, const int &y) {
    this->marginX = x;
    this->marginY = y;
    repaint();
    emit SI_marginChanged(x, y);
}

void CircularProgressBar::setShadow(const bool &enable) {
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
    this->shadow = enable;

    emit this->SI_shadowChanged(enable);
}

void CircularProgressBar::setWidth(const int &width) {
    this->width = width;
    QResizeEvent event(this->size(), this->size());
    this->resizeEvent(&event);
    repaint();
    emit this->SI_widthChanged(width);
}
void CircularProgressBar::setHeight(const int &height) {
    this->height = height;
    QResizeEvent event(this->size(), this->size());
    this->resizeEvent(&event);
    repaint();
    emit this->SI_heightChanged(height);
}
void CircularProgressBar::setTextAlignment(const Qt::Alignment &alignment) {
    this->textAlignment = alignment;
    repaint();
    emit this->SI_textAlignmentChanged(alignment);
}
void CircularProgressBar::setProgressAlignment(const Qt::Alignment &alignment) {
    this->progressAlignment = alignment;
    repaint();
    emit this->SI_progressAlignmentChanged(alignment);
}
void CircularProgressBar::setProgressWidth(const int &width) {
    this->progress_width = width;
    repaint();
    emit this->SI_progressWidthChanged(width);
}
void CircularProgressBar::setProgressRoundedCap(const bool &enable) {
    this->progress_rounded_cap = enable;
    repaint();
    emit this->SI_progressCapChanged(enable);
}
void CircularProgressBar::setEnableBg(const bool &enable) {
    this->enable_bg = enable;
    repaint();
    emit this->SI_backgroundChanged(enable);
}
void CircularProgressBar::setBgColor(const QColor &color) {
    this->bg_color = color;
    repaint();
    emit this->SI_backgroundColorChanged(color);
}
void CircularProgressBar::setProgressColor(const QColor &color) {
    this->progress_color = color;
    repaint();
    emit this->SI_progressColorChanged(color);
}
void CircularProgressBar::setEnableText(const bool &enable) {
    this->enable_text = enable;
    repaint();
    emit this->SI_textEnableChanged(enable);
}
void CircularProgressBar::setMaxValue(const int &value) {
    if (value <= 0) {
        std::cerr << "Invalid max value" << std::endl;
        return;
    }

    if (value < this->value) {
        this->value = value;
    }

    this->max_value = value;
    repaint();
    emit this->SI_maxValueChanged(value);
}
void CircularProgressBar::setFont(const QFont &family) {
    this->font = family;
    repaint();
    emit this->SI_fontChanged(family);
}

void CircularProgressBar::setSuffix(const QString &suffix) {
    this->suffix = suffix;
    repaint();
    emit this->SI_suffixChanged(suffix);
}
void CircularProgressBar::setTextColor(const QColor &color) {
    this->text_color = color;
    repaint();
    emit this->SI_textColorChanged(color);
}
void CircularProgressBar::setSquare(const bool &enable) {
    this->square = enable;
    QResizeEvent event(this->size(), this->size());
    this->resizeEvent(&event);
    emit this->SI_squareChanged(enable);
}
void CircularProgressBar::setGradient(const bool &enable) {
    this->gradient = enable;
    repaint();
    emit this->SI_squareChanged(enable);
}
void CircularProgressBar::setGradientValues(const QMap<qreal, QColor> &colors) {
    this->gradient_colors = colors;
    repaint();
    emit this->SI_gradientValuesChanged(colors);
}
}  // namespace XQt
