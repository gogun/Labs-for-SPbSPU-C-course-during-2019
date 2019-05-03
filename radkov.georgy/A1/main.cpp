#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  Circle shape_0({1, 2}, 5);
  Shape *cir = &shape_0;

  cir->move({3, 4});
  cir->move(7, 6);

  Rectangle shape_1({1, 2}, 5, 8);
  Shape *rect = &shape_1;

  rect->move({2, 9});
  rect->move(13, 1);

  Triangle shape_2({0, 0}, {0, 3}, {4, 0});
  Shape *tri = &shape_2;

  tri->move({6, 11});
  tri->move(2, 5);

  Shape *shapes[3] = {cir, rect, tri};

  for (size_t i = 0; i < 3; ++i)
  {
    rectangle_t frame_rect = shapes[i]->getFrameRect();
    std::cout << "shape_" << i << " info" << std::endl
        << "position: {" << frame_rect.pos.x << ", " << frame_rect.pos.y << "}" << std::endl
        << "size: " << frame_rect.width << " x " << frame_rect.height << std::endl
        << "area: " << shapes[i]->getArea() << std::endl << std::endl;
  }

  return 0;
}
