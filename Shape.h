#ifndef POLYMORPHISM1_SHAPE_H
#define POLYMORPHISM1_SHAPE_H

#include <iostream>

class Shape {
public:
    Shape(std::string color) : _color(color){};
    void setColor(std::string color){ _color=color;}
    std::string getColor(){return _color;}
    virtual double area() = 0; //{ return 0;}
    virtual double perimeter() = 0;
    virtual std::string type() = 0; //{return "shape";}

protected:
    std::string _color;

};


#endif
