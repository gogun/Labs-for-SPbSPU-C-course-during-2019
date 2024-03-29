//
// Created by Andrei Soprachev on 2019-04-01.
//

#include "shape.hpp"
#include <cassert>

Shape::Shape(const point_t &pos) :
  pos_(Vector2(pos))
{}

Shape::Shape(const Vector2 &pos) :
  pos_(pos)
{}

void Shape::move(const point_t &pos)
{
  pos_ = Vector2(pos);
}

void Shape::move(double dx, double dy)
{
  pos_ += Vector2(dx, dy);
}

Shape::Vector2::Vector2(double x, double y) : x_(x), y_(y)
{}

Shape::Vector2::Vector2(const point_t &point) : x_(point.x), y_(point.y)
{}

Shape::Vector2 Shape::Vector2::operator+(const Vector2 &rhs) const
{
  return Vector2(x_ + rhs.x_, y_ + rhs.y_);
}

Shape::Vector2 Shape::Vector2::operator-(const Vector2 &rhs) const
{
  return Vector2(x_ - rhs.x_, y_ - rhs.y_);
}

Shape::Vector2 Shape::Vector2::Vector2::operator*(const double &rhs) const
{
  return Vector2{x_ * rhs, y_ * rhs};
}

Shape::Vector2 Shape::Vector2::Vector2::operator/(const double &rhs) const
{
  assert(rhs != 0);
  return Vector2{x_ / rhs, y_ / rhs};
}

Shape::Vector2 &Shape::Vector2::operator+=(const Vector2 &rhs)
{
  x_ += rhs.x_;
  y_ += rhs.y_;
  return *this;
}

Shape::Vector2 &Shape::Vector2::operator-=(const Vector2 &rhs)
{
  x_ -= rhs.x_;
  y_ -= rhs.y_;
  return *this;
}

Shape::Vector2 &Shape::Vector2::operator*=(const double &rhs)
{
  x_ *= rhs;
  y_ *= rhs;
  return *this;
}

Shape::Vector2 &Shape::Vector2::operator/=(const double &rhs)
{
  assert(rhs != 0);
  x_ /= rhs;
  y_ /= rhs;
  return *this;
}

point_t Shape::Vector2::getPoint() const
{
  return point_t{x_, y_};
}

