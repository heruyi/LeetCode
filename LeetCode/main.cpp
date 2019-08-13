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



int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    Solution so;
    vector<int> vector = {2,4,1};
    so.maxProfit(vector);
    return 0;
}




