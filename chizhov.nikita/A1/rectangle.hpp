#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape {
public:
  Rectangle();
  Rectangle(point_t pos, double w, double h);
  Rectangle(double x, double y, double w, double h);
  Rectangle(point_t pos, double a);
  Rectangle(double x, double y, double a);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t point) override;

private:
  point_t center_;
  double width_;
  double height_;
};
