#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle mycircle(5.0, {3.0, 3.0}); // sozdat' ob"yekt klassa Circle

  Rectangle myrectangle(mycircle.getFrameRect()); // sozdat' ob"yekt klassa Rectangle

  Shape * figures[] = {&mycircle, &myrectangle};
  int size = sizeof(figures)/sizeof(Shape);

  for (Shape * shape : figures)
  {
    shape->showParams();
  }

  for (Shape * shape : figures)
  {
    shape->move(5.0, 5.0);
    shape->showParams();
  }

  return 0;
}
