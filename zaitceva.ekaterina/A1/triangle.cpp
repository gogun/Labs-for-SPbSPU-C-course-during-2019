#include "triangle.hpp"
#include <cmath>
#include <iostream>

Triangle::Triangle(const point_t &point1, const point_t &point2, const point_t &point3):
  point1_(point1),
  point2_(point2),
  point3_(point3)

{
  centre_.x = (point1_.x + point2_.x + point3_.x)/3;
  centre_.y = (point1_.x + point2_.x + point3_.x)/3;
  side1_ = sqrt((point1_.x - point2_.x)*(point1_.x - point2_.x) + (point1_.y - point2_.y)*(point1_.y - point2_.y));
  side2_ = sqrt((point2_.x - point3_.x)*(point2_.x - point3_.x) + (point2_.y - point3_.y)*(point2_.y - point3_.y));
  side3_ = sqrt((point1_.x - point3_.x)*(point1_.x - point3_.x) + (point1_.y - point3_.y)*(point1_.y - point3_.y));
}

double Triangle::getArea() const
{
  return abs(0.5*(point1_.x * (point2_.y - point3_.y) + point2_.x * (point3_.y - point1_.y) + point3_.x * (point1_.y - point2_.y)));
}

rectangle_t Triangle::getFrameRect() const
{
  double min_x = point1_.x;
  double max_x;
  double min_y = point1_.y;
  double max_y;
  if ((point1_.x <= point2_.x) && (point1_.x <= point3_.x))
   {
     min_x = point1_.x;
     if (point2_.x > point3_.x)
      {
        max_x = point2_.x;
      }
     else
      {
        max_x = point3_.x;
      }
   }
  else
   {
     if ((point2_.x <= point3_.x) && (point2_.x <= point1_.x))
      {
        min_x = point2_.x;
        if (point1_.x > point3_.x)
         {
           max_x = point1_.x;
         }
        else
         {
           max_x = point3_.x;
         }
      }
     else
      {
        if ((point3_.x <= point2_.x) && (point3_.x <= point1_.x))
         {
           min_x = point3_.x;
           if (point2_.x > point1_.x)
            {
              max_x = point2_.x;
            }
           else
            {
              max_x = point1_.x;
            }
         }
      }
    }
    if ((point1_.y <= point2_.y) && (point1_.y <= point3_.y))
     {
       min_y = point1_.y;
       if (point2_.y > point3_.y)
        {
          max_y = point2_.y;
        }
       else
        {
          max_y = point3_.y;
        }
     }
    else
     {
       if ((point2_.y <= point3_.y) && (point2_.y <= point1_.y))
        {
          min_y = point2_.y;
          if (point1_.y > point3_.y)
           {
             max_y = point1_.y;
           }
          else
           {
             max_y = point3_.y;
           }
        }
       else
        {
          if ((point3_.y <= point2_.y) && (point3_.y <= point1_.y))
           {
             min_y = point3_.y;
             if (point2_.y > point1_.y)
              {
                max_y = point2_.y;
              }
             else
              {
                max_y = point1_.y;
              }
           }
        }
    }
  point_t cenRect;
  cenRect.x = (max_x + min_x)/2;
  cenRect.y = (max_y + min_y)/2;
  return {max_x - min_x, max_y - min_y, cenRect};
}

void Triangle::move(const point_t &point)
 {
   centre_ = point;
 }

void Triangle::move(double abs, double ord)
 {
   centre_.x += abs;
   centre_.y += ord;
 }

void Triangle::printTriang()
 {
   std::cout << "Sides: " << side1_ << ", " << side2_ << ", " << side3_ << std::endl;
   std::cout << "Centre of gravity:" << " (" << centre_.x << "," << centre_.y << ")" << std::endl;
 }
