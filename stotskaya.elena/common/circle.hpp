#ifndef CIRCLE_HPP_1
#define CIRCLE_HPP_1

#include "shape.hpp"

namespace stotskaya
{
  class Circle : public Shape {
  public:
    Circle(const point_t& center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double ratio) override;
  private:
    point_t center_;
    double radius_;
};
}

#endif // CIRCLE_HPP_1
