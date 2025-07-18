//
//  prime.c
//  求孪生素数
//
//  Created by 杨博文 on 2023/10/20.
//

#include "prime.h"
int prime(int a)
{
    int b;
    for(b=2;b*b<=a;b++)
    {
        if(a%b==0)
        {
            return 0;
        }
    }
    return 1;
}
