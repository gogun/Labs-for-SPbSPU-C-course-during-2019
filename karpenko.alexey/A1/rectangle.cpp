#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const rectangle_t &rect) :
  rect_(rect)
{
<<<<<<< HEAD
  assert((rect.width > 0.0)&&(rect.height > 0.0));
=======
  assert((rect.width >= 0.0)&&(rect.height >= 0.0));
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
}

double Rectangle::getArea() const
{
<<<<<<< HEAD
  return rect_.width * rect_.height;
=======
  return (rect_.width * rect_.height);
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
}

rectangle_t Rectangle::getFrameRect() const
{
<<<<<<< HEAD
  return rect_;
=======
  return (rect_);
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
}

void Rectangle::move(const double dx, const double dy)
{
<<<<<<< HEAD
  rect_.pos.x += dx;
  rect_.pos.y += dy;
=======
  rect_.pos.x = dx;
  rect_.pos.y = dy;
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
}

void Rectangle::move(const point_t &newPos)
{
  rect_.pos = newPos;
}
