#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace vlasenko
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &, const double &);

    double getArea() const;
    rectangle_t getFrameRect() const;
    void printInfo() const;
    void move(const point_t & position);
    void move(const double &, const double &);
    void scale(double );

  private:
    double radius_;
    point_t center_;
  };
}

#endif
