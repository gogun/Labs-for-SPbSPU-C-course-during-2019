#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &pos, const double width, const double height);
  double getArea();
  const rectangle_t getFrameRect();
  void move(const point_t &NewCentre);
  void move(const double dx, const double dy);
  void print();
private:
  double width_;
  double height_;
};
