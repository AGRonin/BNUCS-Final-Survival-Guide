//
//  classSum.hpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#ifndef classSum_hpp
#define classSum_hpp

#include <iostream>
//抽象类
class Sum
{
public:
    virtual ~Sum(){};
    virtual void Show() =0;
    virtual void Add(Sum* num) =0;
};

#endif /* classSum_hpp */
