#include <vector>
#include <iostream>


template<class T>
ShapeList<T>::ShapeList() : _shapeList(std::vector<T>()) {}

template<class T>
void ShapeList<T>::addShape(T s) {
    _shapeList.push_back(s);
}

template<class T>
void ShapeList<T>::printList() {
    for(auto s : _shapeList){
        std::cout << s.getColor() << " " << s.type() << " AREA: " << s.area() << ", PER: " << s.perimeter() << std::endl;
    }
}

template<class T>
T ShapeList<T>::getLargestShape() {
    int largestIdx = 0;
    for(int i = 0; i < _shapeList.size(); i++){
        if(_shapeList[i].area() > _shapeList[largestIdx].area())
            largestIdx = i;
    }
    return _shapeList[largestIdx];
}
