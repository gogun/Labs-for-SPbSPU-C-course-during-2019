//
//  rectangle.hpp
//  A1
//
//  Created by Ирина on 23.03.2019.
//  Copyright © 2019 Ирина. All rights reserved.
//

#ifndef rectangle_h
#define rectangle_h

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, const point_t &position);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &p) override;
  point_t Center() const override;
  void print() const override;
private:
  double width_;
  double height_;
  point_t pos_;
};
#endif /* rectangle_hpp */
