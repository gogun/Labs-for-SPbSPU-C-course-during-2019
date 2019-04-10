#ifndef A2_CIRCLE
#define A2_CIRCLE

#include "shape.hpp"
#include "base-types.hpp"

namespace barekov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t& pos, double radius);
    Circle(double x, double y, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getPos() const override;
    void showScalableParameters() const override;
    void move(const point_t& centre) override;
    void move(double deltaX, double deltaY) override;
    void scale(double scaleFactor) override;

  private:
    point_t centre_;
    double radius_;
  };
}

#endif
