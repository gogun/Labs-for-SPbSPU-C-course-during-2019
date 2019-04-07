#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.hpp"

namespace trofimov
{
 class Rectangle : public Shape
 {
 public:
   Rectangle(const point_t &pos, double w, double h);

   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void move(const point_t &point) override;
   void move(double dx, double dy) override;
   void getInfo() const override;
   void scale(double cScaling) override;
 private:
   rectangle_t rectangle_;
 };
}
#endif
