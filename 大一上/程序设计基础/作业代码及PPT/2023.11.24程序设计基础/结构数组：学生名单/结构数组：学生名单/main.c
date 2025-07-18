//
//  main.c
//  结构数组：学生名单
//
//  Created by 杨博文 on 2023/11/24.
//

#include <stdio.h>
/*定义一个学生结构体，数据成员包括学号，姓名，性别，生日（年月日），然后输出3个同学的数据。
 输出
 1001011 王丽 F 1995/10/12
 1001012 李军 M 1995/5/24
 1001013 赵斌 M 1994/2/25 */
struct student {
    int number;
    char name[10];
    char gender[10];
    char birthday[20];
};
int main(int argc, const char * argv[]) {
    struct student liebiao[3]={{1001011,"王丽","F","1995/10/12"},{1001012,"李军","M","1995/5/24"},{1001013,"赵斌","M","1994/2/25"}};
    for(int i=0;i<3;i++)
    {
        printf("%d %s %s %s\n",liebiao[i].number,liebiao[i].name,liebiao[i].gender,liebiao[i].birthday);
    }
    return 0;
}
