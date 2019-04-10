#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace marashov {
  class Rectangle : public Shape {
  public:
    Rectangle(const point_t &pos, double width, double height);

    Rectangle(double posX, double posY, double width, double height);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t &pos) override;

    void move(double deltaX, double deltaY) override;

    void scale(double scaleAmount) override;

    void writeInfo() const override;

    point_t getCenter() const;

    double getWidth() const;

    double getHeight() const;

  private:
    point_t center_;
    double width_;
    double height_;
  };
}
#endif //RECTANGLE_HPP
