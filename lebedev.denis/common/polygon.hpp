#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <cstddef>

#include "shape.hpp"

namespace lebedev
{
  class Polygon: public Shape
  {
    public:
      Polygon(std::size_t qtyVertex, lebedev::point_t *vertex);
      virtual ~Polygon();

      void printData() const ;
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void scale(const double multiplier) override;
      bool checkBump() const ;

      void move(const double x, const double y) override;
      void move(const point_t &new_point) override;

      lebedev::point_t calcCentroid() const;

    private:
      std::size_t m_qtyVertex;
      point_t m_centroid;
      point_t *m_vertex;
  };
}
#endif
