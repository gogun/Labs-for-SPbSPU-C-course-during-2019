#include <iostream>
#include <cassert>

#include "rectangle.hpp"
#include "circle.hpp"

/* The following overloaded function "show" works with flows of data output */
void show(const point_t &center)
{
  std::cout << "The center of the circle is: (" << center.x << ";"
            << center.y << ")" << '\n';
}

void show(double x, double y)
{
  std::cout << "The center of the circle is: (" << x << ";"
            << y << ")" << '\n';
}

/*if radius is wanted then flag should be true,
if area is wanted then flag should be false.
It is used because of area and radius are of the same type
and the function "show" cannot be overloaded*/
void show(double shown, bool flag)
{
  assert(shown > 0.0);
  if (flag)
  {
    std::cout << "The radius of the circle is: " << shown << '\n';
  } else
  {
    std::cout << "The square is: " << shown << '\n';
  }
}

int main()
{
  Circle mycircle;
  mycircle.m_center = {5.0,5.0}; // initializing the center of the circle

  show(mycircle.m_center);

  mycircle.m_radius = 3.0; // the circle's radius

  show(mycircle.m_radius, true);

  Rectangle myrectangle;
  myrectangle.m_figure = mycircle.getFrameRect();
  // initializing the Rectangle object's field "m_figure" with circle's frame rectangle

  Shape * figures[] = {&mycircle, &myrectangle};
  int size = sizeof(figures)/sizeof(Shape);
  for (int i = 0; i < size; i++)
  {
    show(figures[i]->getArea(), false);
    // the second parameter is for body of the func "show"
  }

  mycircle.move({10.0, 10.0});

  show(mycircle.m_center.x, mycircle.m_center.y);

  return 0;
}
