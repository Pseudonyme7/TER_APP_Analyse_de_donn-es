#include "agw_factory.h"


QWidget* AGW_factory::create_agw()
{
    return dynamic_cast<QWidget*>(new AViD_Graphic_Widget());
}

void AGW_factory::remove_agw(QWidget *w)
{
    delete w;
    w = nullptr;
}

void AGW_factory::setXcol(QWidget* w, int x)
{
    qDebug("Colonne X changée\n");
}

void AGW_factory::setYcol(QWidget* w, int y)
{
    qDebug("Colonne Y changée\n");
}

void AGW_factory::setZcol(QWidget* w, int Z)
{
    qDebug("Colonne Z changée\n");
}

void AGW_factory::setColor(QWidget* w, int c)
{
    qDebug("Couleur changée\n");
}
