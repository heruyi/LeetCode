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
    vector<int> num1 = {9};
    vector<int> num2 = {3,2,2,3};
//    so.merge(num1, 3, num2, 3);
//    so.longestCommonPrefix(strs);
    so.plusOne(num1);
    string ss = so.addBinary("11", "1");
    cout << ss;
    
//    so.removeElement(num2, 3);
//    so.strStr("hello", "ll");
//    so.lengthOfLongestSubstring("abba");
    vector<int> v1 = {0,1,0,3,2};
    vector<int> v2 = {2,2};
//    so.intersect(v1, v2);
//    so.moveZeroes(v1);
//    so.myAtoi(" -42");
    
    
    vector<int> v3 = {3,2,4};
//    so.twoSum(v3, 6);
    vector<vector<string>> vc = {
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    };
    
    vector<vector<int>> vt = {
        {24,4,38,2,21,18,33,40},
        {24,37,25,62,37,15,35,36},
        {42,23,13,58,17,26,19,8},
        {32,48,9,58,36,18,40,61},
        {23,16,0,46,35,34,23,60},
        {9,49,60,47,1,32,20,45},
        {56,34,40,11,61,60,20,30},
        {45,30,25,18,49,3,16,10}};
    so.rotate(vt);

    
    return 0;
}

