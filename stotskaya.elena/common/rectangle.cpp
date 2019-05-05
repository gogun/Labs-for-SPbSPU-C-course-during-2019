#include "rectangle.hpp"
#include <stdexcept>

stotskaya::Rectangle::Rectangle(const point_t& center, double width, double height):
  center_(center),
  width_(width),
  height_(height)
{
  if (width_ <= 0.0) {
    throw std::invalid_argument("Incorrect negative rectangle width");
  }
  if (height_ <= 0.0) {
    throw std::invalid_argument("Incorrect negative rectangle height");
  }
}

double stotskaya::Rectangle::getArea() const
{
  return (width_ * height_);
}

stotskaya::rectangle_t stotskaya::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void stotskaya::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void stotskaya::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void stotskaya::Rectangle::scale(double ratio)
{
  if (ratio <= 0.0) {
    throw std::invalid_argument("Incorect negative scaling ratio");
  } else {
    width_ *= ratio;
    height_ *= ratio;
  }
}
