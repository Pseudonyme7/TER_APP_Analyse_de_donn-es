#include "ui_avid_graphic_widget.h"
#include "avid_graphic_widget.h"

AViD_Graphic_Widget::AViD_Graphic_Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::AViD_Graphic_Widget)
{
    ui->setupUi(this);

    if(parent != nullptr)
    {
        setMaximumSize(parent->size());
    }
    myOpenGLWidget * tmp = new myOpenGLWidget();
    //myVulkanWidget *vkmp = new myVulkanWidget(vkW);

    canvas = new QVBoxLayout(this);
    canvas->addWidget(tmp);
    //QWidget *container = QWidget::createWindowContainer((QWindow*)vkmp);
    //canvas->addWidget(container);
}

AViD_Graphic_Widget::AViD_Graphic_Widget(VulkanWindow *vkW, QWidget *parent):
    QWidget(parent),
    ui(new Ui::AViD_Graphic_Widget)
{
    ui->setupUi(this);

    if(parent != nullptr)
    {
        setMaximumSize(parent->size());
    }
    myOpenGLWidget * tmp = new myOpenGLWidget();
    //myVulkanWidget *vkmp = new myVulkanWidget(vkW);

    canvas = new QVBoxLayout(this);
    canvas->addWidget(tmp);
    //QWidget *container = QWidget::createWindowContainer((QWindow*)vkmp);
    //canvas->addWidget(container);
}

AViD_Graphic_Widget::~AViD_Graphic_Widget()
{
    delete ui;
}

int AViD_Graphic_Widget::getCol_x() const
{
    return col_x;
}

void AViD_Graphic_Widget::setCol_x(int value)
{
    col_x = value;
}

int AViD_Graphic_Widget::getCol_y() const
{
    return col_y;
}

void AViD_Graphic_Widget::setCol_y(int value)
{
    col_y = value;
}

int AViD_Graphic_Widget::getCol_z() const
{
    return col_z;
}

void AViD_Graphic_Widget::setCol_z(int value)
{
    col_z = value;
}

int AViD_Graphic_Widget::getColor() const
{
    return color;
}

void AViD_Graphic_Widget::setColor(int value)
{
    color = value;
}
