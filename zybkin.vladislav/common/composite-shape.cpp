#include "composite-shape.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

zybkin::CompositeShape::CompositeShape(const CompositeShape &copyCompositeShape) :
  shapeArray_(new zybkin::Shape *[copyCompositeShape.count_]),
  count_(copyCompositeShape.count_)
{
  for (int i = 0; i < count_; ++i)
  {
    shapeArray_[i] = copyCompositeShape.shapeArray_[i];
  }
}

zybkin::CompositeShape::CompositeShape(CompositeShape &&movedCompositeShape) :
  shapeArray_(movedCompositeShape.shapeArray_),
  count_(movedCompositeShape.count_)
{
  movedCompositeShape.shapeArray_ = nullptr;
  count_ = 0;
}

zybkin::CompositeShape::CompositeShape(zybkin::Shape &shape) :
  shapeArray_(new zybkin::Shape *[1]{&shape}),
  count_(1)
{
}

zybkin::CompositeShape::~CompositeShape()
{
  delete [] shapeArray_;
}

zybkin::CompositeShape &zybkin::CompositeShape::operator =(const CompositeShape &copyCompositeShape)
{
  if (this != &copyCompositeShape)
  {
    zybkin::CompositeShape(copyCompositeShape).swap(*this);
  }
  return *this;
}

zybkin::CompositeShape &zybkin::CompositeShape::operator =(CompositeShape &&movedCompositeShape)
{
  if (this != &movedCompositeShape)
  {
    CompositeShape(std::move(movedCompositeShape)).swap(*this);
  }

  return *this;
}

zybkin::Shape *zybkin::CompositeShape::operator [](int index) const
{
  if (index >= count_)
  {
    throw std::out_of_range("Index out of range");
  }

  return shapeArray_[index];
}

double zybkin::CompositeShape::getArea() const
{
  double fullArea_ = 0;
  for (int i = 0; i < count_; ++i)
  {
    fullArea_ += shapeArray_[i]->getArea();
  }

  return fullArea_;
}

zybkin::rectangle_t zybkin::CompositeShape::getFrameRect() const
{
  zybkin::rectangle_t currentRectangle = shapeArray_[0]->getFrameRect();
  double max_X = currentRectangle.pos.x + currentRectangle.width / 2.0;
  double min_X = currentRectangle.pos.x - currentRectangle.width / 2.0;
  double max_Y = currentRectangle.pos.y + currentRectangle.height / 2.0;
  double min_Y = currentRectangle.pos.y - currentRectangle.height / 2.0;

  for (int i = 1; i < count_; ++i)
  {
    currentRectangle = shapeArray_[i]->getFrameRect();
    double temporaryValue = currentRectangle.pos.x + currentRectangle.width / 2.0;
    max_X = std::max(temporaryValue, max_X);

    temporaryValue = currentRectangle.pos.x - currentRectangle.width / 2.0;
    min_X = std::min(temporaryValue, min_X);

    temporaryValue = currentRectangle.pos.y + currentRectangle.height / 2.0;
    max_Y = std::max(temporaryValue, max_Y);

    temporaryValue = currentRectangle.pos.y - currentRectangle.height / 2.0;
    min_Y = std::min(temporaryValue, min_Y);
  }

  return {(max_X - min_X), (max_Y - min_Y), {(max_X + min_X) / 2, (max_Y + min_Y) / 2}};
}

int zybkin::CompositeShape::getCount() const
{
  return count_;
}

void zybkin::CompositeShape::move(double shift_x, double shift_y)
{
  for (int i = 0; i < count_; ++i)
  {
    shapeArray_[i]->move(shift_x, shift_y);
  }
}

void zybkin::CompositeShape::move(const point_t &position)
{
  const zybkin::rectangle_t frameRect = getFrameRect();
  double shift_x = position.x - frameRect.pos.x;
  double shift_y = position.y - frameRect.pos.y;

  move(shift_x, shift_y);
}

void zybkin::CompositeShape::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("Coef has to be positive!");
  }
  const zybkin::point_t posFrameRect = getFrameRect().pos;
  for (int i = 0; i < count_; ++i)
  {
    zybkin::point_t shapeCenter = shapeArray_[i]->getFrameRect().pos;
    shapeArray_[i]->scale(coef);
    double shift_X = (shapeCenter.x - posFrameRect.x) * (coef - 1);
    double shift_Y = (shapeCenter.y - posFrameRect.y) * (coef - 1);
    shapeArray_[i]->move(shift_X, shift_Y);
  }
}

void zybkin::CompositeShape::addShape(Shape &shape)
{
  //check that we have empty cell
  for (int i = 1; i < count_; ++i)
  {
    if (shapeArray_[i] == nullptr)
    {
      shapeArray_[i] = &shape;
      return;
    }
  }


  zybkin::Shape ** temporaryArray = new zybkin::Shape*[count_ + 1];
  for (int i = 0; i < count_ + 1; ++i)
  {
    temporaryArray[i] = shapeArray_[i];
  }
  temporaryArray[count_] = &shape;
  count_++;
  delete [] shapeArray_;
  shapeArray_ = temporaryArray;
}

void zybkin::CompositeShape::deleteShape(int index)
{
  if (index >= count_)
  {
    throw std::out_of_range("Index out of range");
  }
  if (count_ == 1)
  {
    throw std::invalid_argument("Composite has to consist one shape at least. You try to delete the last shape.");
  }

  count_--;
  for (int i = index; i < count_; ++i)
  {
    shapeArray_[i] = shapeArray_[i+1];
  }

  shapeArray_[count_] = nullptr;
}

void zybkin::CompositeShape::printInfo() const
{
  const zybkin::rectangle_t frameRect = getFrameRect();
  std::cout << "The center of composite shape: (" << frameRect.pos.x << "," << frameRect.pos.y << ")" << "\n";
  std::cout << "count_ of shapes: " << count_ << "\n";
  std::cout << "Full area of composite shape: " << getArea() << "\n";
  std::cout << "Frame rectangle:\n";
  std::cout << "Width: " << frameRect.width << "\n";
  std::cout << "Height: " << frameRect.height << "\n\n";
}

void zybkin::CompositeShape::swap(CompositeShape &swappingShape)
{
  std::swap(shapeArray_, swappingShape.shapeArray_);
  std::swap(count_, swappingShape.count_);
}
