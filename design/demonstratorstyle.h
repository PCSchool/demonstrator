#ifndef DEMONSTRATORSTYLE_H
#define DEMONSTRATORSTYLE_H

#include<QWidget>
#include<QProxyStyle>
#include<qproxystyle.h>


class DemonstratorStyle : public QProxyStyle
{
    Q_OBJECT
public:
    DemonstratorStyle();

    void polish(QPalette &palette) override;
    void polish(QWidget *widget) override;
    void unpolish(QWidget *widget) override;
    int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const override;
    int styleHint(StyleHint hint, const QStyleOption *option, const QWidget *widget, QStyleHintReturn *returnData) const override;
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const override;
    void drawControl(ControlElement control, const QStyleOption *option, QPainter *painter, const QWidget *widget) const override;

private:
    static void setTexture(QPalette &palette, QPalette::ColorRole role, const QPixmap &pixmap);
    static QPainterPath roundRectPath(const QRect &react);


};

#endif // DEMONSTRATORSTYLE_H
