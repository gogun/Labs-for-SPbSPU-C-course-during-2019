#ifndef RECTANGLE_HPP_1
#define RECTANGLE_HPP_1

#include "shape.hpp"

namespace stotskaya
{
  class Rectangle : public Shape {
  public:
    Rectangle(const point_t& center, double width, double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double ratio) override;
  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif // RECTANGLE_HPP_1
