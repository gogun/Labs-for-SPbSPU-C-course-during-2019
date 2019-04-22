#ifndef TriangleHPP_A2
#define TriangleHPP_A2

#include "shape.hpp"

namespace sheve
{
  class Triangle : public Shape
  {
  public:
    Triangle(const point_t &p1, const point_t &p2, const point_t &p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &p) override;
    void move(double dx, double dy) override;
    rectangle_t getSides() const;
    void scale(double coefficient) override;
    void printInfo() const override;

  private:
    point_t m_pos;
    point_t m_a;
    point_t m_b;
    point_t m_c;
  };
}

#endif
