#ifndef CIRCLE_H
#define CIRCLE_H
#include <Shape.hpp>

class Circle : public Shape
{
public:
  Circle(double r, const point_t& Center);
  void print() const override;
  double getArea() const override;
  void move(const point_t& move) override;
  void move(double dx, double dy) override;
  rectangle_t getFrameRect() const override;
private:
  double r_;
  point_t center_;
};

#endif
