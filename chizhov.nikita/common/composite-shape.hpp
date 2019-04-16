#ifndef CN_A3_COMPOSITESHAPE
#define CN_A3_COMPOSITESHAPE

#include "shape.hpp"

namespace chizhov
{
  class CompositeShape : public Shape {
  public:
    CompositeShape(Shape&);
    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&&);
    ~CompositeShape();

    CompositeShape& operator =(const CompositeShape&);
    CompositeShape& operator =(CompositeShape&&);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double, double);
    void move(point_t);
    void scale(double);

    void addShape(Shape&);
    void deleteShape(const Shape&);

  private:
    Shape** shapes_;
    int quantity_;

    double recomputeArea() const;
    rectangle_t recomputeFrame() const;
    void copyFromSource(const CompositeShape&);
  };
}

#endif
