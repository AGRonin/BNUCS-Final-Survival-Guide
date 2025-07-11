//
//  main.cpp
//  冒泡排序
//
//  Created by 杨博文 on 2024/6/19.
//

#include <iostream>
#include <vector>
  
// 冒泡排序函数
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
  
// 测试冒泡排序
int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "原始数组：";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
  
    bubbleSort(arr);
  
    std::cout << "排序后的数组：";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
  
    return 0;
}
