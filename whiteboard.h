#ifndef WHITEBOARD_H
#define WHITEBOARD_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>

class WhiteBoard : public QWidget
{
    Q_OBJECT

public:
    explicit WhiteBoard(QWidget *parent = nullptr);
    void setPenColor(const QColor &color);
    void clear();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);

    QImage m_image;
    QColor penColor;
    QPoint m_lastPoint;
    bool m_drawing;
};

#endif // WHITEBOARD_H
