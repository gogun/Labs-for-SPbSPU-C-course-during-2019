#ifndef AP_A1_CIRCLE

#define AP_A1_CIRCLE

#include "shape.hpp"

namespace prohorova
{
  class Circle:public Shape
  {
  public:
    Circle(const point_t& /*pos*/, double /*radius*/);
    Circle(double /*posX*/, double /*posY*/, double /*radius*/);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& /*newPos*/) override;
    void move(double /*dx*/, double /*dy*/) override;
    void show() const override;
    void scale(double /*factor*/) override;

    const point_t& getPos() const;
    double getRadius() const;
  
  private:
    point_t pos_;
    double radius_;
  };
}

#endif // AP_A1_CIRCLE
