#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "base-types.hpp"

int main()
{
  point_t point = {534, 348};

  Rectangle rectangle(300, 200, 500, 300);
  Shape * RC = &rectangle;
  RC->dataoutput();
  RC->move(40, 30);
  RC->move(point);
  RC->dataoutput();
  
  point = {765, 395};

  Circle circle(7, {30, 40});
  Shape * CR = &circle;
  CR->dataoutput();
  CR->move(-15, -70);
  CR->move(point);
  CR->dataoutput();

  return 0;
}
