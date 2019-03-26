#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

int main()
{
    Circle cir({12, 12}, 12);
    Rectangle rectang(34, 56, 23, 15);
    cir.printInf();
    rectang.printInf();
    cir.move({45, 67});
    rectang.move(23,45);
    rectangle_t rect;
    rect = cir.getFrameRect();
    std::cout << "Center of circle: (" << rect.position.x << ';'
      <<  rect.position.y << ')' << std::endl;
    rect = rectang.getFrameRect();
    std::cout << "Center of rectangle: (" << rect.position.x << ';'
      <<  rect.position.y << ')' << std::endl;
}