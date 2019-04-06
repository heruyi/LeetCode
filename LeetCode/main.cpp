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



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution so;
    vector<string> strs = {"flower","flow","flight"};
    vector<int> num1 = {1,0,0};
    vector<int> num2 = {3,2,2,3};
//    so.merge(num1, 3, num2, 3);
//    so.longestCommonPrefix(strs);
//    so.plusOne(num1);
    string ss = so.addBinary("11", "1");
    cout << ss;
    
//    so.removeElement(num2, 3);
//    so.strStr("hello", "ll");
    so.lengthOfLongestSubstring("abba");
    
    return 0;
}
