#ifndef POLYMORPHISM1_TRIANGLE_H
#define POLYMORPHISM1_TRIANGLE_H

#include "Shape.h"
#include <math.h>
#include <iostream>

class Triangle : public Shape {
public:
    Triangle(std::string color, double base, double height) :
    Shape(color), _base(base), _height(height){};
    double area(){return (_base*_height)/2;}
    std::string type(){return "Traingle";}
    double perimeter(){return _base+_height+sqrt(pow(_base, 2)+pow(_height, 2));}
    template<class T>
    bool isBiggerShape(T shape){
        return this->area() < shape.area();
    }

private:
    double _base;
    double _height;

};


#endif
