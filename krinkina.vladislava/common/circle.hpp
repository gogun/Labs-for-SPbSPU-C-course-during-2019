#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace krinkina
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &centre, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &centre) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    double getRadius() const;
    void printInfo() const override;

  private:
    point_t centre_;
    double radius_;
  };
} 

#endif //CIRCLE_HPP
