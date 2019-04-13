#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace rodchenkov {

class CompositeShape : public Shape
{
public:
  CompositeShape();
  CompositeShape(const CompositeShape&);
  CompositeShape(CompositeShape&&) noexcept;

  const CompositeShape& operator = (const CompositeShape&);
  const CompositeShape& operator = (CompositeShape&&) noexcept;

  double                 getArea()                const noexcept override;
  rectangle_t            getFrameRect()           const noexcept override; 
  std::unique_ptr<Shape> cloneUnique()            const          override;
  void                   printData(std::ostream&) const          override;
  void                   move(const point_t&)           noexcept override;
  void                   move(double, double)           noexcept override;
  void                   scale(double)                           override;

  std::size_t getSize() const noexcept;
  void add(const std::unique_ptr<Shape>&);
  void add(std::unique_ptr<Shape>&&);

private:

  std::size_t                               size_;
  rectangle_t                               frame_rect_{};
  std::unique_ptr<std::unique_ptr<Shape>[]> shapes_;

  void computeFrameRect() noexcept;
  static void swap(CompositeShape& l, CompositeShape& r) noexcept;
};

} // namespace rodchenkov

#endif // COMPOSITE_SHAPE_HPP
