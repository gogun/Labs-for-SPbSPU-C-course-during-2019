#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printRect (Shape &Shape)
{
    rectangle_t trngl = Shape.getFrameRect();
    std::cout << trngl.width << " " << trngl.height;
    std::cout << " " << "(" << trngl.pos.x << "," <<trngl.pos.y << ")" << std::endl;
}

int main ()
{
    std::cout << "Rectangle" << std::endl;
    Rectangle rect (6,9,{3,4});
    printRect (rect);
    double s = rect.getArea();
    std::cout << s << std::endl;
    point_t pnt = {2,1};
    rect.move(pnt);
    printRect (rect);
    rect.move(2,8);
    printRect (rect);
    //создаем круг
    std::cout << "Circle" << std::endl;
    Circle circ ({5,5},4);
    printRect (circ);
    s = circ.getArea();
    std::cout << s << std::endl;
    circ.move({1,1});
    printRect (circ);
    circ.move(2,8);
    printRect (circ);
    std::cout << "dg" << std::endl;
    return 0;
};
