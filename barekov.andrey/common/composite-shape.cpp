#include "composite-shape.hpp"

#include <iostream>
#include <stdexcept>

barekov::CompositeShape::CompositeShape(Shape* shape) :
  centre_({0, 0}),
  shapeQuantity_(1),
  arrayOfShapes_(new Shape*[1])
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Shape pointer must not be null");
  }

  arrayOfShapes_[0] = shape;
  centre_ = arrayOfShapes_[0]->getFrameRect().pos;
}

double barekov::CompositeShape::getArea() const
{
  double totalArea = 0;
  for (int i = 0; i < shapeQuantity_; i++)
  {
    totalArea += arrayOfShapes_[i]->getArea();
  }
  return totalArea;
}

barekov::rectangle_t barekov::CompositeShape::getFrameRect() const
{
  rectangle_t tmpFrameRect = arrayOfShapes_[0]->getFrameRect();

  //leftX, rightX, bottomY are shortened for better code readability.
  double lftX = tmpFrameRect.pos.x - tmpFrameRect.width / 2;
  double rgtX = tmpFrameRect.pos.x + tmpFrameRect.width / 2;
  double btmY = tmpFrameRect.pos.y - tmpFrameRect.height / 2;
  double topY = tmpFrameRect.pos.y + tmpFrameRect.height / 2;

  for (int i = 0; i < shapeQuantity_; i++)
  {
    tmpFrameRect = arrayOfShapes_[i]->getFrameRect();

    double tmpValue = tmpFrameRect.pos.x - tmpFrameRect.width / 2;
    lftX = tmpValue < lftX ? tmpValue : lftX;

    tmpValue = tmpFrameRect.pos.x + tmpFrameRect.width / 2;
    rgtX = tmpValue > rgtX ? tmpValue : rgtX;

    tmpValue = tmpFrameRect.pos.y - tmpFrameRect.height / 2;
    btmY = tmpValue < btmY ? tmpValue : btmY;

    tmpValue = tmpFrameRect.pos.y + tmpFrameRect.height / 2;
    topY = tmpValue > topY ? tmpValue : topY;
  }

  return {rgtX - lftX, topY - btmY, {(lftX + rgtX) / 2, (btmY + topY) / 2}};
}

barekov::point_t barekov::CompositeShape::getPos() const
{
  return centre_;
}

void barekov::CompositeShape::showScalableParameters() const
{
  std::cout << "\nFrame Rectangle size of the composite shape is "
      << getFrameRect().width << "x" << getFrameRect().height << "\n";
  for (int i = 0; i < shapeQuantity_; i++)
  {
    std::cout << "The position of composite shape part No." << i << " is ("
        << arrayOfShapes_[i]->getFrameRect().pos.x << "; "
        << arrayOfShapes_[i]->getFrameRect().pos.y << ")\n";
  }
}

void barekov::CompositeShape::move(const point_t& centre)
{
  double deltaX = centre.x - centre_.x;
  double deltaY = centre.y - centre_.y;
  for (int i = 0; i < shapeQuantity_; i++)
  {
    arrayOfShapes_[i]->move(deltaX, deltaY);
  }
  centre_ = centre;
}

void barekov::CompositeShape::move(double deltaX, double deltaY)
{
  for (int i = 0; i < shapeQuantity_; i++)
  {
    arrayOfShapes_[i]->move(deltaX, deltaY);
  }
  centre_.x += deltaX;
  centre_.y += deltaY;
}

void barekov::CompositeShape::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Composite shape scale factor must be a positive number");
  }

  for (int i = 0; i < shapeQuantity_; i++)
  {
    double deltaX = arrayOfShapes_[i]->getFrameRect().pos.x - centre_.x;
    double deltaY = arrayOfShapes_[i]->getFrameRect().pos.y - centre_.y;
    arrayOfShapes_[i]->move({centre_.x + deltaX * scaleFactor, centre_.y + deltaY * scaleFactor});
    arrayOfShapes_[i]->scale(scaleFactor);
  }
}

void barekov::CompositeShape::addShape(Shape* addedShape)
{
  if (addedShape == nullptr)
  {
    throw std::invalid_argument("Added shape pointer must not be null");
  }

  std::unique_ptr<Shape*[]> tmpArray(new Shape*[shapeQuantity_ + 1]);
  for (int i = 0; i < shapeQuantity_; i++)
  {
    tmpArray[i] = arrayOfShapes_[i];
  }
  tmpArray[shapeQuantity_] = addedShape;
  shapeQuantity_++;
  arrayOfShapes_.swap(tmpArray);

  centre_ = getFrameRect().pos;
}

void barekov::CompositeShape::deleteShape(int index)
{
  if ((index >= shapeQuantity_) || (index < 0))
  {
    throw std::out_of_range("Index is out of range");
  }
  if (shapeQuantity_ == 1)
  {
    throw std::out_of_range("Composite shape cannot contain less than one figure");
  }

  std::unique_ptr<Shape*[]> tmpArray(new Shape*[shapeQuantity_ - 1]);
  for (int i = 0; i < index; i++)
  {
    tmpArray[i] = arrayOfShapes_[i];
  }
  for (int i = index; i < shapeQuantity_ - 1; i++)
  {
    tmpArray[i] = arrayOfShapes_[i + 1];
  }
  shapeQuantity_--;
  arrayOfShapes_.swap(tmpArray);

  centre_ = getFrameRect().pos;
}
