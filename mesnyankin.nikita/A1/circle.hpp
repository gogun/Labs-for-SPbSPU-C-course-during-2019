#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

class Circle: public Shape {
  public:
    Circle(const double &radius, const point_t &pos);
    Circle(const double &radius, const double &posx, const double &posy);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double &x, const double &y) override;
    void move(const point_t &point) override;

    double getRadius() const;
    point_t getPos() const;

  private:
    double radius_;
    point_t pos_;
};

#endif
