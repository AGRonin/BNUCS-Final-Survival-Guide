//
//  main.c
//  大写字母转换为小写字母
//
//  Created by 杨博文 on 2023/10/13.
//

#include <stdio.h>
/*输入一个字符，判断它是否为大写字母，如果是，将它转换为小写字母；如果不是，不转换。然后输出最后得到的字符。
输入一个字符
输出一个字符，末尾输出换行。*/
int main()
{
    char a;
    a=getchar();
    if(a>='A' && a<='Z')
        a=a+32;
    putchar(a);
    return 0;
}
