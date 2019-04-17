//
//  main.cpp
//  LeetCode
//
//  Created by henry on 2019/4/1.
//  Copyright © 2019 henry. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include "Solution.hpp"
using namespace std;

void mystery(int n){
    n += 5;
    n /= 10;
    printf("%s\n","**********" + 10 - n);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution so;
    so.firstUniqChar("leetcode");
    mystery(49);


    return 0;
}

