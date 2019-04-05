#include "composite-shape.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

maschenko::CompositeShape::CompositeShape(maschenko::Shape *shape) :
  //присваиваю здесь центр с координатами (0;0) так как shape может быть null
  pos_({0, 0}),
  shape_quantity_(1),
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
  for (int i = 0; i < shape_quantity_; ++i)
  {
    sum_shapes_area += shape_array_[i]->getArea();
  }
  return sum_shapes_area;
}

maschenko::rectangle_t maschenko::CompositeShape::getFrameRect() const
{
  double max_y = shape_array_[0]->getFrameRect().pos.y + shape_array_[0]->getFrameRect().height / 2;
  double min_y = shape_array_[0]->getFrameRect().pos.y - shape_array_[0]->getFrameRect().height / 2;
  double max_x = shape_array_[0]->getFrameRect().pos.x + shape_array_[0]->getFrameRect().width / 2;
  double min_x = shape_array_[0]->getFrameRect().pos.x - shape_array_[0]->getFrameRect().width / 2;
  for (int i = 1; i < shape_quantity_; i++)
  {
    if (max_y < shape_array_[i]->getFrameRect().pos.y + shape_array_[i]->getFrameRect().height / 2)
    {
      max_y = shape_array_[i]->getFrameRect().pos.y + shape_array_[i]->getFrameRect().height / 2;
    }
    if (min_y > shape_array_[i]->getFrameRect().pos.y - shape_array_[i]->getFrameRect().height / 2)
    {
      min_y = shape_array_[i]->getFrameRect().pos.y - shape_array_[i]->getFrameRect().height / 2;
    }
    if (max_x < shape_array_[i]->getFrameRect().pos.x + shape_array_[i]->getFrameRect().width / 2)
    {
      max_x = shape_array_[i]->getFrameRect().pos.x + shape_array_[i]->getFrameRect().width / 2;
    }
    if (min_x > shape_array_[i]->getFrameRect().pos.x - shape_array_[i]->getFrameRect().width / 2)
    {
      min_x = shape_array_[i]->getFrameRect().pos.x - shape_array_[i]->getFrameRect().width / 2;
    }
  }
  return
  {
    {
      (max_x + min_x) / 2,
      (max_y + min_y) / 2
    },
    max_x - min_x,
    max_y - min_y
  };
}

void maschenko::CompositeShape::move(double dx, double dy)
{
  for (int i = 0; i < shape_quantity_; ++i)
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
  for (int i = 0; i < shape_quantity_; ++i)
  {
    shape_array_[i]->move(dx, dy);
  }
}

void maschenko::CompositeShape::scale(double coefficient)
{
  if (coefficient > 0)
  {
    double dx = 0;
    double dy = 0;
    for (int i = 0; i < shape_quantity_; ++i)
    {
      dx = shape_array_[i]->getFrameRect().pos.x - pos_.x;
      dy = shape_array_[i]->getFrameRect().pos.x - pos_.y;
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
  std::cout << std::endl
            << "Quantity shape in CompositeShape = " << shape_quantity_
            << " with centre (" << pos_.x << ";" << pos_.y << ") " << std::endl
            << "Area = " << getArea() << std::endl
            << "Frame rectangle width = " << getFrameRect().width
            << ", height = " << getFrameRect().height
            << ", and with centre (" << getFrameRect().pos.x << ";"
            << getFrameRect().pos.y << ") " << std::endl << std::endl;
}

maschenko::point_t maschenko::CompositeShape::getCenter() const
{
  return pos_;
}

int maschenko::CompositeShape::getShapeQuantity() const
{
  return shape_quantity_;
}

void maschenko::CompositeShape::addShape(maschenko::Shape *shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("shape equals null. It can't be");
  }

  std::unique_ptr<maschenko::Shape*[]> new_shape_array(new maschenko::Shape *[shape_quantity_ + 1]);
  for (int i = 0; i < shape_quantity_; ++i)
  {
    new_shape_array[i] = shape_array_[i];
  }
  new_shape_array[shape_quantity_] = shape;
  shape_quantity_++;
  shape_array_.swap(new_shape_array);
  double max_y = shape_array_[0]->getFrameRect().pos.y + shape_array_[0]->getFrameRect().height / 2;
  double min_y = shape_array_[0]->getFrameRect().pos.y - shape_array_[0]->getFrameRect().height / 2;
  double max_x = shape_array_[0]->getFrameRect().pos.x + shape_array_[0]->getFrameRect().width / 2;
  double min_x = shape_array_[0]->getFrameRect().pos.x - shape_array_[0]->getFrameRect().width / 2;
  for (int i = 1; i < shape_quantity_; i++)
  {
    if (max_y < shape_array_[i]->getFrameRect().pos.y + shape_array_[i]->getFrameRect().height / 2)
    {
      max_y = shape_array_[i]->getFrameRect().pos.y + shape_array_[i]->getFrameRect().height / 2;
    }
    if (min_y > shape_array_[i]->getFrameRect().pos.y - shape_array_[i]->getFrameRect().height / 2)
    {
      min_y = shape_array_[i]->getFrameRect().pos.y - shape_array_[i]->getFrameRect().height / 2;
    }
    if (max_x < shape_array_[i]->getFrameRect().pos.x + shape_array_[i]->getFrameRect().width / 2)
    {
      max_x = shape_array_[i]->getFrameRect().pos.x + shape_array_[i]->getFrameRect().width / 2;
    }
    if (min_x > shape_array_[i]->getFrameRect().pos.x - shape_array_[i]->getFrameRect().width / 2)
    {
      min_x = shape_array_[i]->getFrameRect().pos.x - shape_array_[i]->getFrameRect().width / 2;
    }
  }
  pos_.x = (max_x + min_x) / 2;
  pos_.y = (max_y + min_y) / 2;
}
