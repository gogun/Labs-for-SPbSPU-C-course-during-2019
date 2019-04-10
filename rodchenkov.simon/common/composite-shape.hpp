#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace rodchenkov {

class CompositeShape : public Shape
{
public:
  CompositeShape();

  double      getArea()                const noexcept override;
  rectangle_t getFrameRect()           const noexcept override;
  void        printData(std::ostream&) const          override;
  void        move(const point_t&)           noexcept override;
  void        move(double, double)           noexcept override;
  void        scale(double)                           override;
  
  void add(const std::shared_ptr<Shape>&);
  int  getSize() const noexcept;

private:

  std::size_t                               size_;
  rectangle_t                               frame_rect_;
  std::unique_ptr<std::shared_ptr<Shape>[]> shapes_;

  void computeFrameRect() noexcept;
};

} // namespace rodchenkov

#endif // COMPOSITE_SHAPE_HPP
