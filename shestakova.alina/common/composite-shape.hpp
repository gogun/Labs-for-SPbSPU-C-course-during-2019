#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace shestakova
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape(Shape &shape);
    ~CompositeShape() override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void addShape(Shape &shape);
    void deleteShape(int index);

  private:
    int count_;
    Shape** figures_;
  };
}

#endif
