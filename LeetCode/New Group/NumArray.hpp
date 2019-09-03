//
//  NumArray.hpp
//  LeetCode
//
//  Created by henry on 2019/8/21.
//  Copyright © 2019 henry. All rights reserved.
//

#ifndef NumArray_hpp
#define NumArray_hpp

#include <stdio.h>
#include <vector>
using namespace std;
class NumArray {
    
public:
    vector<int> vet;
    size_t size;
    NumArray(vector<int>& nums) {
        size = nums.size();
        if (size > 0) {
            vet = vector<int>(nums.size(),0);
            vet[0] = nums[0];
            for (int i=1; i<nums.size(); i++) {
                vet[i] = vet[i-1] + nums[i];
            }
        }
    }
    
    int sumRange(int i, int j) {
        if (size == 0) {
            return 0;
        }
        if (i==0) {
            return vet[j];
        }
        return vet[j] - vet[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
#endif /* NumArray_hpp */
