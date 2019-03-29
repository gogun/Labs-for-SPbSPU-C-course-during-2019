#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle :
    public Shape {
public:

  Rectangle(point_t &new_pos, double width,
      double heigth);

  double getArea() const override;
  double getFrameRate() const override;
  void info() const override;
  void move(const point_t &new_pos) override;
  void move(const double dx, const double dy) override;

private:
  rectangle_t rectangle_;
};

#endif //RECTANGLE_HPP
