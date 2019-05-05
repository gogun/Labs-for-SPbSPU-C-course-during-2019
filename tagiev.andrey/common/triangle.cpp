#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <cstdlib>

tagiev::Triangle::Triangle(const tagiev::point_t &pointA, const tagiev::point_t &pointB, const tagiev::point_t &pointC) :
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC),
  center_({(pointA.x + pointB.x + pointC.x) / 3, (pointA.y + pointB.y + pointC.y) / 3})
{
  if (((pointA_.x == pointB_.x) && (pointA_.y == pointB_.y)) || ((pointA_.x == pointC_.x) && (pointA_.y == pointC_.y))
        || ((pointB_.x == pointC_.x) && (pointB_.y == pointC_.y)))
  {
    throw std::invalid_argument("Degenerate triangle");
  }
}

tagiev::rectangle_t tagiev::Triangle::getFrameRect() const
{
  const double maxX = std::fmax(std::fmax(pointA_.x, pointB_.x), pointC_.x);
  const double minX = std::fmin(std::fmin(pointA_.x, pointB_.x), pointC_.x);
  const double maxY = std::fmax(std::fmax(pointA_.y, pointB_.y), pointC_.y);
  const double minY = std::fmin(std::fmin(pointA_.y, pointB_.y), pointC_.y);
  return {maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2}};
}

double tagiev::Triangle::getArea() const
{
  return (fabs((pointB_.x - pointA_.x) * (pointC_.y - pointA_.y) - (pointC_.x - pointA_.x) * (pointB_.y - pointA_.y)) / 2);
}

void tagiev::Triangle::move(const tagiev::point_t &newPoint)
{
  const double dx = newPoint.x - center_.x;
  const double dy = newPoint.y - center_.y;

  move(dx, dy);

  center_ = newPoint;
}

void tagiev::Triangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;

  pointA_.x += dx;
  pointA_.y += dy;

  pointB_.x += dx;
  pointB_.y += dy;

  pointC_.x += dx;
  pointC_.y += dy;
}

void tagiev::Triangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("K <= 0");
  }
  pointA_.x = center_.x * (1 - k) + pointA_.x * k;
  pointA_.y = center_.y * (1 - k) + pointA_.y * k;
  pointB_.x = center_.x * (1 - k) + pointB_.x * k;
  pointB_.y = center_.y * (1 - k) + pointB_.y * k;
  pointC_.x = center_.x * (1 - k) + pointC_.x * k;
  pointC_.y = center_.y * (1 - k) + pointC_.y * k;
}
