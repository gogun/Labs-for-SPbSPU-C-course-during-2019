#include "triangle.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

gusarov::Triangle::Triangle(const point_t & pointA, const point_t & pointB, const point_t & pointC):
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC)
{
  if (getArea() == 0.0)
  {
    throw std::invalid_argument("It is not a triangle");
  }
}

gusarov::point_t gusarov::Triangle::getCenter() const
{
  return {(pointA_.x + pointB_.x + pointC_.x) / 3, (pointA_.y + pointB_.y + pointC_.y) / 3};
}

double gusarov::Triangle::getArea() const
{
  point_t side1 = {pointB_.x - pointA_.x, pointB_.y - pointA_.y};
  point_t side2 = {pointC_.x - pointA_.x, pointC_.y - pointA_.y};

  return (fabs((side1.x * side2.y - side1.y * side2.x)) / 2);
}

gusarov::rectangle_t gusarov::Triangle::getFrameRect() const
{
  point_t max {std::max(pointA_.x, std::max(pointB_.x, pointC_.x)),
      std::max(pointA_.y, std::max(pointB_.y, pointC_.y))};
  point_t min {std::min(pointA_.x, std::min(pointB_.x, pointC_.x)),
      std::min(pointA_.y, std::min(pointB_.y, pointC_.y))};

  double width = max.x - min.x;
  double height = max.y - min.y;
  point_t pos = {width / 2 + min.x, height / 2 + min.y};

  return {width, height, pos};
}

void gusarov::Triangle::move(const double shiftX, const double shiftY)
{
  pointA_.x += shiftX;
  pointA_.y += shiftY;

  pointB_.x += shiftX;
  pointB_.y += shiftY;

  pointC_.x += shiftX;
  pointC_.y += shiftY;
}

void gusarov::Triangle::move(const point_t& point)
{
  point_t center = getCenter();
  move(point.x - center.x, point.y - center.y);
}
void gusarov::Triangle::scale(const double scale)
{
  if (scale <= 0)
  {
    throw std::invalid_argument("Invalid scale value");
  }
  point_t center = getCenter();
  pointA_.x = center.x * (1 - scale) + pointA_.x * scale;
  pointA_.y = center.y * (1 - scale) + pointA_.y * scale;

  pointB_.x = center.x * (1 - scale) + pointB_.x * scale;
  pointB_.y = center.y * (1 - scale) + pointB_.y * scale;

  pointC_.x = center.x * (1 - scale) + pointC_.x * scale;
  pointC_.y = center.y * (1 - scale) + pointC_.y * scale;
}

void gusarov::Triangle::printInfo() const
{
  std::cout << "Width of framed rectangle is " << getFrameRect().width << '\n';
  std::cout << "Height of framed rectangle is " << getFrameRect().height << '\n';
  std::cout << "Center of triangle is a point: (" << getCenter().x << ";" << getCenter().y << ")" << '\n';
  std::cout << "Angle of rotation is " << angle_ << '\n';
}

void gusarov::Triangle::rotate(double angle)
{
  const double cos = std::abs(std::cos(angle * M_PI / 180));
  const double sin = std::abs(std::sin(angle * M_PI / 180));
  const double Ax = (pointA_.x - center_.x) * cos - (pointA_.y - center_.y) * sin;
  const double Ay = (pointA_.x - center_.x) * sin + (pointA_.y - center_.y) * cos;
  const double Bx = (pointB_.x - center_.x) * cos - (pointB_.y - center_.y) * sin;
  const double By = (pointB_.x - center_.x) * sin + (pointB_.y - center_.y) * cos;
  const double Cx = (pointC_.x - center_.x) * cos - (pointC_.y - center_.y) * sin;
  const double Cy = (pointC_.x - center_.x) * sin + (pointC_.y - center_.y) * cos;
  pointA_.x = Ax + center_.x;
  pointA_.y = Ay + center_.y;
  pointB_.x = Bx + center_.x;
  pointB_.y = By + center_.y;
  pointC_.x = Cx + center_.x;
  pointC_.y = Cy + center_.y;
}
