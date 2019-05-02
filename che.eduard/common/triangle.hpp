#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace che
{
 class Triangle : public Shape
 {
 public:
   Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC);

   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void move(const point_t &pos) override;
   void move(double dx, double dy) override;
   void scale(double factor) override;
   void showInfo() const override;

 private:
   point_t centre_;
   point_t pointA_;
   point_t pointB_;
   point_t pointC_;
 };
}
#endif
