//
//  main.c
//  求阶乘和
//
//  Created by 杨博文 on 2023/9/16.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*用函数求5！+7！+9！+11！的值。
     无输入
     输出所求的和。 */
    int i,he,j,ji;
    he=0;
    for(i=5;i<=11;i=i+2)
    {
        ji=1;
        for(j=1;j<=i;j++)
        {
            ji=ji*j;
        }
        he=he+ji;
    }
    printf("%d",he);
    return 0;
}
