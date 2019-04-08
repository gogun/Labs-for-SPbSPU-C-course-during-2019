#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t &center, const double width, const double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &goal) override;
  void move(double dx, double dy) override;
  void show() const override;

private:
  rectangle_t rect_;
};

#endif /* Rectangle_hpp */
