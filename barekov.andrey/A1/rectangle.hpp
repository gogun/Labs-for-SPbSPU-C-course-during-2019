#ifndef A1_RECTANGLE
#define A1_RECTANGLE

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(point_t pos, double width, double height);
  Rectangle(double x, double y, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getPos() const override;
  void move(const point_t& centre) override;
  void move(double mx, double my) override;

private:
  point_t centre_;
  double width_;
  double height_;
};

#endif
