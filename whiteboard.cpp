#include "whiteboard.h"

WhiteBoard::WhiteBoard(QWidget *parent)
    : QWidget(parent), penColor(Qt::black), m_drawing(false)
{
    setAttribute(Qt::WA_StaticContents);
    setMinimumSize(800, 600); // Tamaño mínimo del WhiteBoard
    m_image = QImage(size(), QImage::Format_ARGB32);
    m_image.fill(Qt::white);
}

void WhiteBoard::setPenColor(const QColor &color)
{
    penColor = color;
}

void WhiteBoard::clear()
{
    m_image.fill(Qt::white);
    update();
}

void WhiteBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, m_image, dirtyRect);
}

void WhiteBoard::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastPoint = event->pos();
        m_drawing = true;
    }
}

void WhiteBoard::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && m_drawing) {
        drawLineTo(event->pos());
    }
}

void WhiteBoard::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_drawing) {
        drawLineTo(event->pos());
        m_drawing = false;
    }
}

void WhiteBoard::resizeEvent(QResizeEvent *event)
{
    if (width() > m_image.width() || height() > m_image.height()) {
        int newWidth = qMax(width(), m_image.width());
        int newHeight = qMax(height(), m_image.height());
        QImage newImage(QSize(newWidth, newHeight), QImage::Format_ARGB32);
        newImage.fill(Qt::white);

        QPainter painter(&newImage);
        painter.drawImage(QPoint(0, 0), m_image);
        m_image = newImage;
    }

    QWidget::resizeEvent(event);
}

void WhiteBoard::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&m_image);
    painter.setPen(QPen(penColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(m_lastPoint, endPoint);

    int rad = (2 / 2) + 2;
    update(QRect(m_lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    m_lastPoint = endPoint;
}
