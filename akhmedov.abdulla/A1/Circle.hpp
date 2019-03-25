#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape
{
  public:
    Circle();
    Circle(point_t pos, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double dx, double dy) override;
    void getInfo() const override;

  private:
    point_t pos_;
    double radius_;
};

#endif
