//
//  main.cpp
//  邻域均值
//
//  Created by 杨博文 on 2024/7/3.
//

/*顿顿在学习了数字图像处理后，想要对手上的一副灰度图像进行降噪处理。
 不过该图像仅在较暗区域有很多噪点，如果贸然对全图进行降噪，会在抹去噪点的同时也模糊了原有图像。
 因此顿顿打算先使用邻域均值来判断一个像素是否处于较暗区域，然后仅对处于较暗区域的像素进行降噪处理。
 待处理的灰度图像长宽皆为 n 个像素，可以表示为一个 n×n 大小的矩阵 A，其中每个元素是一个 [0,L) 范围内的整数，表示对应位置像素的灰度值。
 对于矩阵中任意一个元素 Aij（0≤i,j<n），其邻域定义为附近若干元素的集和：
 Neighbor(i,j,r)={Axy|0≤x,y<n and |x−i|≤r and |y−j|≤r}
 这里使用了一个额外的参数 r 来指明 Aij 附近元素的具体范围。
 根据定义，易知 Neighbor(i,j,r) 最多有 (2r+1)2 个元素。
 如果元素 Aij 邻域中所有元素的平均值小于或等于一个给定的阈值 t，我们就认为该元素对应位置的像素处于较暗区域。
 现给定邻域参数 r 和阈值 t，试统计输入灰度图像中有多少像素处于较暗区域。
 输入格式
 输入共 n+1 行。
 输入的第一行包含四个用空格分隔的正整数 n、L、r 和 t，含义如前文所述。
 第二到第 n+1 行输入矩阵 A。第 i+2（0≤i<n）行包含用空格分隔的 n 个整数，依次为 Ai0,Ai1,⋯,Ai(n−1)。
 输出格式
 输出一个整数，表示输入灰度图像中处于较暗区域的像素总数。*/
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,L,r,t;
    cin>>n>>L>>r>>t;
    int A[n+1][n+1];
    int sum;
    int hengqianzhuiHe[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        sum=0;
        for(int j=0;j<=n;j++)
        {
            if(i*j==0)
            {
                A[i][j]=0;
            }
            else
            {
                cin>>A[i][j];
            }
            sum+=A[i][j];
            hengqianzhuiHe[i][j]=sum;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            hengqianzhuiHe[i][j]+=hengqianzhuiHe[i-1][j];
        }
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x1,y1,x2,y2;
            x1=max(i-r,0);
            y1=max(j-r,0);
            x2=min(i+r,n);
            y2=min(j+r,n);
            int sum;
            sum=hengqianzhuiHe[x2][y2]-hengqianzhuiHe[x1][y2]-hengqianzhuiHe[x2][y1]+hengqianzhuiHe[x1][y1];
            if(t*(x2-x1+1)*(y2-y1+1)>=sum)
            {
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}
