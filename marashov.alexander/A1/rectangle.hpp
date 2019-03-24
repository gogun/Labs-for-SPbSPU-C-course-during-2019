#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
  public:
    Rectangle(const point_t& pos, double width, double height);
    Rectangle(double posX, double posY, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const override;
    void move(const point_t& pos) override;
    void move(double dltX, double dltY) override;

  private:
    rectangle_t m_figure;
};

#endif //RECTANGLE_HPP
