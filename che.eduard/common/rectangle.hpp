#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace che
{
 class Rectangle : public Shape
 {
 public:
   Rectangle(const rectangle_t & rect);

   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void move(const point_t & point) override;
   void move(double dx, double dy) override;
   void scale(double coef) override;
 private:
   rectangle_t rectangle_;
 };
}
#endif 
