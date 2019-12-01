#include "myvulkanwidget.h"


myVulkanWidget::myVulkanWidget()
{
    vkWindow = new VulkanWindow();
}

myVulkanWidget::myVulkanWidget(VulkanWindow *vkW)
{
    vkWindow = vkW;
}

VulkanWindow *myVulkanWidget::getVkWindow() const
{
    return vkWindow;
}

void myVulkanWidget::setVkWindow(VulkanWindow *value)
{
    vkWindow = value;
}
