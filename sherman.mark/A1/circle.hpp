#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP
#include "shape.hpp"
class Circle: public Shape
{
public:
  Circle (const double, const point_t &);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double, const double) override;
  void move(const point_t &) override;
  void printInformation() const override;
private:
  double radius_;
  point_t center_;
};
#endif //A1_CIRCLE_HPP
