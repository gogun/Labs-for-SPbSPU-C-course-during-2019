#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H
#include "shape.hpp"
#include <iostream>

namespace gusarov
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&&);
    CompositeShape(Shape&);
    ~CompositeShape();

    CompositeShape& operator =(const CompositeShape&);
    CompositeShape& operator =(CompositeShape&&);
    Shape& operator [](const size_t) const;

    size_t getSize() const;
    void add(Shape&);
    void remove(const size_t);
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const double, const double) override;
    void move(const point_t&) override;
    void printInfo() const override;
    void scale(const double) override;

  private:
    size_t size_;
    Shape** shapes_;
  };
}
#endif
