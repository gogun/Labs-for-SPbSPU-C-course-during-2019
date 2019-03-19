#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle final : public Shape {
public:
  Circle(const point_t &pos, const double radius);
  Circle();
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void writeInfo() const override;
  void move(const point_t &pos) override;
  void move(const double dx, const double dy) override;
private:
  point_t pos_;
  double radius_;
};
#endif
