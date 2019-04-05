#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
<<<<<<< HEAD

=======
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const rectangle_t &rect);
<<<<<<< HEAD
  
=======
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t &newPos) override;

private:
  rectangle_t rect_;
};
#endif
