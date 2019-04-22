#include "triangle.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

sysoeva::Triangle::Triangle(point_t vertex1, point_t vertex2, point_t vertex3):
  vertex_1(vertex1),
  vertex_2(vertex2),
  vertex_3(vertex3),
  center_(getCenter())
{
  if ((vertex_1.x - vertex_2.x) * (vertex_3.y - vertex_2.y) == (vertex_1.y - vertex_2.y) * (vertex_3.x - vertex_2.x))
  {
    throw std::invalid_argument("Vertices lie on one line");
  }
}

sysoeva::point_t sysoeva::Triangle::getCenter() const
{
  return {(vertex_1.x + vertex_2.x + vertex_3.x) / 3, (vertex_1.y + vertex_2.y + vertex_3.y) / 3};
}

double getDistance(const sysoeva::point_t & vertex1, const sysoeva::point_t & vertex2)
{
  return sqrt(pow(vertex2.x - vertex1.x, 2) + pow(vertex2.y - vertex1.y, 2));
}

double sysoeva::Triangle::getArea() const
{
  double side_a = getDistance(vertex_1, vertex_2);
  double side_b = getDistance(vertex_2, vertex_3);
  double side_c = getDistance(vertex_3, vertex_1);
  double p = 0.5 * (side_a + side_b + side_c);
  return sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
}

sysoeva::rectangle_t sysoeva::Triangle::getFrameRect() const
{
  double min_x = std::min({vertex_1.x, vertex_2.x, vertex_3.x});
  double min_y = std::min({vertex_1.y, vertex_2.y, vertex_3.y});
  double max_x = std::max({vertex_1.x, vertex_2.x, vertex_3.x});
  double max_y = std::max({vertex_1.y, vertex_2.y, vertex_3.y});
  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t center = {min_x + (width / 2), min_y + (height / 2)};
  return {width, height, center};
}

void sysoeva::Triangle::move(const point_t & point)
{
  move(point.x - center_.x, point.y - center_.y);
}

void sysoeva::Triangle::move(double dx, double dy)
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

void sysoeva::Triangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient has invalid value");
  }
  point_t vector_1 = {(vertex_1.x - center_.x) * coefficient, (vertex_1.y - center_.y) * coefficient};
  point_t vector_2 = {(vertex_2.x - center_.x) * coefficient, (vertex_2.y - center_.y) * coefficient};
  point_t vector_3 = {(vertex_3.x - center_.x) * coefficient, (vertex_3.y - center_.y) * coefficient};
  vertex_1 = {center_.x + vector_1.x, center_.y + vector_1.y};
  vertex_2 = {center_.x + vector_2.x, center_.y + vector_2.y};
  vertex_3 = {center_.x + vector_3.x, center_.y + vector_3.y};
}

  void sysoeva::Triangle::showCoord()
{
  std::cout << "New coordinates of triangle: A(" << vertex_1.x << "," << vertex_1.y << ")";
  std::cout << " B(" << vertex_2.x << "," << vertex_2.y << ")";
  std::cout << " C(" << vertex_3.x << "," << vertex_3.y << ")" << '\n';
  std::cout << "Center O(" << center_.x << "," << center_.y << ")" << '\n';
}

void sysoeva::Triangle::printCenter()
{
  std::cout << "center (" << center_.x << "," << center_.y << ")" << '\n';
}
