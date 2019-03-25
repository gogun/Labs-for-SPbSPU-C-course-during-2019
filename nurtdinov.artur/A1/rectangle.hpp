//
// Created by Артур on 18.03.2019.
//

#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape {
public:
  Rectangle(const point_t &point, const double &width, const double &height);

  point_t getPosition() const override;

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &point) override;

  void move(const double &dx, const double &dy) override;

private:
  double width_, height_;
  point_t position_;
};

#endif //A1_RECTANGLE_HPP
