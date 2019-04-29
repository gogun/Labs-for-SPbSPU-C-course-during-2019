#ifndef A3_COMPOSITE_SHAPE_HPP
#define A3_COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace maschenko
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape &cs);
    CompositeShape(CompositeShape &&cs);
    CompositeShape(maschenko::Shape *shape);
    ~CompositeShape();

    CompositeShape& operator =(const CompositeShape& rhs);
    CompositeShape& operator =(CompositeShape&& rhs);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const maschenko::point_t &center) override;
    void scale(double coefficient) override;
    void writeInfo() const override;
    int getShapeCount() const;
    void addShape(Shape *shape);
    void removeShape(Shape *shape);
    void removeShape(int index);
    Shape* getPointerOnShapeByIndex(int index) const;

  private:
    int shape_count_;
    std::unique_ptr<Shape *[]> shape_array_;
  };
}

#endif //A3_COMPOSITE_SHAPE_HPP
