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
    CompositeShape(maschenko::Shape *shape);

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
    Shape* getShapeAt(int index) const;

  private:
    int shape_count_;
    std::unique_ptr<Shape *[]> shape_array_;
  };
}

#endif //A3_COMPOSITE_SHAPE_HPP
