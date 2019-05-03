#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace shestakova
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& copiedCompositeShape);
    CompositeShape(CompositeShape&& movedCompositeShape);
    CompositeShape(Shape& shape);
    ~CompositeShape();

    CompositeShape &operator =(const CompositeShape &copiedCompositeShape);
    CompositeShape &operator =(CompositeShape &&movedCompositeShape);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void addShape(Shape &shape);
    void deleteShape(unsigned int index);

  private:
    unsigned int count_;
    Shape** figures_;
  };
}

#endif
