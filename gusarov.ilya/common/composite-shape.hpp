#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H
#include "shape.hpp"
#include <iostream>
#include <memory>

namespace gusarov
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape &);
    CompositeShape(CompositeShape &&);
    CompositeShape(const std::shared_ptr<gusarov::Shape> &);
    ~CompositeShape() override = default;
    CompositeShape &operator =(const CompositeShape &);
    CompositeShape &operator =(CompositeShape &&);
    std::shared_ptr<gusarov::Shape> &operator [](const size_t) const;
    size_t getSize() const;
    void add(const std::shared_ptr<gusarov::Shape> &);
    void remove(const size_t);
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const double, const double) override;
    void move(const point_t &) override;
    void printInfo() const override;
    void scale(const double) override;
    void rotate(double) override;
  private:
    size_t size_;
    std::unique_ptr<std::shared_ptr<Shape> []> shapes_;
  };
}
#endif
