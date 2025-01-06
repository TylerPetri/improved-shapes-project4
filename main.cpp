
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ShapeList.h"
#include <iostream>

using namespace std;

std::string lowerCase(std::string s){
    std::string temp;
    for(auto c : s){
        temp += tolower(c);
    }
    return temp;
}

int main() {

    ShapeList<Circle> slc;
    ShapeList<Rectangle> slr;
    ShapeList<Triangle> slt;
    std::string shapeType;
    std::string shapeColor;
    double width = 0;
    double height = 0;
    double radius = 0;

    std::cout << "Welcome to the shape program" << std::endl;
    std::cout << "Please enter 'quit' for the shape/color when you wish to exit" << std::endl;

    do{
        std::cout << "Enter Shape Color:";
        std::cin >> shapeColor;
        if(lowerCase(shapeColor) == "quit")
            break;
        std::cout << "Please enter one of the following: Circle/Rectangle/Triangle" << std::endl;
        std::cout << "Enter Shape Type:";
        std::cin >> shapeType;
        if(lowerCase(shapeType) == "circle"){
            std::cout << "Enter radius of circle:";
            std::cin >> radius;
            slc.addShape(Circle(shapeColor, radius));
        }
        else if(lowerCase(shapeType) == "rectangle"){
            std::cout << "Enter width of rectangle:";
            std::cin >> width;
            std::cout << "Enter height of rectangle:";
            std::cin >> height;
            slr.addShape(Rectangle(shapeColor, width, height));
        }
        else if(lowerCase(shapeType) == "triangle"){
            std::cout << "Enter base of triangle:";
            std::cin >> width;
            std::cout << "Enter height of triangle:";
            std::cin >> height;
            slt.addShape(Triangle(shapeColor, width, height));
        }
        else{
            if(lowerCase(shapeType) != "quit")
                std::cout << "Invalid Shape Type.." << std::endl;
        }
    }while(lowerCase(shapeType) != "quit");

    Circle largestCircle = slc.getLargestShape();
    std::cout << "CIRCLE INFO:" << std::endl;
    slc.printList();
    std::cout << "LARGEST CIRCLE HAS AREA: " << largestCircle.area() << std::endl;
    std::cout << "\n\n";
    Rectangle largestRect = slr.getLargestShape();
    std::cout << "RECTANGLE INFO:" << std::endl;
    slr.printList();
    std::cout << "LARGEST RECTANGLE HAS AREA: " << largestRect.area() << std::endl;
    std::cout << "\n\n";
    Triangle largestTri = slt.getLargestShape();
    std::cout << "TRIANGLE INFO:" << std::endl;
    slt.printList();
    std::cout << "LARGEST TRIANGLE HAS AREA: " << largestTri.area() << std::endl;
    std::cout << "\n\n";

    if(largestCircle.isBiggerShape(largestTri) && largestRect.isBiggerShape(largestTri))
        std::cout << largestTri.type() << " with area " << largestTri.area() << " is the largest of all shapes!" << std::endl;
    else if(largestTri.isBiggerShape(largestCircle) && largestRect.isBiggerShape(largestCircle))
        std::cout << largestCircle.type() << " with area " << largestCircle.area() << " is the largest of all shapes!" << std::endl;
    else
        std::cout << largestRect.type() << " with area " << largestRect.area() << " is the largest of all shapes!" << std::endl;

    return 0;
}
