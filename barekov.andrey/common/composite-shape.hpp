#ifndef A3_COMPOSITE_SHAPE
#define A3_COMPOSITE_SHAPE

#include <memory>

#include "shape.hpp"
#include "base-types.hpp"

namespace barekov
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& source);
    CompositeShape(CompositeShape&& source);
    CompositeShape(Shape* shape);
    ~CompositeShape();

    CompositeShape& operator =(const CompositeShape& rhs);
    CompositeShape& operator =(CompositeShape&& rhs);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getPos() const override;
    void showScalableParameters() const override;
    void move(const point_t& centre) override;
    void move(double deltaX, double deltaY) override;
    void scale(double scaleFactor) override;

    void addShape(Shape* shape);
    void deleteShape(int index);

  private:
    int count_;
    std::unique_ptr<Shape*[]> arrayOfShapes_;
  };
}

#endif
