#ifndef CN_A2_RECTANGLE
#define CN_A2_RECTANGLE

#include "shape.hpp"
#include "base-types.hpp"

namespace chizhov {
  class Rectangle : public Shape {
  public:
    Rectangle(point_t, double, double);
    Rectangle(double, double, double, double);
    Rectangle(point_t, double);
    Rectangle(double, double, double);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double, double) override;
    void move(point_t) override;
    void scale(double) override;

  private:
    point_t center_;
    double width_;
    double height_;
  };
}
#endif
