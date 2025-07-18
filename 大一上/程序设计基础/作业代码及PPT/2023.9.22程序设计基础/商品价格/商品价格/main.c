//
//  main.c
//  商品价格
//
//  Created by 杨博文 on 2023/9/22.
//

#include <stdio.h>

/*假设自动售货机出售4种商品，薯片(crisps)、爆米花(popcorn)、巧克力(chocolate)和可乐(cola)，售价分别是每份3.0、2.5、4.0和3.5元。在屏幕上显示以下菜单，用户可以连续查询商品的价格，当查询次数超过5次时，自动退出查询；不到5次时，用户可以选择退出。当用户输入编号1～4，显示相应商品的价格；输入0，退出查询；输入其他编号，显示价格为0。
 [1] Select crisps
 [2] Select popcorn
 [3] Select chocolate
 [4] Select cola
 [0] Exit
*/
int main(void)
{
    int choice, i;
    double price;
    for(i=1; i<= 5;i++)
    {
        printf("[1] Select crisps \n");
        printf("[2] Select popcorn \n");
        printf("[3] Select chocolate \n");
        printf("[4] Select cola \n");
        printf("[0] exit \n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice == 0)
            break;
        switch (choice)
        {
           case 1:
                price=3.0;
                break;
           case 2:
                price=2.5;
                break;
           case 3:
                price=4.0;
                break;
           case 4:
                price=3.5;
                break;
           default:
                price=0.0;
                break;
        }
        printf("price = %0.1f\n", price);
    }
    printf("Thanks \n");
}
