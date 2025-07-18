//
//  main.c
//  富豪排行榜
//
//  Created by 杨博文 on 2023/11/24.
//

#include <stdio.h>
/*富豪排行榜
 1917年创立的福布斯杂志，在编制各种排行榜方面有97年历史，1982年首次推出富豪榜在全球产生空前影响，现在，一年一度的福布斯全球亿万富翁榜在全世界受到密切关注。福布斯每年编制一百多个有关人物、公司和生活时尚排行榜，在全球范围内，福布斯富豪榜的江湖地位毋庸置疑。他云集了世界各地的富豪们。
 定义一个结构体，描述富豪们的信息，可参考如下：
 struct magnate{
     char name[20];  //姓名
     double property;//财产，以亿元为单位。
 };
 从键盘输入两个整数n (1 <= n < = 100)和k ( 1<= k <= n )，表示有n位候选人，要从中选出排名前k位的富豪，然后是n位候选人的名字和财产（亿元）。 （名字是由不超过20个字母组成的字符串 ,任意两个人的财产都不一样）。要求输出排名前K的富豪的名字和财产，按财产从大到小排序（每位富豪的数据占一行，其中姓名和财产之间用一个空格分隔）。
 输入
 5 3
 Ffdixdmd 272.47
 Avmje 151.07
 Gtbhp 197.87
 Brjcxz 159.74
 Mtrqmeq 28.79
 输出
 Ffdixdmd 272.47
 Gtbhp 197.87
 Brjcxz 159.74 */
struct magnate
{
    char name[20];
    double property;
};
int main(int argc, const char * argv[])
{
    int n,k;
    scanf("%d %d",&n,&k);
    struct magnate list[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s%lf",list[i].name,&list[i].property);
    }
    double max=0;
    int maxp=0,j;
    int flag[n];
    for(int i=0;i<n;i++)
        flag[i]=0;
    for(int i=0;i<k;i++)
    {
        max=0;
        maxp=0;
        for(j=0;j<n;j++)
        {
            if(flag[j]==1)
                continue;
            if(list[j].property>max)
            {
                max=list[j].property;
                maxp=j;
            }
        }
        printf("%s %.2lf\n",list[maxp].name,list[maxp].property);
        flag[maxp]=1;
    }
    return 0;
}
