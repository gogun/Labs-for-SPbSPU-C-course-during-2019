#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace lebedev
{
  class Rectangle : public Shape
  {
    public:
	  Rectangle(double height, double widht, const point_t &pos);

	  double getArea() const override;
	  rectangle_t getFrameRect() const override;
	  void move(const double x, const double y) override;
	  void move(const point_t &new_point) override;
	  void scale(const double multiplier) override;

    private:
	  double m_height;
	  double m_width;
	  point_t m_pos;
  };
}
#endif
