//
//  MinStack.cpp
//  LeetCode
//
//  Created by henry on 2019/8/14.
//  Copyright © 2019 henry. All rights reserved.
//

#include "MinStack.hpp"

MinStack::MinStack() {
    this->dataStack = new std::stack<int>();
    this->minStack = new std::stack<int>();
}

void MinStack::push(int x) {
    this->dataStack->push(x);
    if (this->minStack->empty() || x <= this->minStack->top()) {
        this->minStack->push(x);
    }
}

void MinStack::pop() {
    if (this->dataStack->top() == this->minStack->top()	) {
        this->minStack->pop();
    }
    this->dataStack->pop();
}

int MinStack::top() {
    
    return this->dataStack->top();
}

int MinStack::getMin() {
    return this->minStack->top();
}
