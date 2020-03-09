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
/**
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
    vector<int> vector{3,1,4,1,5};
    so.quickSort(vector, 0, 4);

    return 0;
 
}





