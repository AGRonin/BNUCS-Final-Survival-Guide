//
//  main.c
//  寻找最近点
//
//  Created by 杨博文 on 2023/11/24.
//

#include <stdio.h>
#include <math.h>
/*寻找最近点
 在一个平面上的第一象限中的若干个点中，寻找距离坐标原点最近的点。假设每个点用两个坐标表示。
 定义一个结构体，描述点的信息，可参考如下：
 struct point{
     int x;  //横坐标
     int y;  //纵坐标
 };
 从键盘输入一个整数n (1 <= n < = 100)，表示有n个候选的点，然后输入n个点的横纵坐标。现要从中选出距离原点最近的点并输出，假设距离的值保留两位小数，如果两个点到原点的距离相等，则取横坐标小的点；如果两个点到原点的距离相等且横坐标相等，则取纵坐标小的点。输出的格式为“（横坐标,纵坐标）”。*/
struct point{
    int x;
    int y;
};
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    struct point data[n];
    double min=-1;
    int j=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&data[i].x,&data[i].y);
        if(min==-1 || min*min>data[i].x*data[i].x+data[i].y*data[i].y || (min*min==data[i].x*data[i].x+data[i].y*data[i].y && data[j].x>data[i].x) || (min*min==data[i].x*data[i].x+data[i].y*data[i].y && data[j].x==data[i].x && data[j].y>data[i].y) )
        {
            j=i;
            min=sqrt(data[i].x*data[i].x+data[i].y*data[i].y);
            min=(int)(min*100);
            min=min/100.0;
        }
    }
    printf("(%d,%d)",data[j].x,data[j].y);
    return 0;
}
