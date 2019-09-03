//
//  MyQueue.hpp
//  LeetCode
//
//  Created by henry on 2019/8/20.
//  Copyright © 2019 henry. All rights reserved.
//

#ifndef MyQueue_hpp
#define MyQueue_hpp

#include <stdio.h>
#include <stack>
class MyQueue {
public:
    /** Initialize your data structure here. */
    
    std::stack<int> *st1;
    std::stack<int> *st2;

    MyQueue() {
        st1 = new std::stack<int>();
        st2 = new std::stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1->push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        if (st2->empty()) {
            while (!st1->empty()) {
                st2->push(st1->top());
                st1->pop();
            }
        }
        int top = st2->top();
        st2->pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        
        if (st2->empty()) {
            while (!st1->empty()) {
                st2->push(st1->top());
                st1->pop();
            }
        }
        return st2->top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1->empty() && st2->empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
#endif /* MyQueue_hpp */
