#include "shape.hpp"

class Circle: public Shape
{
public:
  Rectangle(double radius_, point_t pos = {0.0, 0.0});
  double void getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  voit move(point newPos);
protected:
  double radius_;
  point_t pos_;
};
