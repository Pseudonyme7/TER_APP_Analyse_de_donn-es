#ifndef AVID_SHAPE_H
#define AVID_SHAPE_H
#include "avid_point.h"

class AViD_Shape
{
public:
    AViD_Shape();

    virtual void shape_translate(int new_x, int new_y, int new_z) = 0;
    virtual void shape_rotate(float degree, int ax_x, int ax_y, int ax_z) = 0;
    virtual float shape_dist(AViD_Shape* a, AViD_Shape* b) = 0;

    virtual ~AViD_Shape();

private:

};

#endif // AVID_SHAPE_H
