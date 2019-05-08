#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  Circle mycircle(5.0, {3.0, 3.0});

  Rectangle myrectangle(mycircle.getFrameRect());

  Triangle mytriangle(point_t{1, 1}, point_t{1, 3}, point_t{3, 2});

  Shape * figures[] = {&mycircle, &myrectangle, &mytriangle};

  for (Shape * shape : figures)
  {
    shape->showParams();
    shape->move(5.0, 5.0);
    shape->showParams();
  }

  return 0;
}
