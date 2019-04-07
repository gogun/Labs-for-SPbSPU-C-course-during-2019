#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &centre, const double &radius);
  void setRadius(const double &radius);
  double getRadius() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &to_position) override;
  void move(const double &dx, const double &dy) override;
  void printShapeInfo() const override;
private:
  double radius_;
};
#endif
