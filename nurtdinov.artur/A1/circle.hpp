//
// Created by Артур on 18.03.2019.
//

#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &point, double radius);

  point_t getCenter() const override;

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &point) override;

  void move(double dx, double dy) override;

private:
  point_t position_;
  double radius_;
};


#endif //A1_CIRCLE_HPP
