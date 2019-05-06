#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle:
    public Shape {
public:
  Circle(double radius, const point_t &center);
  void printInfo() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &newPos) override;
  void move(double dx, double dy) override;
private:
  double radius_;
  point_t center_;
};
#endif //CIRCLE_HPP
