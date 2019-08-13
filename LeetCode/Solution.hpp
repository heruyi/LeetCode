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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

struct CharTreeNode {
    char val;
    CharTreeNode *left;
    CharTreeNode *right;
    CharTreeNode(char x) : val(x), left(NULL), right(NULL){}
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
    
    ListNode* mergeKLists(vector<ListNode*>& lists);
    
    //35. 搜索插入位置
    int searchInsert(vector<int>& nums, int target);
    
    ListNode* deleteDuplicates(ListNode* head);
    
    bool isSameTree(TreeNode* p, TreeNode* q);
    
    void sortColors(vector<int>& nums);
    
    vector<string> fizzBuzz(int n);
    
    int hammingDistance(int x, int y);
    
    int findContentChildren(vector<int>& g, vector<int>& s);
    
    int islandPerimeter(vector<vector<int>>& grid);
    
    int maxSubArray(vector<int>& nums);
    
    uint32_t reverseBits(uint32_t n);
    
    vector<vector<int>> generate(int numRows);
    
    int missingNumber(vector<int>& nums);
    
    int lengthOfLastWord(string s);
    
    int minDepth(TreeNode* root);
    
    int maxDepth(TreeNode* root);
    
    bool isBalanced(TreeNode* root);
    
    vector<vector<int>> levelOrderBottom(TreeNode* root);
    
    TreeNode* sortedArrayToBST(vector<int>& nums,int start,int end);
    
    TreeNode* sortedArrayToBST(vector<int>& nums);
    
    void preOrderWithoutRecursion(TreeNode *root);
    
    bool hasPathSum(TreeNode* root, int sum);
    
    vector<int> getRow(int rowIndex);
    
    //121 买卖股票的最佳时机
    int maxProfit(vector<int>& prices);
};

#endif /* Solution_hpp */
