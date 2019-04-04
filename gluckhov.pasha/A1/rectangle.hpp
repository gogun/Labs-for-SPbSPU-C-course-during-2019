#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double width, double height, point_t pos = {0.0, 0.0});
  double void getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  voit move(point newPos);
protected:
  double width_;
  double height_;
  point_t pos_;
};
