//
//  circle.cpp
//  A1
//
//  Created by Никита Пурнов on 27.03.2019.
//  Copyright © 2019 Никита Пурнов. All rights reserved.
//

#include "circle.hpp"

#include <iostream>
#include <cmath>

Circle::Circle(const double radius, const point_t & pos) :
  radius_(radius),
  pos_(pos)
{
    if (radius <= 0.0) {
        std::cerr << "Invalid circle radius, shall be greater than 0.0, is: " << radius << std::endl;
    }
}

double Circle::getArea() const
{
    return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
    return rectangle_t { .width = 2 * radius_, .height = 2 * radius_, .pos = pos_ };
}

void Circle::move(const point_t & pos)
{
    pos_.x = pos.x;
    pos_.y = pos.y;
}

void Circle::move(double x, double y)
{
    pos_.x += x;
    pos_.y += y;
}
