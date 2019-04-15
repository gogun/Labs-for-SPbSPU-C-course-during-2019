#include "triangle.hpp"
#include <cassert>
#include <iostream>
#include <cmath>
#include <algorithm>


Triangle::Triangle(const point_t & point1, const point_t & point2, const point_t & point3) :
  p1_(point1),
  p2_(point2),
  p3_(point3)
{
  double area = getArea();

  assert((area != 0.0) && ("The area of triangle is zero, it means the points are collinear"));

  center_.x = (p1_.x + p2_.x + p3_.x) / 3;
  center_.y = (p1_.y + p2_.y + p3_.y) / 3;
}

double Triangle::getArea() const
{
  double area = (std::abs((p1_.x * (p2_.y - p3_.y)) + (p2_.x * (p3_.y - p1_.y)) + (p3_.x * (p1_.y - p2_.y)))) / 2;
  return area;
}

rectangle_t Triangle::getFrameRect() const
{
  double min_x = std::min(std::min(p1_.x, p2_.x), p3_.x);
  double max_x = std::max(std::max(p1_.x, p2_.x), p3_.x);
  double min_y = std::min(std::min(p1_.y, p2_.y), p3_.y);
  double max_y = std::max(std::max(p1_.y, p2_.y), p3_.y);

  rectangle_t rect;
  rect.width = max_x - min_x;
  rect.height = max_y - min_y;
  rect.pos.x = min_x + (rect.width / 2);
  rect.pos.y = min_y + (rect.height / 2);

  return rect;
}

void Triangle::move(const point_t & pos)
{
  double dx = pos.x - p1_.x;
  double dy = pos.y - p1_.y;

  move(dx, dy);
}

void Triangle::move(const double &x, const double &y)
{
  p1_.x += x;
  p1_.y += y;

  p2_.x += x;
  p2_.y += y;

  p3_.x += x;
  p3_.y += y;

  center_.x += x;
  center_.y += y;
}

void Triangle::printInfo() const
{
  std::cout << "Triangle: " << std::endl;
  std::cout << "point 1: " << "x: " << p1_.x << " y: " << p1_.y << std::endl;
  std::cout << "point 2: " << "x: " << p2_.x << " y: " << p2_.y << std::endl;
  std::cout << "point 3: " << "x: " << p3_.x << " y: " << p3_.y << std::endl;
}

void Triangle::getCenterInfo() const
{
  std::cout << "Center X: " << center_.x << "Center Y: " << center_.y;
}
