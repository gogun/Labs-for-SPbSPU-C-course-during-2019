#ifndef CIRCLE_H
#define CIRCLE_H

#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape {
  public:
    Circle(double, point_t);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double, double) override;
    void move(point_t) override;
    double getRadius();
    point_t getPos();
    void showData();
  private:
    double radius_;
    point_t pos_;
};

#endif
