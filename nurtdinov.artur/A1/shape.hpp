//
// Created by Артур on 18.03.2019.
//

#ifndef A1_SHAPE_HPP
#define A1_SHAPE_HPP

#include "base-types.hpp"

class Shape {
public:

  virtual ~Shape() = default;

  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;

  virtual void move(const point_t &point) = 0;

  virtual void move(const double &dx, const double &dy) = 0;
};

#endif //A1_SHAPE_HPP
