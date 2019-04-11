#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "shape.hpp"

class Circle:public Shape {
public:
  Circle(const point_t, double); //Constructor: centre of circle and radius
  Circle(double, double, double); //Constructor by coordinates and radius

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t) override;
  void move(double, double) override;

  void print() const override;
  point_t getPosition() const;
  double getRadius() const;

private:
  point_t circCentre_;
  double radius_;
};
#endif //A1_CIRCLE_HPP
