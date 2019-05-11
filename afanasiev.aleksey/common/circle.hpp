#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace afanasiev
{

class Circle: public Shape
{
public:
  Circle(const point_t &position, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(const point_t &newPosition) override;
  void move(double dx, double dy) override;
  void scale(double zoomFactor) override;

private:
  point_t position_;
  double radius_;
};

} //namespace afanasiev

#endif //CIRCLE_HPP
