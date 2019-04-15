#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace fedorov
{
  class Shape
  {
  public:
    Shape(const point_t &position);
    virtual ~Shape() = default;

    virtual rectangle_t getFrameRect() const = 0;
    virtual double getArea() const = 0;

    virtual void printInfo() const;
    virtual void scale(double) = 0;
    void move(const point_t &point);
    void move(const double dx, const double dy);

  protected:
    point_t position_;
  };
}

#endif //SHAPE_HPP
