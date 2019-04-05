#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &, const double &, const double &);

  double printArea() const;
  rectangle_t printFrameRect() const;
  void printFeatures() const;

  void move(const double &, const double &);
  void move(const point_t &);

private:
  double m_width, m_height;
};

#endif // RECTANGLE_HPP_INCLUDED
