#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{

public:

  Circle(const point_t & pos, double radius);
  
  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &pos) override;

  void move(double dispX, double dispY) override;

private:

  point_t m_center_;

  double m_radius_;

};

#endif // CIRCLE_HPP
