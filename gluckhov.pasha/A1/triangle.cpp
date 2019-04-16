#include "triangle.hpp"
#include <cassert>
#include <iostream>

Triangle::Triangle(const point_t &vertexA, const point_t &vertexB, const point_t &vertexC):
  pos_({(vertexA.x + vertexB.x + vertexC.x) / 3}, {(vertexA.y + vertexB.y + vertexC.y) / 3}),
  vertexA_(vertexA),
  vertexB_(vertexB),
  vertexC_(vertexC)
{
  const double areaTriangle = getArea();
  assert(areaTriangle > 0.0);
}

double Triangle::getArea() const
{
  return ((vertexA_.x - vertexC_.x) * (vertexB_.y - vertexC_.y)
          - (vertexB_.x - vertexC_.x) * (vertexA_.y - vertexC_.y)) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  const maxX = std::max(std::max(vertexA_.x, vertexB_.x), vertexC_.x);
  const minX = std::min(std::min(vertexA_.x, vertexB_.x), vertexC_.x);

  const maxY = std::max(std::max(vertexA_.y, vertexB_.y), vertexC_.y);
  const minY = std::min(std::min(vertexA_.y, vertexB_.y), vertexC_.y);
  return {maxX - minX, maxY - minY, pos_};
}

void Triangle::printData() const
{
  std::cout << "A vertex of the triangle: (" << vertexA_.x << ";\b" << vertexA_.y << ')';
  std::cout << "\nB vertex of the triangle: (" << vertexB_.x << ";\b" << vertexB_.y << ')';
  std::cout << "\nC vertex of the triangle: (" << vertexC_.x << ";\b" << vertexC_.y << ')';
  std::cout << "\nPosition of the triangle: (" << pos_.x << ";\b" << pos_.y << ')';
}

void Triangle::move(double dx, double dy)
{
  const point_t point = {dx, dy};
  vertexA_ += point;
  vertexB_ += point;
  vertexC_ += point;
}

void Triangle::move(const point_t &newPos)
{
  const point_t difference = newPos - pos_;

  move(difference.x, difference.y);
}
