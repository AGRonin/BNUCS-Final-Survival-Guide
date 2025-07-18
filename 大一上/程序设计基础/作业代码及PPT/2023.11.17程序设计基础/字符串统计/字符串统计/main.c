//
//  main.c
//  字符串统计
//
//  Created by 杨博文 on 2023/11/21.
//

#include <stdio.h>
/*输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数。
 输入一行字符
 输出统计值 中间用空格隔开*/
int main(int argc, const char * argv[]) {
    char zifuchuan[80];
    gets(zifuchuan);
    char *zhizhen;
    int english=0,number=0,space=0,more=0;
    for(zhizhen=zifuchuan;*zhizhen!='\0';*zhizhen++)
    {
        if((*zhizhen>='A' && *zhizhen<='Z')||(*zhizhen>='a' && *zhizhen<='z'))
            english++;
        else if(*zhizhen>='0' && *zhizhen<='9')
            number++;
        else if(*zhizhen==' ')
            space++;
        else
            more++;
    }
    printf("%d %d %d %d",english,number,space,more);
    return 0;
}
