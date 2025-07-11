//
//  main.c
//  2024年月历打印
//
//  Created by 杨博文 on 2024/2/29.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int month,day,start;
    scanf("%d",&month);
    switch(month)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            day=31;
            break;
        case 2:
            day=29;
            break;
        default:
            day=30;
            break;
    }
    switch (month) 
    {
        case 1:case 4:case 7:
            start=1;
            break;
        case 2:case 8:
            start=4;
            break;
        case 3:case 11:
            start=5;
            break;
        case 5:
            start=3;
            break;
        case 6:
            start=6;
            break;
        case 9:case 12:
            start=0;
            break;
        default:
            start=2;
            break;
    }
    printf("日  一  二  三  四  五  六\n");
    int j=0;
    for(int i=1-start;i<=day;i++)
    {
        if(i<=0)
            printf(" ");
        else if(i<10)
            printf(" %d",i);
        else
            printf("%d",i);
        j++;
        if(j%7==0)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
