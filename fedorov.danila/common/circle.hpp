#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace fedorov
{
  class Circle :
      public Shape
  {
  public:
    Circle(const point_t &position, const double radius);

    rectangle_t getFrameRect() const override;
    double getArea() const override;
    double getRadius() const;

    void printInfo() const override;
    void scale(double scale) override;

  private:
    double radius_;
  };
}

#endif //CIRCLE_HPP
