#ifndef POLYMORPHISM1_RECTANGLE_H
#define POLYMORPHISM1_RECTANGLE_H

#include "Shape.h"
#include <iostream>

class Rectangle : public Shape {
public:
    Rectangle(std::string color, double width, double height) :
    Shape(color), _width(width), _height(height){};
    double area(){ return _width*_height;}
    std::string type(){return "Rectangle";}
    double perimeter(){return 2*(_width+_height);}
    template<class T>
    bool isBiggerShape(T shape){
        return this->area() < shape.area();
    }


private:
    double _width;
    double _height;
};


#endif
