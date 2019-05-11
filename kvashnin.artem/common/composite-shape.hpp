#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace kvashnin
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& cs);
    CompositeShape(CompositeShape&& cs);
    CompositeShape(Shape *shape);
    ~CompositeShape() = default;

    CompositeShape& operator =(const CompositeShape& rh);
    CompositeShape& operator =(CompositeShape&& rh);
    Shape* operator [](int i) const;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(const double dx, const double dy) override;
    void scale(double coefficient) override;
    void printInfo() const override;

    point_t getCentre() const;
    int size() const;
    void add(Shape *shape);
    void remove(int index);

  private:
    int counter_;
    std::unique_ptr<Shape *[]> array_;
  };
}

#endif
