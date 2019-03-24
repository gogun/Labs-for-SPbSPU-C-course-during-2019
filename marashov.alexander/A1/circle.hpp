#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
  public:
    Circle(const point_t& center, double radius);
    Circle(double centerX, double centerY, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const override;
    void move(const point_t& pos) override;
    void move(double dltX, double dltY) override;

  private:
    point_t m_center;
    double m_radius;
};

#endif //CIRCLE_HPP
