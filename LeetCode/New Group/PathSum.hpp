//
//  PathSum.hpp
//  LeetCode
//
//  Created by henry on 2019/8/23.
//  Copyright © 2019 henry. All rights reserved.
//

#ifndef PathSum_hpp
#define PathSum_hpp
#include "Solution.hpp"
#include <stdio.h>


class Solution1 {
public:
    
    /**
    
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        res = 0;
        allPath(root, sum);
        return res;
    }
private:
    int res;
        //遍历每个结点
    void allPath(TreeNode* root, int sum){
        if(!root) return;
        dfs(root, sum);
        allPath(root->left, sum);
        allPath(root->right, sum);
    }
        //寻找以root为起始点的路径数
    void dfs(TreeNode* root, int sum){
        if(!root) return;
        if(root->val == sum) {
            res += 1;
        }
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        return ;
    }
     
     */
    int res;
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        
        res = 0;
        map<int,int> map; // map<currentSum,sumCount>
        map[0] = 1;
        findPath(root, sum, 0, map);
        return res;
    }
    
    void findPath(TreeNode *root,int sum,int currentSum,map<int,int> &map){
        if (!root) {
            return;
        }
        currentSum = currentSum + root->val;
        res += map[currentSum - sum];
        map[currentSum]++;
        findPath(root->left, sum, currentSum, map);
        findPath(root->right, sum, currentSum, map);
        map[currentSum]--;
    }
};

#endif /* PathSum_hpp */
