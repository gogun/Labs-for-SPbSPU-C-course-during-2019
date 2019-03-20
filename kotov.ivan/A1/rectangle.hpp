#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle:
  public Shape
{
  
public:

  Rectangle(const point_t &pos, const double width, const double height);
  
  double getArea() const override;
  
  rectangle_t getFrameRect() const override;
  
  void move(const point_t &pos) override;
  
  void move(const double dispX, const double dispY) override;
  
private:

  point_t m_pos;
  
  double m_width;
  
  double m_height;
  
};

#endif // RECTANGLE_HPP
