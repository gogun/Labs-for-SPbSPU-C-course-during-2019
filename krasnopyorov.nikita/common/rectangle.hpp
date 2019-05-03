#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"


namespace krasnopyorov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(rectangle_t characteristics);
    void move(const point_t &dot) override;
    void move(double deltax, double deltay) override;
    void scale(double k) override;
    double getArea() const override;
    double getHeight() const;
    double getWidth() const;
    void writeChanges() const;
    rectangle_t getFrameRect() const override;
  private:
    rectangle_t characteristics_;
  };
}


#endif
