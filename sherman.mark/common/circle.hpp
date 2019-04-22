#ifndef COMMON_CIRCLE_HPP
#define COMMON_CIRCLE_HPP
#include "shape.hpp"

namespace sherman
{
  class Circle : public Shape
  {
  public:
    Circle(double, const point_t &);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double, double) override;
    void move(const point_t &) override;
    void scale (double) override;
    void printInformation() const override;
  private:
    double radius_;
    point_t center_;
  };
}

#endif
