#ifndef AVID_GRAPHIC_WIDGET_H
#define AVID_GRAPHIC_WIDGET_H

#include <QVBoxLayout>
#include <QVector>

#include "myopenglwidget.h"
#include "myvulkanwidget.h"


namespace Ui {
class AViD_Graphic_Widget;
}

class AViD_Graphic_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit AViD_Graphic_Widget(QWidget *parent = nullptr);
    explicit AViD_Graphic_Widget(VulkanWindow *vkW, QWidget *parent = nullptr);
    ~AViD_Graphic_Widget();

    QVBoxLayout* canvas;
    QVector<myOpenGLWidget> m_glWidgets;
    QVector<myVulkanWidget> m_vkWidgets;


    int getCol_x() const;
    void setCol_x(int value);

    int getCol_y() const;
    void setCol_y(int value);

    int getCol_z() const;
    void setCol_z(int value);

    int getColor() const;
    void setColor(int value);

protected:
    int col_x = 0;
    int col_y = 0;
    int col_z = 0;
    int color = 0;

private:
    Ui::AViD_Graphic_Widget *ui;
};


#endif // AVID_GRAPHIC_WIDGET_H
