#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
  public:
    Rectangle(const point_t& pos, float width, float height);
    Rectangle(float posX, float posY, float width, float height);

    float getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const override;
    void move(const point_t& pos) override;
    void move(float dltX, float dltY) override;

  private:
    rectangle_t m_figure;
};

#endif //RECTANGLE_HPP
