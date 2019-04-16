#include "triangle.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

Triangle::Triangle(point_t vertex1, point_t vertex2, point_t vertex3):
  vertex_1(vertex1),
  vertex_2(vertex2),
  vertex_3(vertex3)
{
  assert((vertex_1.x - vertex_2.x)/(vertex_3.y - vertex_2.y) != (vertex_1.y - vertex_2.y)/(vertex_3.x - vertex_2.x));
  center_ = getCenter();
}

point_t Triangle::getCenter() const
{
  return {(vertex_1.x + vertex_2.x + vertex_3.x)/3, (vertex_1.y + vertex_2.y + vertex_3.y)/3};
}

double Triangle::getArea() const
{
  double side_a = sqrt(pow(vertex_2.x - vertex_1.x, 2) + pow(vertex_2.y - vertex_1.y, 2));
  double side_b = sqrt(pow(vertex_3.x - vertex_2.x, 2) + pow(vertex_3.y - vertex_2.y, 2));
  double side_c = sqrt(pow(vertex_1.x - vertex_3.x, 2) + pow(vertex_1.y - vertex_3.y, 2));
  double p = 0.5 * (side_a + side_b + side_c);
  return sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
}

rectangle_t Triangle::getFrameRect() const
{
  double width = std::max(std::max(vertex_1.x, vertex_2.x), vertex_3.x)
    - std::min(std::min(vertex_1.x, vertex_2.x), vertex_3.x);
  double height = std::max(std::max(vertex_1.y, vertex_2.y), vertex_3.y)
    - std::min(std::min(vertex_1.y, vertex_2.y), vertex_3.y);
  point_t center = {std::min(std::min(vertex_1.x, vertex_2.x), vertex_3.x) + (width/2),
                   std::min(std::min(vertex_1.y, vertex_2.y), vertex_3.y) + (height/2)};
  return {width, height, center};
}

void Triangle::move(const point_t & point)
{
  double dx = center_.x - point.x;
  double dy = center_.y - point.y;
  center_ = point;
  vertex_1.x -= dx;
  vertex_2.x -= dx;
  vertex_3.x -= dx;
  vertex_1.y -= dy;
  vertex_2.y -= dy;
  vertex_3.y -= dy;
}

void Triangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  vertex_1.x += dx;
  vertex_2.x += dx;
  vertex_3.x += dx;
  vertex_1.y += dy;
  vertex_2.y += dy;
  vertex_3.y += dy;
}

void Triangle::showCoord()
{
  std::cout << "New coordinates of triangle: A(" << vertex_1.x << "," << vertex_1.y << ")";
  std::cout << " B(" << vertex_2.x << "," << vertex_2.y << ")";
  std::cout << " C(" << vertex_3.x << "," << vertex_3.y << ")" << '\n';
  std::cout << "Center O(" << center_.x << "," << center_.y << ")" << '\n';
}

void Triangle::printCenter()
{
  double x = center_.x;
  double y = center_.y;
  std::cout << "center (" << x << "," << y << ")" << '\n';
}
