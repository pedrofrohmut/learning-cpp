#include "Shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle: public Shape
{
    public:
        Circle(double width);
        Circle();

        virtual ~Circle();

        double Area() override;

    private:

};

#endif // CIRCLE_H
