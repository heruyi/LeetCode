//
//  MinStack.hpp
//  LeetCode
//
//  Created by henry on 2019/8/14.
//  Copyright © 2019 henry. All rights reserved.
//

#ifndef MinStack_hpp
#define MinStack_hpp

#include <stdio.h>
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    
    std::stack<int> *dataStack;
    std::stack<int> *minStack;
    
    MinStack();
    
    void push(int x);
    
    void pop();
    
    int top();
    
    int getMin();
};


#endif /* MinStack_hpp */
