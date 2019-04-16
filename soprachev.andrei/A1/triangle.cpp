//
// Created by Andrei Soprachev on 2019-04-01.
//

#include "triangle.hpp"
#include <cassert>
#include "math.h" //need for abs in getArea

point_t centerOfMassByPoints(const point_t &point0, const point_t &point1, const point_t &point2)
{
  return point_t
    {
      (point0.x + point1.x + point2.x) / 3,
      (point0.y + point1.y + point2.y) / 3,
    };
}

//треугольник по трём вершиам
Triangle::Triangle(const point_t &globalVertex0, const point_t &globalVertex1, const point_t &globalVertex2) :
  Shape(centerOfMassByPoints(globalVertex0, globalVertex1, globalVertex2)),
  vertex0_(Vector2(globalVertex0) - pos_),
  vertex1_(Vector2(globalVertex1) - pos_),
  vertex2_(Vector2(globalVertex2) - pos_)
{
  assert(getArea() > 0);
}

//объём через определитель матрицы
double Triangle::getArea() const
{
  double a = (vertex0_.x_ - vertex2_.x_) * (vertex1_.y_ - vertex2_.y_);
  double b = (vertex1_.x_ - vertex2_.x_) * (vertex0_.y_ - vertex2_.y_);
  double det = a - b;
  return abs(.5 * det);
}

rectangle_t Triangle::getFrameRect() const
{
  double left = std::min(vertex0_.x_, std::min(vertex1_.x_, vertex2_.x_));
  double right = std::max(vertex0_.x_, std::max(vertex1_.x_, vertex2_.x_));
  double down = std::min(vertex0_.y_, std::min(vertex1_.y_, vertex2_.y_));
  double up = std::max(vertex0_.y_, std::max(vertex1_.y_, vertex2_.y_));

  return rectangle_t
    {
      point_t
        {
          this->pos_.x_ + left + ((right - left) / 2),
          this->pos_.y_ + down + ((up - down) / 2)
        },
      right - left,
      up - down
    };
}

std::string Triangle::getName() const
{
  return "Triangle";
}
