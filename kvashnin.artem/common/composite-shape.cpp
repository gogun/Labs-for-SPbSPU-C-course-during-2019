#include "composite-shape.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <limits>

kvashnin::CompositeShape::CompositeShape():
  counter_(0),
  array_(new Shape*[0])
{}

kvashnin::CompositeShape::CompositeShape(const CompositeShape& cs):
  counter_(cs.counter_),
  array_(new Shape*[cs.counter_])
{
  for (int i = 0; i < counter_; i++)
  {
    array_[i] = cs.array_[i];
  }
}

kvashnin::CompositeShape::CompositeShape(CompositeShape&& cs):
  counter_(cs.counter_),
  array_(std::move(cs.array_))
{}

kvashnin::CompositeShape::CompositeShape(Shape *shape):
  counter_(1),
  array_(new Shape*[1])
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("null ptr");
  }
  array_[0] = shape;
}

kvashnin::CompositeShape& kvashnin::CompositeShape::operator =(const CompositeShape& rh)
{
  if (this == &rh)
  {
    return *this;
  }

  std::unique_ptr<Shape*[]> newArray(new Shape*[rh.counter_]);
  for (int i = 0; i < rh.counter_; i++)
  {
    newArray[i] = rh.array_[i];
  }
  array_.swap(newArray);
  return *this;
}

kvashnin::CompositeShape& kvashnin::CompositeShape::operator =(CompositeShape&& rh)
{
  array_ = std::move(rh.array_);
  return *this;
}

kvashnin::Shape* kvashnin::CompositeShape::operator [](int index)
{
  if ((index > counter_) || (index < 0))
  {
    throw std::out_of_range("Invalid index");
  }
  return array_[index];
}


double kvashnin::CompositeShape::getArea() const
{
  double sum = 0;
  for (int i = 0; i < counter_; i++)
  {
    sum += array_[i]->getArea();
  }
  return sum;
}

kvashnin::rectangle_t kvashnin::CompositeShape::getFrameRect() const
{
  if (counter_ != 0)
  {
    double left = std::numeric_limits<double>::max();
    double right = std::numeric_limits<double>::min();
    double top = std::numeric_limits<double>::min();
    double bottom = std::numeric_limits<double>::max();

    for (int i = 0; i < counter_; i++)
    {
      rectangle_t curFrameRect = array_[i]->getFrameRect();

      double leftBorder = curFrameRect.pos.x - curFrameRect.width / 2;
      double rightBorder = curFrameRect.pos.x + curFrameRect.width / 2;
      double topBorder = curFrameRect.pos.y + curFrameRect.height / 2;
      double bottomBorder = curFrameRect.pos.y - curFrameRect.height / 2;

      left = std::min(left, leftBorder);
      right = std::max(right, rightBorder);
      top = std::max(top, topBorder);
      bottom = std::min(bottom, bottomBorder);
    }
    return {{(right + left) / 2, (top + bottom) / 2}, right - left, top - bottom};
  }
  else
  {
    throw std::invalid_argument("empty array");
  }
}

void kvashnin::CompositeShape::move(const point_t &pos)
{
  point_t cenData = getCentre();
  for (int i = 0; i < counter_; i++)
  {
    array_[i]->move(pos.x - cenData.x, pos.y - cenData.y);
  }
}

void kvashnin::CompositeShape::move(const double dx, const double dy)
{
  for (int i = 0; i < counter_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

void kvashnin::CompositeShape::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("coefficient can not be <= 0");
  }
  point_t cenData = getCentre();
  for (int i = 0; i < counter_; i++)
  {
    array_[i]->scale(coefficient);
    array_[i]->move(cenData.x + (array_[i]->getFrameRect().pos.x - cenData.x) * coefficient,
        cenData.y + (array_[i]->getFrameRect().pos.y - cenData.y) * coefficient);
  }
}

void kvashnin::CompositeShape::printInfo() const
{
  rectangle_t frameRectData = getFrameRect();
  point_t centreData = getCentre();
  std::cout << "CompositeShape coordinates: X: " << centreData.x
      << "; Y: " << centreData.y << std::endl
      << "CompositeShape area: " << getArea() << std::endl
      << "Rectangle frame width: " << frameRectData.width
      << "; height: " << frameRectData.height << std::endl
      << "Length: " << length() << std::endl;
}

kvashnin::point_t kvashnin::CompositeShape::getCentre() const
{
  return getFrameRect().pos;
}

int kvashnin::CompositeShape::length() const
{
  return counter_;
}

void kvashnin::CompositeShape::add(kvashnin::Shape *shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("null ptr");
  }

  std::unique_ptr<Shape*[]> newArray(new Shape*[counter_ + 1]);
  for (int i = 0; i < counter_; i++)
  {
    newArray[i] = array_[i];
  }
  newArray[counter_] = shape;
  counter_++;
  array_.swap(newArray);
}

void kvashnin::CompositeShape::remove(int index)
{
  if ((index > counter_) || (index < 0))
  {
    throw std::out_of_range("Invalid index");
  }

  std::unique_ptr<Shape*[]> newArray(new Shape*[counter_ - 1]);

  for (int i = 0; i < index; i++)
  {
    newArray[i] = array_[i];
  }
  counter_--;
  for (int i = index; i < counter_; i++)
  {
    newArray[i] = array_[i + 1];
  }

  array_.swap(newArray);
}
