#ifndef CircleHPP_A2
#define CircleHPP_A2

#include "shape.hpp"

namespace lukina
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t &newPoint) override;
    void scale(double coefficient) override;
    void printInfo() const override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif
