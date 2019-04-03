//
//  base-types.hpp
//  A1
//
//  Created by Никита Пурнов on 27.03.2019.
//  Copyright © 2019 Никита Пурнов. All rights reserved.
//

#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
    double x;
    double y;
};

struct rectangle_t
{
    double width;
    double height;
    point_t pos;
};

#endif 

