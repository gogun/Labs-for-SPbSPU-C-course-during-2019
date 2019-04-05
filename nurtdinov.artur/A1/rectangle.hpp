//
// Created by Артур on 18.03.2019.
//

#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &point, double width, double height);

  point_t getCenter() const override;

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &point) override;

  void move(double dx, double dy) override;

private:
  double width_;
  double height_;
  point_t position_;
};

#endif //A1_RECTANGLE_HPP
