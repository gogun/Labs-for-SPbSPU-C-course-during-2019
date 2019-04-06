#include "shape.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

Circle::Circle (double Rcircle, point_t cpoint):
  cR(Rcircle),
  pos(cpoint)
{
  if (cR <= 0)
  throw std::invalid_argument("radius of circle <= 0");
}

double Circle::getArea() const
{
  return M_PI*cR*cR;
}

rectangle_t Circle::getFrameRect() const
{
  return {cR,cR,pos.x,pos.y};
}

void Circle::move(const double mX,const double mY)
{
  pos.x += mX;
  pos.y += mY;
}

void Circle::move(const point_t point)
{
  pos.x = point.x;
  pos.y = point.y;
}

void Circle::dataoutput() const
{
  std::cout << "area_of_circle_=" << getArea() << std::endl;
  std::cout << "framerect_width_height_X_Y_=" << getFrameRect().width << " " << getFrameRect().height << " ";
  std::cout << getFrameRect().pos.x << " " << getFrameRect().pos.y << std::endl;
  std::cout << "position_X_Y_" << pos.x << " " << pos.y << std::endl;
}
