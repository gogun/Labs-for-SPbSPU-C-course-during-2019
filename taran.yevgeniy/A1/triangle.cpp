#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

Triangle::Triangle(const point_t& A, const point_t& B, const point_t& C):
  pos_({(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3}),
  point1_(A),
  point2_(B),
  point3_(C)
{
  if (((point1_.x == point2_.x) && (point1_.y == point2_.y)) || ((point2_.x == point3_.x)
    && (point2_.y == point3_.y)) || ((point1_.x == point3_.x) && (point1_.y == point3_.y)))
  {
    throw std::invalid_argument("Tochki treugol'nika ne dolzhny imet' odinakovyye koordinaty");
  }
}

double Triangle::getArea() const
{
  return (std::fabs(point1_.x - point3_.x) * (point2_.y - point3_.y)
    - std::fabs(point2_.x - point3_.x) * (point1_.y - point3_.y)) / 2;
}

rectangle_t Triangle::getFrameRect() const
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

void Triangle::move(const point_t & newPos)
{
  const double dx = newPos.x - pos_.x;
  const double dy = newPos.y - pos_.y;

  move(dx, dy);
}

void Triangle::move(double dx, double dy)
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

void Triangle::showParams() const
{
  rectangle_t framingRect = getFrameRect();
  std::cout << "Triangle: center - {" << framingRect.pos.x << ","
            << framingRect.pos.y << "}\nWidth - " << framingRect.width
            << "\nHeight - " << framingRect.height << '\n'
            << "Area - " << getArea() << '\n';
}
