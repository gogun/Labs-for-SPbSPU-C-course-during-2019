#ifndef rectangle_hpp
#define rectangle_hpp

#include "shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(const double width, const double height, const point_t &center);
    
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(const double dx, const double dy) override;
    void printInfo() const override;
    
private:
    double width_;
    double height_;
    point_t pos_;
};

#endif
