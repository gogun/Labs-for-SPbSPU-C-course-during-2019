#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle c({1,2.4},5); // Circle with centre at point [1,2.4] and radius 5
  Shape * shape = &c;

  double area = shape->getArea();
  rectangle_t framerect = shape->getFrameRect();

  std::cout<<"--------------------Circle--------------------\n";
  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n\n";

  shape->move(5,0.6);
  std::cout<<"Move 1.1:\n";

  area = shape->getArea();
  framerect = shape->getFrameRect();

  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n\n";

  shape->move({-3,-1});
  std::cout<<"Move 1.2:\n";

  area = shape->getArea();
  framerect = shape->getFrameRect();

  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n\n";

  Rectangle r({3,2},5,4); // Rectangle with centre at point [3,2], width 5 and heigh 4
  shape = &r;

  area = shape->getArea();
  framerect = shape->getFrameRect();

  std::cout<<"--------------------RECTANGLE--------------------\n";
  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n";

  shape->move(31.5,5);
  std::cout<<"Move 2.1:\n";

  area = shape->getArea();
  framerect = shape->getFrameRect();

  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n\n";

  shape->move({-11,2});
  std::cout<<"Move 2.2:\n";

  area = shape->getArea();
  framerect = shape->getFrameRect();

  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n\n";

  Rectangle s({3,2},11); // Rectangle with centre at point [3,2], width 5 and heigh 4
  shape = &s;

  area = shape->getArea();
  framerect = shape->getFrameRect();

  std::cout<<"--------------------SQUARE--------------------\n";
  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n";

  shape->move(0,0);
  std::cout<<"Move 2.1:\n";

  area = shape->getArea();
  framerect = shape->getFrameRect();

  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n\n";

  shape->move({0,0});
  std::cout<<"Move 2.2:\n";

  area = shape->getArea();
  framerect = shape->getFrameRect();

  std::cout<<"Area is "<<area<<";\nCentre is ["<<framerect.pos.x<<","<<framerect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<framerect.width<<", height is "<<framerect.height<<";\n";
  return 0;
}
