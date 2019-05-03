#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "shape.hpp"

namespace nurtdinov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &point, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double ratio) override;

  private:
    point_t position_;
    double radius_;
  };
}

#endif //A1_CIRCLE_HPP
