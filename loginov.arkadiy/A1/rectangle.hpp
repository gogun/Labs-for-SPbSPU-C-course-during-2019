#ifndef SPBSPU_LABS_2019_RECTANGLE_HPP
#define SPBSPU_LABS_2019_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape {
public:
  Rectangle(const point_t &point, double width, double height);

  double  getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &point) override;

  double getWidth();
  double getHeight();
  point_t getPoint();

private:
  rectangle_t rectangle_;
};

#endif
