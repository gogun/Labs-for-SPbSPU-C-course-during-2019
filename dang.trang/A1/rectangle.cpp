#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include <iostream>
Rectangle::Rectangle(double Wid, double Hei, double xrect, double yrect):
  rrect{Wid,Hei,{xrect,yrect}}
  {}
double Rectangle::getArea() const
{
  return rrect.height*rrect.width;
}
rectangle_t Rectangle::getFrameRect() const
{
  return {rrect.height , rrect.width , rrect.pos.x , rrect.pos.y};
}
void Rectangle::move(const double mX,const double mY)
{
  rrect.pos.x += mX;
  rrect.pos.y += mY;
}
void Rectangle::move(const point_t point)
{
  rrect.pos.x = point.x;
  rrect.pos.y = point.y;
}
void Rectangle::dataoutput() const
{
  std::cout<<"area_of_rectangle_="<<getArea()<<std::endl;
  std::cout<<"framerect_width_height_X_Y_="<<getFrameRect().width<<" "<<getFrameRect().height<<" ";
  std::cout<<getFrameRect().pos.x<<" "<<getFrameRect().pos.y<<std::endl;
  std::cout<<"position_X_Y_"<<rrect.pos.x<<" "<<rrect.pos.y<<std::endl;
}
