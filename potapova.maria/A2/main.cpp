#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  potapova::Circle circle({5,7},3);
  potapova::Shape *shape = &circle;
  std::cout << "Area: " << shape->getArea() << std::endl;
  shape->move(3,4);
  potapova::rectangle_t rect = shape->getFrameRect();
  std::cout << "FrameRect: " << '\n'
    << "  width - " << rect.width << '\n'
    << "  height - " << rect.height << '\n'
    << "  center - " << rect.pos.x << " , " << rect.pos.y << std::endl;

  shape->move({1,3});
  shape->scale(2);
  potapova::rectangle_t rect_ = shape->getFrameRect();
  std::cout << "New center: " << rect_.pos.x<< " , " << rect_.pos.y << '\n'
    << " New area - " << shape->getArea() << std::endl;

  potapova::Rectangle rectangle({{9,2}, 3, 8});
  shape = &rectangle;
  std::cout << "Area: " << shape->getArea() << std::endl;
  shape->move(7,1);
  potapova::rectangle_t rectan = shape->getFrameRect();
  std::cout << "FrameRect: " << '\n'
    << "  height - " << rectan.height << '\n'
    << "  width - " << rectan.width << '\n'
    << "  center - " << rectan.pos.x << " , " << rectan.pos.y <<std::endl;

  shape->move({4,2});
  shape->scale(3);
  potapova::rectangle_t rectan_ = shape->getFrameRect();
  std::cout << "New center - " << rectan_.pos.x << " , " << rectan_.pos.y
    << " New area - " << shape->getArea() <<std::endl;
  return 0;
}
