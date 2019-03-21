#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape {
public:
  Circle(const point_t &pos, const double radius);

  ~Circle();

  double getArea() const;

  rectangle_t getFrameRect() const;

  void move(const double dx, const double dy);

  void move(const point_t &point);

  point_t getCenter() const;

  double getRadius() const;

private:
  point_t center_;
  double radius_;
};
