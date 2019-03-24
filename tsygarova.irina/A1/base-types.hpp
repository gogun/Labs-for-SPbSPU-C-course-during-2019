//
//  base-types.hpp
//  A1
//
//  Created by Ирина on 23.03.2019.
//  Copyright © 2019 Ирина. All rights reserved.
//

#ifndef base_types_h
#define base_types_h

struct point_t
{
  double x;
  double y;
};
struct rectangle_t
{
  double width_;
  double height_;
  point_t pos_;
};
#endif /* base_types_hpp */
