#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace marashov {
  class Circle: public Shape {
  public:
    Circle(const point_t &center, double radius);

    Circle(double centerX, double centerY, double radius);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t &pos) override;

    void move(double dltX, double dltY) override;

    void scale(double scaleAmount) override;

    void writeInfo() const override;

    point_t getCenter() const;

    double getRadius() const;

  private:
    point_t center_;
    double radius_;
  };
}

#endif //CIRCLE_HPP
