//
//  main.c
//  字符串后移
//
//  Created by 杨博文 on 2023/11/17.
//

#include <stdio.h>
#include <string.h>
/*给出一个字符串s，把s循环右移n位，然后输出循环右移后的字符串。
 输入 输入共两行，第一行为一整数n，表示将字符串s右移n位，第二行为字符串s（s为长度小于10000位的字符串）
 输出只有一行，为右移后字符串*/
int main(int argc, const char * argv[]) {
    int n,k;
    scanf("%d\n",&n);
    char list[10001];
    scanf("%s",list);
    k=strlen(list);
    printf("%s",list+k-n);
    for(int m=0;m<k-n;m++)
        printf("%c",list[m]);
    return 0;
}
