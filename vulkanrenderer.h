#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#include <QVulkanWindow>
#include <QVulkanWindowRenderer>
#include <QWidget>
#include <QObject>
#include <QtGlobal>
#include <QVulkanDeviceFunctions>


//! [0]
class VulkanRenderer : public QVulkanWindowRenderer
{
public:
    VulkanRenderer(QVulkanWindow *w);

    void initResources() override;
    void initSwapChainResources() override;
    void releaseSwapChainResources() override;
    void releaseResources() override;

    void startNextFrame() override;

private:
    QVulkanWindow *m_window;
    QVulkanDeviceFunctions *m_devFuncs;
    float m_green = 0;
};

class VulkanWindow : public QVulkanWindow
{
public:
    QVulkanWindowRenderer *createRenderer() override;
};
//! [0]


#endif // VULKANRENDERER_H
