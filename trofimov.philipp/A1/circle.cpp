#ifndef CIRCLE_H
#define CIRCLE_H
#include "circle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h> 

Circle::Circle(const point_t &pos, double r) :
  radius_(r),
  center_(pos)
{
  assert(radius_ >= 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ *radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { center_,radius_,radius_ };
}

void  Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;

}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::getInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Rectangle height = " << rectangle.height << std::endl;
  std::cout << "Rectangle width = " << rectangle.width << std::endl;
  std::cout << "Point x = " << rectangle.pos.x << std::endl;
  std::cout << "Point y = " << rectangle.pos.y << std::endl;
}
#endif
