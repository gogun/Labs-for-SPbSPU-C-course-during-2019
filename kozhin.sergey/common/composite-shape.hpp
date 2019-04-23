#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include "shape.hpp"

namespace kozhin
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&&);
    CompositeShape(Shape&);
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape&);
    CompositeShape& operator=(CompositeShape&&);
    Shape& operator[](int) const;
    void addShape(Shape&);
    void deleteShape(int);
    Shape& getShape(int) const;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const override;
    int getShapeCount() const;
    void move(double, double) override;
    void move(const point_t&) override;
    void scale(double) override;

  private:
    int count_;
    int size_;
    Shape** shapeList_;
  };

} // namespace kozhin

#endif // COMPOSITESHAPE_HPP
