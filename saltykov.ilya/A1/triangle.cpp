#include "triangle.hpp"

#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t& pointA, const point_t& pointB, const point_t& pointC) :
  centre_({(pointA.x + pointB.x + pointC.x) / 3, (pointA.y + pointB.y + pointC.y) / 3}),
//a + 2/3m = a + 2/3 ((b + c)/2-a) = a + 1/3(b + c) - 2/3a = 1/3(a + b + c)
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC)
{
  assert(abs((pointB.x - pointA.x) / (pointB.y - pointA.y)
      - (pointC.x - pointA.x) / (pointC.y - pointA.y)) > 0.0000000001);
//points should not lie on the same line
}

double Triangle::getArea() const
{
  return abs((pointB_.x - pointA_.x) * (pointC_.y - pointA_.y)
      - (pointC_.x - pointA_.x) * (pointB_.y - pointA_.y)) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  double max_x = fmax(fmax(pointA_.x, pointB_.x), pointC_.x);
  double min_x = fmin(fmin(pointA_.x, pointB_.x), pointC_.x);
  double max_y = fmax(fmax(pointA_.y, pointB_.y), pointC_.y);
  double min_y = fmin(fmin(pointA_.y, pointB_.y), pointC_.y);
  return {max_x - min_x, max_y - min_y, {(max_x + min_x) / 2, (max_y + min_y) / 2}};
}

point_t Triangle::getPos() const
{
  return centre_;
}

void Triangle::move(const point_t& centre)
{
  centre_ = centre;
}

void Triangle::move(double deltaX, double deltaY)
{
  centre_.x += deltaX;
  centre_.y += deltaY;
}
