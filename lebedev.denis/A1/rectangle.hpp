#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(point_t pos, double widht, double height);
  
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double x, const double y) override;
  void move(point_t &new_poit) override;

private:
  double m_width;
  double m_height;
  point_t m_pos;
};
#endif
