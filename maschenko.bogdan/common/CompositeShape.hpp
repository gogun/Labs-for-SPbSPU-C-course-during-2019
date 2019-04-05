#ifndef A2_COMPOSITESHAPE_HPP
#define A2_COMPOSITESHAPE_HPP

#include "shape.hpp"
#include <memory>

class CompositeShape : public maschenko::Shape
{
public:
  CompositeShape(maschenko::Shape *shape);

  double getArea() const override;
  maschenko::rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const maschenko::point_t &center) override;
  void scale(double coefficient) override;
  void writeInfo() const override;
  maschenko::point_t getCenter() const;
  int getShapeQuantity() const;
  void addShape(maschenko::Shape *shape);

private:
  maschenko::point_t pos_;
  int shape_quantity_;
  std::unique_ptr<maschenko::Shape*[]> shape_array_;
};

#endif //A2_COMPOSITESHAPE_HPP
