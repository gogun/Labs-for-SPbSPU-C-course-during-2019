#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"

namespace blyshchik {
  class Rectangle : public Shape {
  public:
    Rectangle(const point_t /*pos*/, double /*width*/, double /*height*/);
    Rectangle(double /*x*/, double /*y*/, double /*width*/, double /*height*/);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t /*newPos*/) override;
    void move(double /*newX*/, double /*newY*/) override;
    void print() const override;
    point_t getPosition() const;
    double getHeight() const;
    double getWidth() const;
    void scale(double /*coefficient*/) override;

  private:
    rectangle_t rectCl_;
  };
};
#endif //A1_RECTANGLE_HPP
