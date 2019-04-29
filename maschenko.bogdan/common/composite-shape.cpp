#include "composite-shape.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

maschenko::CompositeShape::CompositeShape() :
  shape_count_(0),
  shape_array_()
{}

maschenko::CompositeShape::CompositeShape(const maschenko::CompositeShape &cs) :
  shape_count_(cs.shape_count_),
  shape_array_(new maschenko::Shape*[cs.shape_count_])
{
  for (int i = 0; i < shape_count_; ++i)
  {
    shape_array_[i] = cs.shape_array_[i];
  }
}

maschenko::CompositeShape::CompositeShape(maschenko::CompositeShape &&cs) :
  shape_count_(cs.shape_count_),
  shape_array_(std::move(cs.shape_array_))
{}

maschenko::CompositeShape::CompositeShape(maschenko::Shape *shape) :
  shape_count_(1),
  shape_array_(new maschenko::Shape*[1])
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("shape equals null. It can't be");
  }
  shape_array_[0] = shape;
}

maschenko::CompositeShape::~CompositeShape()
{}

maschenko::CompositeShape& maschenko::CompositeShape::operator =(const CompositeShape& rhs)
{
  if (this != &rhs)
  {
    shape_count_ = rhs.shape_count_;
    std::unique_ptr<Shape*[]> new_shape_array(new Shape*[rhs.shape_count_]);
    for (int i = 0; i < shape_count_; i++)
    {
      new_shape_array[i] = rhs.shape_array_[i];
    }
    shape_array_.swap(new_shape_array);
  }

  return *this;
}

maschenko::CompositeShape& maschenko::CompositeShape::operator =(CompositeShape&& rhs)
{
  if (this != &rhs)
  {
    shape_count_ = rhs.shape_count_;
    shape_array__.swap(rhs.shape_array_);
    rhs.shape_array_.reset();
    rhs.shape_count_ = 0;
  }

  return *this;
}

double maschenko::CompositeShape::getArea() const
{
  double sum_shapes_area = 0;
  for (int i = 0; i < shape_count_; ++i)
  {
    sum_shapes_area += shape_array_[i]->getArea();
  }
  return sum_shapes_area;
}

maschenko::rectangle_t maschenko::CompositeShape::getFrameRect() const
{
  double max_x = shape_array_[0]->getFrameRect().pos.x;
  double min_x = shape_array_[0]->getFrameRect().pos.x;
  double max_y = shape_array_[0]->getFrameRect().pos.y;
  double min_y = shape_array_[0]->getFrameRect().pos.y;

  for (int i = 1; i < shape_count_; ++i)
  {
    rectangle_t temp_rect = shape_array_[i]->getFrameRect();

    double bottom_side = temp_rect.pos.y - temp_rect.height / 2;
    min_y = std::min(min_y, bottom_side);

    double top_side = temp_rect.pos.y + temp_rect.height / 2;
    max_y = std::max(max_y, top_side);

    double left_side = temp_rect.pos.x - temp_rect.width / 2;
    min_x = std::min(min_x, left_side);

    double right_side = temp_rect.pos.x + temp_rect.width / 2;
    max_x = std::max(max_x, right_side);
  }

  return rectangle_t{point_t{(max_x + min_x) / 2, (max_y + min_y) / 2}, max_x - min_x, max_y - min_y};
}

void maschenko::CompositeShape::move(double dx, double dy)
{
  for (int i = 0; i < shape_count_; ++i)
  {
    shape_array_[i]->move(dx, dy);
  }
}

void maschenko::CompositeShape::move(const maschenko::point_t &center)
{
  double dx = center.x - getFrameRect().pos.x;
  double dy = center.y - getFrameRect().pos.y;
  for (int i = 0; i < shape_count_; ++i)
  {
    shape_array_[i]->move(dx, dy);
  }
}

void maschenko::CompositeShape::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient for CompositeShape");
  }

  const point_t pos = getFrameRect().pos
  for (int i = 0; i < shape_count_; ++i)
  {
    double dx = shape_array_[i]->getFrameRect().pos.x - pos.x;
    double dy = shape_array_[i]->getFrameRect().pos.y - pos.y;
    shape_array_[i]->move((coefficient - 1) * dx, (coefficient - 1) * dy);
    shape_array_[i]->scale(coefficient);
  }
}

void maschenko::CompositeShape::writeInfo() const
{
  maschenko::rectangle_t temp_rect = getFrameRect();
  std::cout << std::endl
            << "Quantity shape in CompositeShape = " << shape_count_ << std::endl
            << "Area = " << getArea() << std::endl
            << "Frame rectangle width = " << temp_rect.width
            << ", height = " << temp_rect.height
            << ", and with centre (" << temp_rect.pos.x << ";"
            << temp_rect.pos.y << ") " << std::endl << std::endl;
}

int maschenko::CompositeShape::getShapeCount() const
{
  return shape_count_;
}

void maschenko::CompositeShape::addShape(maschenko::Shape *shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("shape equals null. It can't be");
  }

  std::unique_ptr<maschenko::Shape*[]> new_shape_array(new maschenko::Shape *[shape_count_ + 1]);
  for (int i = 0; i < shape_count_; ++i)
  {
    new_shape_array[i] = shape_array_[i];
  }
  new_shape_array[shape_count_] = shape;
  shape_count_++;
  shape_array_.swap(new_shape_array);
}

void maschenko::CompositeShape::removeShape(int index)
{
  if (index > shape_count_)
  {
    throw std::out_of_range("Index out of range");
  }

  std::unique_ptr<maschenko::Shape *[]> new_shape_array(new maschenko::Shape *[shape_count_ - 1]);

  for (int i = 0; i < index; ++i)
  {
    new_shape_array[i] = shape_array_[i];
  }

  shape_count_--;

  for (int i = index; i < shape_count_; ++i)
  {
    new_shape_array[i] = shape_array_[i + 1];
  }

  shape_array_.swap(new_shape_array);
}

void maschenko::CompositeShape::removeShape(maschenko::Shape *shape)
{
  for (int i = 0; i < shape_count_; ++i)
  {
    if (shape == shape_array_[i])
    {
      removeShape(i);
      return;
    }
  }

  throw std::invalid_argument("This shape doesn't exist");
}

maschenko::Shape* maschenko::CompositeShape::getPointerOnShapeByIndex(int index) const
{
  if (index > shape_count_)
  {
    throw std::out_of_range("Index out of range");
  }
  return shape_array_[index];
}
