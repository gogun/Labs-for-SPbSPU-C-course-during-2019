#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
  public:
    Circle(const point_t& center, float radius);
    Circle(float centerX, float centerY, float radius);

    float getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const override;
    void move(const point_t& pos) override;
    void move(float dltX, float dltY) override;

  private:
    point_t m_center;
    float m_radius;
};

#endif //CIRCLE_HPP
