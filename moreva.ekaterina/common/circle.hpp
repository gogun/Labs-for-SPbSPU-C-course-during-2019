#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace moreva
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t & pos, double radius);
    Circle(double centerX, double centerY, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & pos) override;
    void move(double dX, double dY) override;
    void scale(double factor) override;
    point_t getCenter() const;
    double getRadius() const;
    void printInfo() const override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif // CIRCLE_HPP
