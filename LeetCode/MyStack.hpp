//
//  MyStack.hpp
//  LeetCode
//
//  Created by henry on 2019/8/19.
//  Copyright © 2019 henry. All rights reserved.
//

#ifndef MyStack_hpp
#define MyStack_hpp


#include <stdio.h>
#include <deque>

class MyStack {
    
public:
    /** Initialize your data structure here. */
    std::deque<int> *queue;
    
    MyStack();
    
    /** Push element x onto stack. */
    void push(int x);
    
    /** Removes the element on top of the stack and returns that element. */
    int pop();
    
    /** Get the top element. */
    int top();
    
    /** Returns whether the stack is empty. */
    bool empty();
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

#endif /* MyStack_hpp */
