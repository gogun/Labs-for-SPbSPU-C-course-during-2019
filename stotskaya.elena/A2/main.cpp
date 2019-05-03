#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  stotskaya::Rectangle rect1({1.0, 2.0}, 20.0, 10.0);
  rect1.move(3.5, -2.0);
  stotskaya::rectangle_t frame1 = rect1.getFrameRect();
  std::cout << "rect1 frame position: " << frame1.pos.x << ", " << frame1.pos.y << "\n";
  stotskaya::Shape* shapeP = &rect1;
  std::cout << "rect1 area: " << shapeP->getArea() << "\n";
  stotskaya::Circle circle1({1.0, 2.5}, 4.0);
  shapeP = &circle1;
  stotskaya::rectangle_t frame2 = shapeP->getFrameRect();
  std::cout << "circle1 frame size: " << frame2.width << "*" << frame2.height << "\n";
  shapeP->move({3.2, 3.4});
  frame2 = circle1.getFrameRect();
  std::cout << "circle1 frame position: " << frame2.pos.x << ", " << frame2.pos.y << "\n";
  std::cout << "circle1 area: " << circle1.getArea() << "\n";
  rect1.scale(3.0);
  std::cout << "rect1 area: " << rect1.getArea() << "\n";
  circle1.scale(0.4);
  std::cout << "circle1 area: " << circle1.getArea();
  return 0;
}
