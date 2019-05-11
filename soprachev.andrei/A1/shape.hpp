//
// Created by Andrei Soprachev on 2019-03-19.
//

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "base-types.hpp"

class Shape
{
public:
  Shape(const point_t &pos);
  virtual ~Shape() = default;
  virtual std::string getName() const = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double dx, double dy);
  virtual void move(const point_t &pos);

protected:
  class Vector2
  {
  public:
    double x_;
    double y_;
    Vector2(double x, double y);
    Vector2(const point_t &point);
    Vector2 operator+(const Vector2 &rhs) const;
    Vector2 operator-(const Vector2 &rhs) const;
    Vector2 operator*(const double &rhs) const;
    Vector2 operator/(const double &rhs) const;
    Vector2 &operator+=(const Vector2 &rhs);
    Vector2 &operator-=(const Vector2 &rhs);
    Vector2 &operator*=(const double &rhs);
    Vector2 &operator/=(const double &rhs);
    point_t getPoint() const;
  };

  Shape(const Vector2 &pos);
  Vector2 pos_;
};

#endif //SHAPE_HPP
