#include "composite-shape.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

maschenko::CompositeShape::CompositeShape(maschenko::Shape *shape) :
  //присваиваю здесь центр с координатами (0;0) так как shape может быть null
  pos_({0, 0}),
  shape_count_(1),
  shape_array_(new maschenko::Shape*[1])
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("shape equals null. It can't be");
  }
  shape_array_[0] = shape;
  pos_ = shape_array_[0]->getFrameRect().pos;
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
  pos_.x += dx;
  pos_.y += dy;
}

void maschenko::CompositeShape::move(const maschenko::point_t &center)
{
  double dx = center.x - pos_.x;
  double dy = center.y - pos_.y;
  pos_ = center;
  for (int i = 0; i < shape_count_; ++i)
  {
    shape_array_[i]->move(dx, dy);
  }
}

void maschenko::CompositeShape::scale(double coefficient)
{
  if (coefficient > 0)
  {
    double dx = shape_array_[0]->getFrameRect().pos.x - pos_.x;
    double dy = shape_array_[0]->getFrameRect().pos.y - pos_.y;
    shape_array_[0]->move((coefficient - 1) * dx, (coefficient - 1) * dy);
    shape_array_[0]->scale(coefficient);

    for (int i = 1; i < shape_count_; ++i)
    {
      dx = shape_array_[i]->getFrameRect().pos.x - pos_.x;
      dy = shape_array_[i]->getFrameRect().pos.y - pos_.y;
      shape_array_[i]->move((coefficient - 1) * dx, (coefficient - 1) * dy);
      shape_array_[i]->scale(coefficient);
    }
  }
  else
  {
    throw std::invalid_argument("Invalid coefficient for CompositeShape");
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

int maschenko::CompositeShape::getShapeQuantity() const
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

  pos_.x = getFrameRect().pos.x;
  pos_.y = getFrameRect().pos.y;
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

  pos_.x = getFrameRect().pos.x;
  pos_.y = getFrameRect().pos.y;
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

maschenko::Shape* maschenko::CompositeShape::getShape(int index) const
{
  if (index > shape_count_)
  {
    throw std::out_of_range("Index out of range");
  }

  return shape_array_[index];
}
