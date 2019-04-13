#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace afanasiev
{

class Rectangle: public Shape
{
public:
  Rectangle(const point_t &position, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(const point_t &newPosition) override;
  void move(double dx, double dy) override;
  void scale(double zoomFactor) override;

private:
  point_t position_;
  double width_;
  double height_;
};

} //namespace afanasiev

#endif //RECTANGLE_HPP
