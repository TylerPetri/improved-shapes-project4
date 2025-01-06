#ifndef POLYMORPHISM1_CIRCLE_H
#define POLYMORPHISM1_CIRCLE_H

#include "Shape.h"
#include <cmath>
#include <iostream>

class Circle : public Shape {
public:
    Circle(std::string color, double radius) : Shape(color), _radius(radius){};
    double area(){return pow(M_PI*_radius, 2);}
    std::string type(){return "Circle";}
    double perimeter(){return 2*M_PI*_radius;}
    template<class T>
    bool isBiggerShape(T shape){
        return this->area() < shape.area();
    }

private:
    double _radius;
};


#endif
