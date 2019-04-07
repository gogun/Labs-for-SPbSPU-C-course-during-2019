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

  point_t operator+(point_t rhs) const
  {
    return point_t{this->x + rhs.x, this->y + rhs.y};
  }

  point_t operator-(point_t rhs) const
  {
    return point_t{this->x - rhs.x, this->y - rhs.y};
  }

  point_t operator/(const double &rhs) const
  {
    assert(rhs != 0);
    return point_t{this->x / rhs, this->y / rhs};
  }

  point_t &operator+=(const point_t &rhs)
  {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
  }

  double magnitude() const;

};

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
};


#endif //LAB1_BASE_TYPES_HPP
