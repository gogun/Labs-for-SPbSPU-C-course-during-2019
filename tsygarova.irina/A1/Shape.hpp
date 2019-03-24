//
//  Shape.hpp
//  A1
//
//  Created by Ирина on 23.03.2019.
//  Copyright © 2019 Ирина. All rights reserved.
//

#ifndef Shape_h
#define Shape_h

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void move(const point_t &p) = 0;
  virtual point_t Center() const = 0;
  virtual void print() const =0;
};

#endif /* Shape_hpp */
