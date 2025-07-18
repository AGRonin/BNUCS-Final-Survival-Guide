//
//  main.c
//  用指针数组对多个字符串进行排序
//
//  Created by 杨博文 on 2023/12/15.
//

#include <stdio.h>
#include <string.h>

void fsort(char *color[ ], int n)
{     
    int k, j;
    char *temp;
    for(k = 1; k < n; k++)
    {
        for(j = 0; j < n-k; j++)
        {
            if(strcmp(color[j],color[j+1])>0)
            {
                temp = color[j];
                color[j] = color[j+1];
                color[j+1] = temp;
            }
        }
    }
}

int main(void)
{   
    int i;
    char  *pcolor[5]={ "red",  "blue",  "yellow", "green",  "purple" };
    fsort( pcolor, 5 ); 
    for(i = 0; i < 5; i++) 
        printf("%s ", pcolor[i]);
     return 0;
}   
