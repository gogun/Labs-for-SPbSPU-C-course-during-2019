#ifndef triangle_hpp
#define triangle_hpp

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &corner_1, const point_t &corner_2, const point_t &corner_3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(const double dx, const double dy) override;
  void printInfo() const override;
private:
  point_t m_corner_1, m_corner_2, m_corner_3;
  point_t m_center;
};
#endif
