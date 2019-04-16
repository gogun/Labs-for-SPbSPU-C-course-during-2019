#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace lebedev
{
  class Circle: public Shape
  {
    public:
      Circle(double radius, const point_t &pos);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const double x, const double y) override;
      void move(const point_t &new_point) override;
      void scale(const double multiplier) override;

    private:
      double m_radius;
      point_t m_pos;
  };
}
#endif
