//
//  main.cpp
//  大数质因数分解
//
//  Created by 杨博文 on 2024/7/1.
//

#include <iostream>
#include <cmath>

int findLargerPrimeFactor(int n) {
    for (int i = std::sqrt(n); i >= 2; i--) {
        if (n % i == 0)
        {
            return n/i;
        }
    }
    return 0;
}
  
int main() {
    int n;
    std::cin >> n;
    int largerPrime = findLargerPrimeFactor(n);
    std::cout << largerPrime;
    return 0;
}
