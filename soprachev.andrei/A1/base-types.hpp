//
// Created by Andrei Soprachev on 2019-03-19.
//

#ifndef LAB1_BASE_TYPES_HPP
#define LAB1_BASE_TYPES_HPP

#include "cassert"
#include <ostream>
#include "math.h"

//равносильно вектору тк по заданию определена операция сложения
struct point_t
{
  double x;
  double y;
  std::string toString() const;
  double magnitude() const;

  friend point_t operator+(const point_t &lhs, const point_t &rhs)
  {
    return point_t{lhs.x + rhs.x, lhs.y + rhs.y};
  }

  friend point_t operator-(const point_t &lhs, const point_t &rhs)
  {
    return point_t{lhs.x - rhs.x, lhs.y - rhs.y};
  }

  friend point_t operator/(const point_t &lhs, const double &rhs)
  {
    assert(rhs != 0);
    return point_t{lhs.x / rhs, lhs.y / rhs};
  }

  point_t &operator+=(const point_t &rhs)
  {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
  }

};

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
};


#endif //LAB1_BASE_TYPES_HPP
