#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace drozdov
{
  class Circle: public Shape
  {
    public:
      Circle (double radius, const point_t &pos);

      void printData() const override;
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void scale(double factor) override;
      double getRadius() const;

      void move (double dx, double dy) override;
      void move (const point_t &dot) override;
    private:
      double radius_;
      point_t pos_;
  };
}
#endif
