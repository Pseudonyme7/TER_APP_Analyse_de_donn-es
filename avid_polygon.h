#ifndef AVID_POLYGON_H
#define AVID_POLYGON_H

#include <QVector>
#include "avid_shape.h"

class AViD_Polygon : AViD_Shape
{
public:
    AViD_Polygon();
    QVector<AViD_Point> points;
};

#endif // AVID_POLYGON_H
