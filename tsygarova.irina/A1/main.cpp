#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
    Rectangle rectangle({4, 2, {1, 3}});
    Shape * shapePtr = &rectangle;
    std::cout << "FOR RECTANGLE\n";
    shapePtr -> print();
    std::cout << "1) Moving along Оx " << 4 << " and Oy " << 7 << std::endl;
    shapePtr -> move(4, 7);
    shapePtr -> print();
    std::cout << "2) Moving to the point (" << 8 << "; " << 6 << ")\n";
    shapePtr -> move({8, 6});
    shapePtr -> print();
    std::cout << std::endl;

    Circle circle(6, {2, 3});
    shapePtr = &circle;
    std::cout << "FOR CIRCLE\n";
    shapePtr -> print();
    std::cout << "1) Moving along Оx " << 5 << " and Oy " << 9 << std::endl;
    shapePtr -> move(5, 9);
    shapePtr -> print();
    std::cout << "2) Moving to the point (" << 9 << "; " << 3 << ")\n";
    shapePtr -> move({9, 3});
    shapePtr -> print();
  return 0;
}
