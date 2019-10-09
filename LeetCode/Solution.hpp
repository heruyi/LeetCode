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

typedef struct _Point{
public:
    int x;
    int y;
    _Point(int x,int y) : x(x), y(y) {};
    _Point(){}
}_Point;

struct cmplKey{
public:
    bool operator()(const _Point &k1, const _Point &k2) const {
        return (k1.x != k2.x || k1.y != k2.y);
    }
};

class Node {
public:
    int val;
    vector<Node*> children;
    
    Node() {}
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
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
    //141 环形链表
    bool hasCycle(ListNode *head);
    //160 相交链表
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    ///168 Excel表列名称
    string convertToTitle(int n);
    ///169 求众数
    int majorityElement(vector<int>& nums);
    ///171.Excel表列序号
    int titleToNumber(string s);
    ///198 打家劫舍
    int rob(vector<int>& nums);
    ///203 移除链表元素
    ListNode* removeElements(ListNode* head, int val);
    ///204 计数质数
    int countPrimes(int n);
    ///205 同构字符串
    bool isIsomorphic(string s, string t);
    ///219 存在重复元素 II
    bool containsNearbyDuplicate(vector<int>& nums, int k);
    ///226 翻转二叉树
    TreeNode* invertTree(TreeNode* root) ;
    ///257 二叉树的所有路径
    vector<string> binaryTreePaths(TreeNode* root);
    ///258 各位相加
    int addDigits(int num);
    ///290 单词规律
    bool wordPattern(string pattern, string str);
    ///345 反转字符串中的元音字母
    string reverseVowels(string s);
    ///349 两个数组的交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
    ///400 第N个数字
    int findNthDigit(int n);
    ///405 数字转换为十六进制数
    string toHex(int num);
    ///414 第三大的数
    int thirdMax(vector<int>& nums);
    ///415字符串相加
    string addStrings(string num1, string num2);
    ///429 N叉树的层序遍历
    vector<vector<int>> levelOrder(Node* root);
    ///434 字符串中的单词数
    int countSegments(string s);
    ///438. 找到字符串中所有字母异位词
    vector<int> findAnagrams(string s, string p);
    ///441 排列硬币
    int arrangeCoins(int n);
    ///443.压缩字符串
    int compress(vector<char>& chars);
    ///445.两数相加 II
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    ///447.回旋镖的数量
    int numberOfBoomerangs(vector<vector<int>>& points);
    ///448.找到所有数组中消失的数字
    vector<int> findDisappearedNumbers(vector<int>& nums);
    ///459.重复的字符串
    bool repeatedSubstringPattern(string s);
    ///475.供暖器
    int findRadius(vector<int>& houses, vector<int>& heaters);
    ///476.数字的补数
    int findComplement(int num);
    ///482.密匙格式化
    string licenseKeyFormatting(string S, int K);
    ///485.最大的连续1的个数
    int findMaxConsecutiveOnes(vector<int>& nums);
    ///492.构造矩形
    vector<int> constructRectangle(int area);
    ///下一个更大元素
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);
    ///500.键盘行
    vector<string> findWords(vector<string>& words);
    ///506.相对名次
    vector<string> findRelativeRanks(vector<int>& nums);
    ///520.检测大写字母
    bool detectCapitalUse(string word) ;
    ///532.数组中的K-diff数对
    int findPairs(vector<int>& nums, int k);
    ///538.把二叉搜索树转换为累加树
    TreeNode* convertBST(TreeNode* root);
};

#endif /* Solution_hpp */
