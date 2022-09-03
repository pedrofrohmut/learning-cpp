#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
    protected:
        double height;
        double width;

    public:
        // Static Attribute
        static int numOfShapes;

        // Constructors
        Shape(double length);
        Shape(double height, double width);
        Shape();

        // Deconstructor: called every time a object is not needed
        virtual ~Shape();

        // Getters and Setters
        void SetHeight(double height);
        double GetHeight();
        void SetWidth(double width);
        double GetWidth();
        static int GetNumOfShapes();

        // Mark with virtual so it has to be overridden
        virtual double Area();

    private:

};

#endif // SHAPE_H
