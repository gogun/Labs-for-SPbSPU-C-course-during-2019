#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

Triangle::Triangle(const point_t &vertexA, const point_t &vertexB, const point_t &vertexC):
  vertexA_(vertexA),
  vertexB_(vertexB),
  vertexC_(vertexC),
  center_ {(vertexA.x + vertexB.x + vertexC.x) / 3 , (vertexA.y + vertexB.y + vertexC.y) / 3}
{
  assert((vertexA_.x != vertexB_.x) || ((vertexA_.x != vertexC_.x) && (vertexA_.y != vertexB_.y)));
  assert((vertexA_.x != vertexC_.x) || ((vertexA_.y != vertexB_.y) && (vertexA_.y != vertexC_.y)));
  assert((vertexB_.x != vertexC_.x) || (vertexB_.y != vertexC_.y));
}

double Triangle::getArea() const
{
  return (std::fabs((vertexA_.x - vertexC_.x) * (vertexB_.y - vertexC_.y)
      - (vertexB_.x - vertexC_.x) * (vertexA_.y - vertexC_.y)) / 2);
}

void Triangle::printInfo() const
{
  std::cout << "Center = " << center_.x << ";" << center_.y << " vertexA = " << vertexA_.x << ";" << vertexA_.y
      << " vertexB = " << vertexB_.x << ";" << vertexB_.y << " vertexC = " << vertexC_.x << ";" << vertexC_.y << "\n";
}

rectangle_t Triangle::getFrameRect() const
{
  const double maxX = std::max({vertexA_.x, vertexB_.x, vertexC_.x});
  const double minX = std::min({vertexA_.x, vertexB_.x, vertexC_.x});
  const double width = maxX - minX;
  const double maxY = std::max({vertexA_.y, vertexB_.y, vertexC_.y});
  const double minY = std::min({vertexA_.y, vertexB_.y, vertexC_.y});
  const double height = maxY - minY;
  const point_t centerRect = {(minX + width) / 2, (minY + height) / 2};

  std::cout << "Center = " << centerRect.x << ";" << centerRect.y;
  return {height, width};
}

void Triangle::move(const point_t &newCenter)
{
  double dx = newCenter.x - center_.x;
  double dy = newCenter.y - center_.y;

  center_ = newCenter;

  vertexA_.x += dx;
  vertexA_.y += dy;

  vertexB_.x += dx;
  vertexB_.y += dy;

  vertexC_.x += dx;
  vertexC_.y += dy;
}

void Triangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;

  vertexA_.x += dx;
  vertexA_.y += dy;

  vertexB_.x += dx;
  vertexB_.y += dy;

  vertexC_.x += dx;
  vertexC_.y += dy;
}
