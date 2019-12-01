#ifndef AGW_FACTORY_H
#define AGW_FACTORY_H

#include "avid_graphic_widget.h"

class AGW_factory
{
public:
    static QWidget* create_agw();
    static void remove_agw(QWidget* w);

public slots:
    //Les colonnes à prendre en compte (Le QWidget sera cast en avid_graphic_widget)
    static void setXcol(QWidget* w, int x);
    static void setYcol(QWidget* w, int y);
    static void setZcol(QWidget* w, int Z);
    static void setColor(QWidget* w, int c);

    //Pas encore implémentés
    QWidget* create_scatterPlot();
    void remove_scatterPlot();
};

#endif // AGW_FACTORY_H
