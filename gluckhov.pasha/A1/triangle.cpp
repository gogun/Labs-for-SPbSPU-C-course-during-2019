#include "triangle.hpp"
#include <math.h>
#include <cassert>
#include <iostream>

Triangle::Triangle(const point_t &vertexA, const point_t &vertexB, const point_t &vertexC):
  pos_({(vertexA.x + vertexB.x + vertexC.x) / 3, (vertexA.y + vertexB.y + vertexC.y) / 3}),
  vertexA_(vertexA),
  vertexB_(vertexB),
  vertexC_(vertexC)
{
  const double areaTriangle = getArea();
  assert(areaTriangle > 0.0);
}

double Triangle::getArea() const
{
  return (std::fabs(vertexA_.x - vertexC_.x) * (vertexB_.y - vertexC_.y)
          - std::fabs(vertexB_.x - vertexC_.x) * (vertexA_.y - vertexC_.y)) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  const double maxX = std::max(std::max(vertexA_.x, vertexB_.x), vertexC_.x);
  const double minX = std::min(std::min(vertexA_.x, vertexB_.x), vertexC_.x);

  const double maxY = std::max(std::max(vertexA_.y, vertexB_.y), vertexC_.y);
  const double minY = std::min(std::min(vertexA_.y, vertexB_.y), vertexC_.y);
  
  const double width = maxX - minX;
  const double height = maxY - minY;
  const point_t position = {minX + width / 2, minY + height / 2};
  
  return {width, height, position};
}

void Triangle::printData() const
{
  std::cout << "A vertex of the triangle: (" << vertexA_.x << ';' << vertexA_.y << ')';
  std::cout << "\nB vertex of the triangle: (" << vertexB_.x << ';' << vertexB_.y << ')';
  std::cout << "\nC vertex of the triangle: (" << vertexC_.x << ';' << vertexC_.y << ')';
  std::cout << "\nPosition of the triangle: (" << pos_.x << ';' << pos_.y << ')';
}

void Triangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;

  vertexA_.x += dx;
  vertexA_.y += dy;

  vertexB_.x += dx;
  vertexB_.y += dy;

  vertexC_.x += dx;
  vertexC_.y += dy;
}

void Triangle::move(const point_t &newPos)
{
  const point_t difference = {newPos.x - pos_.x, newPos.y - pos_.y};

  move(difference.x, difference.y);
}
