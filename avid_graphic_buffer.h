#ifndef AVID_GRAPHIC_BUFFER_H
#define AVID_GRAPHIC_BUFFER_H

#include "avid_shape.h"

class AViD_Graphic_Buffer
{
public:
    AViD_Graphic_Buffer();
    QVector<float> toBuffer(AViD_Shape &shape, QVector<float> color);
};

#endif // AVID_GRAPHIC_BUFFER_H
