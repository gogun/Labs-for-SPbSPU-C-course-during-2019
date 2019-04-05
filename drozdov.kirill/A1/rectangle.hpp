#include "shape.hpp"

class Rectangle: public Shape
{
  public:
    Rectangle(double width, double height, point_t pos = {0,0});
    void displayData() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move (double dx, double dy) override;
    void move (point_t dot) override;
  private:
    double width_;
    double height_;
    point_t pos_;
};
