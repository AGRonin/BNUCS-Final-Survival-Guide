//
//  main.cpp
//  从1开始的整数数组
//
//  Created by 杨博文 on 2024/5/10.
//

/*实现以下功能：
 创建IntAraay数组arr1, 10个数据。输入arr1的10个数据。
 利用arr1拷贝创建IntAraay数组arr2。
 创建IntAraay数组arr3, 20个数据。 执行 arr3=arr1 .
 分别输出arr1, arr2, arr3 的内容。

 请注意：
 IntAraay类的下标从1开始
 增加拷贝构造函数、重载赋值=函数、输入>>函数、输出<<函数等 */

#include "classIntArray.hpp"

int main(int argc, const char * argv[]) {
    IntArray arr1(10);
    std::cin >> arr1;
    IntArray arr2(arr1),arr3(20);
    arr3=arr1;
    std::cout <<"arr1:"<<arr1<<"arr2:"<<arr2<<"arr3:"<<arr3;
    return 0;
}
