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

    CompositeShape operator =(const CompositeShape&);
    CompositeShape operator =(CompositeShape&&);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double, double);
    void move(point_t);
    void scale(double);

    void addShape(Shape&);

  private:
    struct link;

    struct link {
      Shape* value;
      link* next;
      link* prev;
    };

    rectangle_t frameRect_;
    double area_;
    link* listHead_;
    link* listLast_;

    void recomputeArea();
    void recomputeFrame();
    void copyFromSource(const CompositeShape&);
  };
}

#endif
