#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED
#include "shape.hpp"

namespace nazarov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &pos, const double &width, const double &height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printFeatures() const override;
    point_t getPos() const override;
    double getWidth() const;
    double getHeight() const;
    void scale(double times) override;
    void move(double dx, double dy) override;
    void move(const point_t &pos) override;

  private:
    point_t pos_;
    double width_, height_;
  };
};

#endif
