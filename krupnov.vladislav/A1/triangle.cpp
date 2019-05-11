#include "triangle.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cmath>

const int QTY_VERTEX = 3;

Triangle::Triangle(const point_t &vertex1, const point_t &vertex2, const point_t &vertex3):
  vertices_({vertex1, vertex2, vertex3}),
  center_({(vertex1.x + vertex2.x + vertex3.x) / 3, (vertex1.y + vertex2.y + vertex3.y) / 3})
{
  if (getArea() <= 0.0) {
    throw std::invalid_argument("The specified triangle's tops is not valid.");
  }
}

void Triangle::printInfo() const
{
  std::cout << "\nTriangle";
  for (int index = 0; index < QTY_VERTEX; index++)
  {
    std::cout << "\nTops №" << index + 1 << " coordinates: " << vertices_[index].x << "; " << vertices_[index].y;
  }
  std::cout << "\nCenter: " << center_.x << "; " << center_.y;
}

double Triangle::getArea() const
{
  return (0.5 * (fabs(vertices_[0].x - vertices_[2].x) * (vertices_[1].y - vertices_[2].y)
            - fabs(vertices_[1].x - vertices_[2].x) * (vertices_[0].y - vertices_[2].y)));
}

rectangle_t Triangle::getFrameRect() const
{
  const double minX = std::min(std::min(vertices_[0].x, vertices_[1].x), vertices_[2].x);
  const double maxX = std::max(std::max(vertices_[0].x, vertices_[1].x), vertices_[2].x);
  const double minY = std::min(std::min(vertices_[0].y, vertices_[1].y), vertices_[2].y);
  const double maxY = std::max(std::max(vertices_[0].y, vertices_[1].y), vertices_[2].y);

  const double width = (maxX - minX);
  const double height = (maxY - minY);
  const point_t pos = {minX + width / 2, minY + height / 2};

  return {width, height, pos};
}

void Triangle::move(const point_t &newPos)
{
  const point_t offset = {newPos.x - center_.x, newPos.y - center_.y};

  move(offset.x, offset.y);
}

void Triangle::move(double dx, double dy)
{
  for (int index = 0; index < QTY_VERTEX; index++)
  {
    vertices_[index].x += dx;
    vertices_[index].y += dy;
  }

  center_.x += dx;
  center_.y += dy;
}
