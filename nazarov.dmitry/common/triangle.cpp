#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iostream>

nazarov::Triangle::Triangle(const point_t &A, const point_t &B, const point_t &C) :
  pos_({(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3}),
  point1_(A),
  point2_(B),
  point3_(C)
{
  if (((point1_.x == point2_.x) && (point1_.y == point2_.y)) || ((point2_.x == point3_.x)
    && (point2_.y == point3_.y)) || ((point1_.x == point3_.x) && (point1_.y == point3_.y)))
  {
    throw std::invalid_argument("Triangle points must not have the same coordinates");
  }
}

double nazarov::Triangle::getArea() const
{
  return (std::fabs(point1_.x - point3_.x) * (point2_.y - point3_.y)
    - std::fabs(point2_.x - point3_.x) * (point1_.y - point3_.y)) / 2;
}

nazarov::rectangle_t nazarov::Triangle::getFrameRect() const
{
  const double maxX = std::max(std::max(point1_.x, point2_.x), point3_.x);
  const double  minX = std::min(std::min(point1_.x, point2_.x), point3_.x);

  const double maxY = std::max(std::max(point1_.y, point2_.y), point3_.y);
  const double  minY = std::min(std::min(point1_.y, point2_.y), point3_.y);

  const double width = maxX - minX;
  const double height = maxY - minY;
  const point_t pos = {minX + width / 2, minY + height / 2};

  return {pos, width, height};
}

void nazarov::Triangle::move(const point_t &newPos)
{
  const double dx = newPos.x - pos_.x;
  const double dy = newPos.y - pos_.y;
  
  move(dx, dy);
}

void nazarov::Triangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;

  point1_.x += dx;
  point1_.y += dy;

  point2_.x += dx;
  point2_.y += dy;

  point3_.x += dx;
  point3_.y += dy;
}

void nazarov::Triangle::printFeatures() const
{
  rectangle_t framingRectangle = getFrameRect();
  std::cout << "Triangle point A is at position ( " << point1_.x << ';' << point1_.y << " )";
  std::cout << "\n point B is at position ( " << point2_.x << ';' << point2_.y << " )";
  std::cout << "\n point C is at position ( " << point3_.x << ';' << point3_.y << " )";
  std::cout << "\n Triangle centre is at position ( " << pos_.x << "," << pos_.y << " )";
  std::cout << "\n Triangle frame width is " << framingRectangle.width;
  std::cout << "\n Triangle frame height is " << framingRectangle.width;
  std::cout << "\n Triangle area is " << getArea() << "\n\n";
}

void nazarov::Triangle::scale(double times)
{
  if (times <= 0)
  {
    throw std::invalid_argument("'times' should be positive");
  }
  else
  {
    point1_ = {pos_.x + (point1_.x - pos_.x) * times, pos_.y + (point1_.y - pos_.y) * times};
    point2_ = {pos_.x + (point2_.x - pos_.x) * times, pos_.y + (point2_.y - pos_.y) * times};
    point3_ = {pos_.x + (point3_.x - pos_.x) * times, pos_.y + (point3_.y - pos_.y) * times};
  }
}
