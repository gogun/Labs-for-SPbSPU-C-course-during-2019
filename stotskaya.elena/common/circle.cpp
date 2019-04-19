#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <cmath>
#include <stdexcept>

stotskaya::Circle::Circle(const point_t& center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0.0) {
    throw std::invalid_argument("Incorrect negative circle radius");
  }
}

double stotskaya::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

stotskaya::rectangle_t stotskaya::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void stotskaya::Circle::move(const point_t &point)
{
  center_ = point;
}

void stotskaya::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void stotskaya::Circle::scale(double ratio)
{
  if (ratio <= 0.0) {
    throw std::invalid_argument("Incorrect negative scaling ratio");
  } else {
    radius_ *= ratio;
  }
}
