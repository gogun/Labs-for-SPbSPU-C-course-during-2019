#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include <iostream>
#include "shape.hpp"

namespace kvashnin
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();
    CompositeShape(Shape *shape);
    Shape* operator [](int i);
    void operator +=(Shape *shape);
    void operator -=(int index);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(const double dx, const double dy) override;
    void scale(double coefficient) override;
    void printInfo() const override;
    point_t getCentre() const;
    int length() const;
    void add(Shape *shape);
    void remove(int index);
    Shape* getShape(int index) const;

  private:
    int counter_;
    std::unique_ptr<Shape *[]> array_;
  };
}

#endif
