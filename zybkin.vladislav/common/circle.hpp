#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace zybkin
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &, double);

    double getArea() const;
    rectangle_t getFrameRect() const;
    void printInfo() const;
    void move(const point_t &);
    void move(double, double);
    void scale(double);

  private:
    double radius_;
    point_t center_;
  };
}

#endif /* CIRCLE_HPP */
