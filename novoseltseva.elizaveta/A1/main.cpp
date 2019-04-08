#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Circle mycircle(5.0, { 3.0, 3.0 });

  Rectangle myrectangle(mycircle.getFrameRect());

  Shape* figures[] = { &mycircle, &myrectangle };
  int size = sizeof(figures) / sizeof(Shape);

  for (int i = 0; i < size; i++)
  {
    figures[i]->showParams();
  }

  for (int i = 0; i < size; i++)
  {
    figures[i]->move(5.0, 5.0);
    figures[i]->showParams();
  }

  return 0;
}
