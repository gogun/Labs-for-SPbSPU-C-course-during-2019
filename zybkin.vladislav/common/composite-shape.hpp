#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include "shape.hpp"

namespace zybkin
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape(const CompositeShape &);
    CompositeShape(CompositeShape &&);
    CompositeShape(Shape *);
    ~CompositeShape();

    CompositeShape &operator =(const CompositeShape &);
    CompositeShape &operator =(CompositeShape &&);
    Shape *operator [](int) const;

    double getArea() const;
    rectangle_t getFrameRect() const;
    int getCount() const;
    void printInfo() const;
    void move(const point_t &);
    void move(double, double);
    void scale(double);
    void add(Shape *);
    void remove(int);
    void swap(CompositeShape &);

  private:
    Shape ** shapeArray_;
    int count_;
  };
}

#endif // COMPOSITESHAPE_HPP
