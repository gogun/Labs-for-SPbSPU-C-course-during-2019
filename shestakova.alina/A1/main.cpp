#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
    Rectangle rect({10, -2}, 8, 3);
    Shape * shape = &rect;
    std::cout << "Created rectangle's parameters:\n";
    shape->printInfo();
    std::cout << "\nRectangle with a new centre at (4, 3):\n";
    rect.move({4, 3});
    shape->printInfo();
    std::cout << "\nRectangle shifted with dx=11, dy=0.9:\n";
    rect.move(11, 0.9);
    shape->printInfo();

    Circle circ({0.9, 2.3}, 3);
    shape =&circ;
    std::cout << "\nCreated circle's parameters:\n";
    shape->printInfo();
    std::cout << "\nCircle with a new centre at (12, 11):\n";
    shape->move({12, 11});
    shape->printInfo();
    std::cout << "\nCircle shifted with dx=2.3, dy=4:\n";
    shape->move(2.3, 4);
    shape->printInfo();

    return 0;
}
