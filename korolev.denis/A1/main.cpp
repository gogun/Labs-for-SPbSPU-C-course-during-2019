#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

void movePoint(Shape &shape, const point_t &position)
{
  std::cout << "Move to point: {" << position.x << ";"
    << position.y << "}" << std::endl;
  shape.move(position);
  std::cout << "Parameters of shape after move: " << std::endl;
  shape.printInf();
}

void moveXY(Shape &shape, double dx, double dy)
{
    std::cout << "Move to X: " << dx << ", Y: " << dy << std::endl;
    shape.move(dx, dy);
    std::cout << "Parameters of shape after move: " << std::endl;
    shape.printInf();
}

int main()
{
    Circle cir({12, 12}, 12);
    cir.printInf();
    // Move to point{23,45}
    movePoint(cir, {23,45});
    // Move to x = 45, y = 12
    moveXY(cir, 45, 12);

    Rectangle rect(12, 34, 23 , 56);
    rect.printInf();
    // Move to point{67,78}
    movePoint(rect, {67, 78});
    // Move to x = 17, y = 34
    moveXY(rect, 17,34);

    // Square around circle
    rectangle_t rec = cir.getFrameRect();
    Rectangle rect2({rec.pos.x, rec.pos.y}, rec.width, rec.height );
    rect2.printInf();
    
    return 0;
}

