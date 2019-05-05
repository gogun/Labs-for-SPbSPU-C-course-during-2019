#include <iostream>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

using namespace radkov;

int main()
{
  try
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

    Shape *shapes[] = {cir, rect, tri};
    size_t i = 0;

    for (Shape *shape: shapes)
    {
      rectangle_t frame_rect = shape->getFrameRect();
      std::cout << "shape_" << i << " info" << std::endl
          << "position: {" << frame_rect.pos.x << ", " << frame_rect.pos.y << "}" << std::endl
          << "size: " << frame_rect.width << " x " << frame_rect.height << std::endl
          << "area: " << shape->getArea() << std::endl << std::endl;
      ++i;
    }
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}
