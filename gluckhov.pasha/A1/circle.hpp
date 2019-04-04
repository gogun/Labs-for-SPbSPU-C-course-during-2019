#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(double radius_, point_t pos = {0.0, 0.0});
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void displayData() const override;
  void move(double dx, double dy) override;
  void move(point_t newPos);
protected:
  double radius_;
  point_t pos_;
};
