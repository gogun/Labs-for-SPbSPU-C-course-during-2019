#include "base-types.hpp"
#include "circle.hpp"
#include

Circle::Circle(const point_t &center, double radius):
  center_(center),
  radius_(radius)
{

}
double Circle::getArea() const
{
  return pi*radius_*radius_;//what is pi?
}
void Circle::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}
void Circle::move(point_t newPoint)
{
  center_ = newPoint;
}
