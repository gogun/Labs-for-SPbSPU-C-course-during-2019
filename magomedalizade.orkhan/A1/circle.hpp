#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, const double radius_);
  double getArea();
  const rectangle_t getFrameRect();
  void move(const point_t &NewCentre);
  void move(const double dx, const double dy);
  void print();
private:
  double radius_;
};
