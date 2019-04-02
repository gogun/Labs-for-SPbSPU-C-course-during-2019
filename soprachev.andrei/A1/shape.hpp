//
// Created by Andrei Soprachev on 2019-03-19.
//

#ifndef LAB1_SHAPE_HPP
#define LAB1_SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  Shape(const point_t &pos);

  virtual ~Shape() = default;

  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;

  virtual void move(double dx, double dy);

  virtual void move(const point_t &pos);

  const point_t &getPos() const;

protected:
  point_t pos;
};

#endif //LAB1_SHAPE_HPP
