#ifndef AVID_CIRCLE_H
#define AVID_CIRCLE_H

#include "avid_shape.h"

class AViD_Circle : AViD_Shape
{
public:
    AViD_Circle(AViD_Point* center, float radius);

    AViD_Point center;
    float radius;
};

#endif // AVID_CIRCLE_H
