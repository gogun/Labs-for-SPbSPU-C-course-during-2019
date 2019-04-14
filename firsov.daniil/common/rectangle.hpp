#ifndef A2_RECTANGLE_HPP
#define A2_RECTANGLE_HPP
#include "shape.hpp"

namespace firsov
{
  class Rectangle : public Shape {
  public:
    Rectangle(double width, double height, const point_t position);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double multiplier) override;
    void printShapeInfo() const override;

  private:
    double width_;
    double height_;
    point_t pos_;
	};
}
#endif
