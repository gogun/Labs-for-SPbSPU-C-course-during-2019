#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape {
public:
  Circle();
  Circle(point_t pos, double r);
  Circle(double x, double y, double r);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t point) override;

private:
  point_t center_;
  double radius_;
};
