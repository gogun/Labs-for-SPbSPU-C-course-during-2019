#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"



int main()
{
  Circle cir({3.0, 2.0}, 7.0);
  Shape* shp = &cir;
  shp->writeParameters();
  shp->move({5.0, -5.0});
  shp->writeParameters();
  shp->move(2.0, 3.0);
  shp->writeParameters();

  Rectangle rect({{5.0, 11.0}, 3.0, 6.0});
  shp = &rect;
  shp->writeParameters();
  shp->move({6.0, -6.0});
  shp->writeParameters();
  shp->move(3.0, 5.0);
  shp->writeParameters();

  Triangle trg({2.0, 1.0}, {2.5, 1.5}, {3.0, 2.0});
  shp = &trg;
  shp->writeParameters();
  shp->move({7.0, -7.0});
  shp->writeParameters();
  shp->move(5.0, 6.0);
  shp->writeParameters();

  return 0;
}
