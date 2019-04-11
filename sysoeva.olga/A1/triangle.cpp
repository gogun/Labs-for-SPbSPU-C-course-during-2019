#include "triangle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Triangle::Triangle(point_t vertex1, point_t vertex2, point_t vertex3):
  vertex_1(vertex1),
  vertex_2(vertex2),
  vertex_3(vertex3)

{
  assert ((getDistance(vertex_1, vertex_2) + getDistance(vertex_2, vertex_3)) > getDistance(vertex_3, vertex_1));
  assert ((getDistance(vertex_2, vertex_3) + getDistance(vertex_3, vertex_1)) > getDistance(vertex_1, vertex_2));
  assert ((getDistance(vertex_3, vertex_1) + getDistance(vertex_1, vertex_2)) > getDistance(vertex_2, vertex_3));
  center_ = getCenter();
}

point_t Triangle::getCenter() const
{
  return {(vertex_1.x + vertex_2.x + vertex_3.x)/3, (vertex_1.y + vertex_2.y + vertex_3.y)/3};
}

double Triangle::getDistance(point_t point1, point_t point2) const
{
  return sqrt(((point2.x - point1.x) * (point2.x - point1.x)) + ((point2.y - point1.y) * (point2.y - point1.y)));
}

double Triangle::getArea() const
{
  double side_a = sqrt((vertex_2.x - vertex_1.x)*(vertex_2.x - vertex_1.x)
    + (vertex_2.y - vertex_1.y)*(vertex_2.y - vertex_1.y));
  double side_b = sqrt((vertex_3.x - vertex_2.x)*(vertex_3.x - vertex_2.x)
    + (vertex_3.y - vertex_2.y)*(vertex_3.y - vertex_2.y));
  double side_c = sqrt((vertex_1.x - vertex_3.x)*(vertex_1.x - vertex_3.x)
    + (vertex_1.y - vertex_3.y)*(vertex_1.y - vertex_3.y));
  double p = 0.5 * (side_a + side_b + side_c);
  return sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
}

double Triangle::getMinTop(double point1, double point2, double point3) const
{
  return (point1 < point2) ? point1 : ((point1 < point3) ? point1 : ((point2 < point3) ? point2 : point3));
}

double Triangle::getMaxTop(double point1, double point2, double point3) const
{
  return (point1 > point2) ? point1 : ((point1 > point3) ? point1 : ((point2 > point3) ? point2 : point3));
}

rectangle_t Triangle::getFrameRect() const
{
  double width = getMaxTop(vertex_1.x, vertex_2.x, vertex_3.x) - getMinTop(vertex_1.x, vertex_2.x, vertex_3.x);
  double height = getMaxTop(vertex_1.y, vertex_2.y, vertex_3.y) - getMinTop(vertex_1.y, vertex_2.y, vertex_3.y);
  double center_x = getMinTop(vertex_1.x, vertex_2.x, vertex_3.x) + (width/2);
  double center_y = getMinTop(vertex_1.y, vertex_2.y, vertex_3.y) + (height/2);
  return {width, height, {center_x, center_y}};
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
  std::cout << "center (" << x << " , " << y << ")" << '\n';
}
