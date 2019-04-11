#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace tolstikov {

  class Circle : public Shape {
  public:
    Circle(point_t centre, double radius);

    double getArea() const override;
    double getRadius() const;

    rectangle_t getFrameRect() const override;

    void scale(double scaleFactor) override;
    void move(point_t point) override;
    void move(double dx, double dy) override;

  private:
    point_t centre_;
    double radius_;
  };

}

#endif
