#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double radius,const point_t &pos); // для pos используем ссылку, так как это - структура
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &pos) override; // смещение в заданную точку
  void move(const double x, const double y) override; // смещение по осям

private:
  double radius_;
  point_t pos_;
};

#endif // CIRCLE_HPP
