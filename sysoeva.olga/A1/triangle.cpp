#include "triangle.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

Triangle::Triangle(point_t vertex1, point_t vertex2, point_t vertex3):
  vertex_1(vertex1),
  vertex_2(vertex2),
  vertex_3(vertex3),
  center_(getCenter())
{
  assert((vertex_1.x - vertex_2.x) * (vertex_3.y - vertex_2.y) != (vertex_1.y - vertex_2.y) * (vertex_3.x - vertex_2.x));
}

point_t Triangle::getCenter() const
{
  return {(vertex_1.x + vertex_2.x + vertex_3.x) / 3, (vertex_1.y + vertex_2.y + vertex_3.y) / 3};
}

double getVector(const point_t & vertex1, const point_t & vertex2)
{
  return sqrt(pow(vertex2.x - vertex1.x, 2) + pow(vertex2.y - vertex1.y, 2));
}

double Triangle::getArea() const
{
  double side_a = getVector(vertex_1, vertex_2);
  double side_b = getVector(vertex_2, vertex_3);
  double side_c = getVector(vertex_3, vertex_1);
  double p = 0.5 * (side_a + side_b + side_c);
  return sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
}

rectangle_t Triangle::getFrameRect() const
{
  double min_x = std::min({vertex_1.x, vertex_2.x, vertex_3.x});
  double min_y = std::min({vertex_1.y, vertex_2.y, vertex_3.y});
  double max_x = std::max({vertex_1.x, vertex_2.x, vertex_3.x});
  double max_y = std::max({vertex_1.y, vertex_2.y, vertex_3.y});
  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t center = {min_x + (width/2), min_y + (height/2)};
  return {width, height, center};
}

void Triangle::move(const point_t & point)
{
  move(point.x - center_.x, point.y - center_.y);
}

void Triangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  vertex_1.x += dx;
  vertex_1.y += dy;
  vertex_2.x += dx;
  vertex_2.y += dy;
  vertex_3.x += dx;
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
  std::cout << "center (" << center_.x << "," << center_.y << ")" << '\n';
}
