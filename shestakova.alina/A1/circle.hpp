#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(point_t pos, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(double dx, double dy) override;

private:
  point_t pos_;
  double radius_;
};
