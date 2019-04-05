#include "Triangle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

Triangle::Triangle(const point_t &pA,const point_t &pB,const point_t &pC):
  point_a_(pA),
  point_b_(pB),
  point_c_(pC),
  center_({(pA.x+pB.x+pC.x)/3,(pA.y+pB.y+pC.y)/3})
{
  if(getArea() <= 0)
  {
    throw std::invalid_argument("Invalid triangle parameters!");
  }
}
double Triangle::getDistance(const point_t &point_1,const point_t &point_2) const
{
  return sqrt((point_1.x-point_2.x)*(point_1.x-point_2.x) + (point_1.y-point_2.y)*(point_1.y-point_2.y));
}
void Triangle::move(const double dx,const double dy)
{
  point_a_.x += dx;
  point_b_.x += dx;
  point_c_.x += dx;
  center_.x += dx;
  point_a_.y += dy;
  point_b_.y += dy;
  point_c_.y += dy;
  center_.y += dy;
}
void Triangle::move(const point_t &new_p)
{
  move(new_p.x-center_.x,new_p.y-center_.y);
  center_ = new_p;
}
double Triangle::getArea() const
{
  double ab= getDistance(point_a_,point_b_);
  double bc= getDistance(point_b_,point_c_);
  double ca= getDistance(point_c_,point_a_);
  double p= (ab+bc+ca)/2;
  return sqrt(p*(p-ab)*(p-bc)*(p-ca));
}
rectangle_t Triangle::getFrameRect() const
{
  rectangle_t frameshapes;
  frameshapes.height= abs(max(max(point_a_.y,point_b_.y),point_c_.y) - min(min(point_a_.y,point_b_.y),point_c_.y));
  frameshapes.width = abs(max(max(point_a_.x,point_b_.x),point_c_.x) - min(min(point_a_.x,point_b_.x),point_c_.x));
  frameshapes.pos.x = min(min(point_a_.x,point_b_.x),point_c_.x) +frameshapes.width/2;
  frameshapes.pos.y = min(min(point_a_.y,point_b_.y),point_c_.y) +frameshapes.height/2;
  return frameshapes;
}
void Triangle::print() const
{
  cout<<"----Triangle: \n";
  cout<<"  A:( "<<point_a_.x<<", "<<point_a_.y<<") \t B:( "<<point_b_.x<<", "<<point_b_.y<<") \t C:( "<<point_c_.x<<", "<<point_c_.y<<") \n";
  cout<<"  center: ("<<center_.x<<", "<<center_.y<<") \n";
  cout<<"  Area= "<<getArea()<<endl;
  cout<<"  FrameRect for Triangle: \n";
  cout<<"     center: ("<<getFrameRect().pos.x<<", "<<getFrameRect().pos.y<<") width= "<<getFrameRect().width<<" height= "<<getFrameRect().height<<endl;
}
