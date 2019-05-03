#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

krasnopyorov::Rectangle::Rectangle(rectangle_t characteristics):
  characteristics_(characteristics)
{
  if (characteristics_.height <= 0)
  {
    throw std::invalid_argument("Incorrect height value");
  }

  if (characteristics_.width <= 0)
  {
    throw std::invalid_argument("Incorrect width value");
  }
}

double krasnopyorov::Rectangle::getArea() const
{
  return characteristics_.width * characteristics_.height;
}

double krasnopyorov::Rectangle::getHeight() const
{
  return characteristics_.height;
}

double krasnopyorov::Rectangle::getWidth() const
{
  return characteristics_.width;
}

krasnopyorov::rectangle_t krasnopyorov::Rectangle::getFrameRect() const
{
  return characteristics_;
}

void krasnopyorov::Rectangle::move(const point_t &dot)
{
  characteristics_.pos = dot;
}

void krasnopyorov::Rectangle::move(double deltax, double deltay)
{
  characteristics_.pos.x += deltax;
  characteristics_.pos.y += deltay;
}

void krasnopyorov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Inccorect scaling coefficient");
  }
  characteristics_.width *= k;
  characteristics_.height *= k;
}

void krasnopyorov::Rectangle::writeChanges() const
{
  std::cout << "New coordinates of the centre (" << characteristics_.pos.x << ","
      << characteristics_.pos.y << ")" << "\n";
}
