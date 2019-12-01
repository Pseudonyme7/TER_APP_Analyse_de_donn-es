#ifndef MYVULKANWIDGET_H
#define MYVULKANWIDGET_H

#include <QLoggingCategory>

#include "vulkanrenderer.h"

class myVulkanWidget : QWindow
{
public:
    myVulkanWidget();
    myVulkanWidget(VulkanWindow *vkW);

    VulkanWindow *getVkWindow() const;
    void setVkWindow(VulkanWindow *value);

private:
    VulkanWindow* vkWindow;
};


#endif // MYVULKANWIDGET_H
