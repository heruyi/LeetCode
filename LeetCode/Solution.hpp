//
//  Solution.hpp
//  LeetCode
//
//  Created by henry on 6/4/2019.
//  Copyright © 2019 henry. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    int removeElement(vector<int>& nums, int val);
    
    bool isPalindrome(int x);
    
    int romanToInt(string s);
    
    string longestCommonPrefix(vector<string>& strs);
    
    bool isValid(string s);
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    
    vector<int> plusOne(vector<int>& digits);
    
    string addBinary(string a, string b);
    
    int strStr(string haystack, string needle);
    
    int lengthOfLongestSubstring(string s);
    
    int singleNumber(vector<int>& nums);
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    
    void moveZeroes(vector<int>& nums);

    int myAtoi(string str);
    
    vector<int> twoSum(vector<int>& nums, int target);
    
    bool isValidSudoku(vector<vector<string>>& board);
    
    void rotate(vector<vector<int>>& matrix);
    
    void reverseString(vector<char>& s);
    
    bool isPalindrome(string s);
    
    bool isAnagram(string s, string t);
    
    int reverse(int x);
    
    int firstUniqChar(string s);

    ListNode* removeNthFromEnd(ListNode* head, int n);
    
    ListNode* reverseList(ListNode* head);

    bool isPalindrome(ListNode* head);
};

#endif /* Solution_hpp */
