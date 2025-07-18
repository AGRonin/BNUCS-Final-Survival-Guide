//
//  main.c
//  高考成绩输出
//
//  Created by 杨博文 on 2023/12/1.
//

#include <stdio.h>
/*定义一个学生结构体，数据成员包括考生序号，姓名，考生地区代号（字母），高考成绩（理科，文科）。定义函数：输入学生信息函数setStudent，输出学生信息函数printStudent，
 要求实现以下功能：
 （1）输入高校衡量标准（1代表理科，2代表文科，不是1,2则输出I do not know whether the standard is liberal arts or science.）
 （2）输入7个同学数据；
 （3）根据指定高校衡量标准，按照成绩倒序输出7个同学的所有数据。（按照输入标准衡量，以理科为例，若理科成绩相同，则按照文科成绩衡量，若两者均相同，排序时把考生序号较大的排在前面即可）
 样例输入
 1
 1001011 王丽 F 654 624
 1001012 李军 M 667 610
 1001013 赵斌 M 667 608
 1001014 赵妍 N 688 670
 1001015 王军 V 688 670
 1001016  宋芳凝 R 703 624
 1001017 高华 X 601 634
 样例输出
 1001016 宋芳凝 R 703 624
 1001015 王军 V 688 670
 1001014 赵妍 N 688 670
 1001012 李军 M 667 610
 1001013 赵斌 M 667 608
 1001011 王丽 F 654 624
 1001017 高华 X 601 634
 提示 若衡量标准不明（输入的不是1或2），则我们认为输出时按照输入学号由大到小倒序输出（此时不必按照成绩排序）*/
struct data
{
    int xuehao;
    char name[20];
    char location[20];
    int like;
    int wenke;
}studata[7];
void setStudent(struct data *p)
{
    for(int i=0;i<7;i++,p++)
    {
        scanf("%d%s%s%d%d",&(*p).xuehao,(*p).name,(*p).location,&(*p).like,&(*p).wenke);
    }
}
void printStudent(struct data *p,int biaozhun)
{
    if(biaozhun==0)
    {
        for(int i=0;i<7;i++)//七次输出
        {
            int shuchu=0,maxxuehao=0;
            struct data *pt;
            pt=p;
            for(int j=0;j<7;j++,pt++)//七次判断
            {
                if(pt->xuehao>maxxuehao)
                {
                    shuchu=j;
                    maxxuehao=pt->xuehao;
                }
            }
            pt=p+shuchu;
            pt->xuehao=0;
            printf("%d %s %s %d %d\n",maxxuehao,pt->name,pt->location,pt->like,pt->wenke);
        }
    }
    if(biaozhun==1)
    {
        for(int i=0;i<7;i++)//七次输出
        {
            int shuchu=0,maxlike=0,maxwenke=0,maxxuehao=0;
            struct data *pt;
            pt=p;
            for(int j=0;j<7;j++,pt++)//七次判断
            {
                if(pt->like >maxlike || (pt->like==maxlike && pt->wenke>maxwenke) || (pt->like==maxlike && pt->wenke==maxwenke && pt->xuehao>maxxuehao))
                {
                    shuchu=j;
                    maxlike=pt->like;
                    maxwenke=pt->wenke;
                    maxxuehao=pt->xuehao;
                }
            }
            pt=p+shuchu;
            pt->like=0;
            printf("%d %s %s %d %d\n",maxxuehao,pt->name,pt->location,maxlike,maxwenke);
        }
    }
    if(biaozhun==2)
    {
        for(int i=0;i<7;i++)//七次输出
        {
            int shuchu=0,maxlike=0,maxwenke=0,maxxuehao=0;
            struct data *pt;
            pt=p;
            for(int j=0;j<7;j++,pt++)//七次判断
            {
                if(pt->wenke >maxwenke || (pt->wenke==maxwenke && pt->like>maxlike) || (pt->wenke==maxwenke && pt->like==maxlike && pt->xuehao>maxxuehao))
                {
                    shuchu=j;
                    maxlike=pt->like;
                    maxwenke=pt->wenke;
                    maxxuehao=pt->xuehao;
                }
            }
            pt=p+shuchu;
            pt->wenke=0;
            printf("%d %s %s %d %d\n",maxxuehao,pt->name,pt->location,maxlike,maxwenke);
        }
    }
}
int main(int argc, const char * argv[]) {
    int biaozhun;
    scanf("%d",&biaozhun);
    struct data *p;
    p=studata;
    setStudent(p);
    if(biaozhun!=1 && biaozhun!=2)
    {
        biaozhun=0;
        printf("I do not know whether the standard is liberal arts or science.\n");
    }
    p=studata;
    printStudent(p,biaozhun);
    return 0;
}
