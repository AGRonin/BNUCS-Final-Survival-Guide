//
//  main.c
//  百分制转换为等级制（switch版）
//
//  Created by 杨博文 on 2023/10/13.
//

#include <stdio.h>
/*从键盘输入一百分制成绩，要求输出其所对应的等级'A', 'B', 'C', 'D'。85分以上（含）为'A'，70~84分之间为'B'，60~69分之间为'C'，60分以下为'D'。
 用switch语句
 输入百分制成绩，保证成绩在0~100之间。
 输出百分制成绩所对应的等级，末尾输出换行。*/
int main(int argc, const char * argv[]) {
    int a;
    char b;
    scanf("%d",&a);
    switch(a)
    {
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
        case 98:
        case 99:
        case 100:
            b='A';
            break;
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
            b='B';
            break;
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
            b='C';
            break;
        default:
            b='D';
            break;
    }
    printf("%c\n",b);
    return 0;
}
