#ifndef CN_A2_CIRCLE
#define CN_A2_CIRCLE

#include "shape.hpp"

namespace chizhov
{
  class Circle : public Shape {
  public:
    Circle(point_t, double);
    Circle(double, double, double);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double, double) override;
    void move(point_t) override;
    void scale(double) override;

  private:
    point_t center_;
    double radius_;
  };
}
#endif
