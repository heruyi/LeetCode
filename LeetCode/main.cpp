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
#include "PathSum.hpp"
using namespace std;

void mystery(int n){
    n += 5;
    n /= 10;
    printf("%s\n","**********" + 10 - n);
}

void ProOrderTraverse(TreeNode *tree)
{
    if (tree == NULL)
        return;
    cout << tree->val << " ";
    ProOrderTraverse(tree->left);
    ProOrderTraverse(tree->right);
}

void preOrderTraverse2(TreeNode *root){
    
    stack<TreeNode *> stack;
    TreeNode *pNode = root;
    while (pNode != NULL || !stack.empty()) {
        if (pNode != NULL) {
            cout << pNode->val << " ";
            stack.push(pNode);
            pNode = pNode->left;
        }else{
            TreeNode *node = stack.top();
            pNode = node->right;
            stack.pop();
        }
    }
}

/**

void helper(TreeNode *root,int sum,vector<vector<int>> &rst, vector<int>curr){
    sum -= root->val;
    curr.push_back(root->val);
    if (!root->left && !root->right && sum == 0) {
        rst.push_back(vector<int>(curr));
        return;
    }
    
    if (root->left) {
        helper(root->left, sum, rst, curr);
        curr.pop_back();
    }
    if (root->right) {
        helper(root->right, sum, rst, curr);
        curr.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    
    vector<int> curr;
    
    helper(root, sum, result, curr);
    return result;
}

*/

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    Solution so;
//    vector<int> vector = {3,2,3};
//    so.maxProfit(vector);
//    so.convertToTitle(28);
//    so.isIsomorphic("ab", "aa");
//
    TreeNode a = TreeNode(10);
    TreeNode b = TreeNode(5);
    TreeNode c = TreeNode(-3);
    TreeNode d = TreeNode(3);
    TreeNode e = TreeNode(2);
    TreeNode f = TreeNode(11);
    TreeNode g = TreeNode(3);
    TreeNode h = TreeNode(-2);
    TreeNode i = TreeNode(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    e.right = &i;
    vector<char> ccc{'a','a','b','b','c','c','c'};
    
    vector<int> aa{0,0};
    vector<int> bb{1,0};
    vector<int> cc{-1,0};
    vector<int> dd{0,1};
    vector<int> ee{0,-1};
    vector<vector<int>>ff{aa,bb,cc,dd,ee};
    vector<int>ac{4,3,2,7,8,2,3,1};
    so.findDisappearedNumbers(ac);
//    so.binaryTreePaths(&root);
//    so.reverseVowels("leetcode");
    vector<int> vec = {3,2,1};
//    so.countSegments("Hello, my name is John");
    return 0;
}

//TreeNode * arrayToTree(vector<int> *vet){
//    if (!vet || vet->size() == 0) {
//        return nullptr;
//    }
//
//
//
//}




