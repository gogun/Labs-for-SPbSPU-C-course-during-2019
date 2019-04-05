#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &, const double &);

  double printArea() const;
  rectangle_t printFrameRect() const;
  void printFeatures() const;

  void move(const double &, const double &);
  void move(const point_t &);

private:
  double m_radius;
};

#endif // CIRCLE_HPP
