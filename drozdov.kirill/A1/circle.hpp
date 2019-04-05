#include "shape.hpp"

class Circle: public Shape
{
  public:
    Circle (double radius,point_t pos = {0.0 , 0.0});
    void displayData() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move (double dx, double dy) override;
    void move (point_t dot) override;
  private:
    double radius_;
    point_t pos_;
};
