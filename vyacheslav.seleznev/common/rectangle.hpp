#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace seleznev
{
  class Rectangle : public Shape
  {
    public:
      Rectangle(double width, double height, point_t pos);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void scale(double coefficient) override;
      double getHeight();
      double getWidth();

    private:
      double width_;
      double height_;
  };
}

#endif
