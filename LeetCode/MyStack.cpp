//
//  MyStack.cpp
//  LeetCode
//
//  Created by henry on 2019/8/19.
//  Copyright © 2019 henry. All rights reserved.
//

#include "MyStack.hpp"

MyStack::MyStack() {
    this->queue = new std::deque<int>();
}

/** Push element x onto stack. */
void MyStack::push(int x){
    this->queue->push_front(x);
}

/** Removes the element on top of the stack and returns that element. */
int MyStack::pop(){
   	int top = this->queue->front();
	this->queue->pop_front();
    return top;
}

/** Get the top element. */
int MyStack::top(){
    return this->queue->front();
}

/** Returns whether the stack is empty. */
bool MyStack::empty(){
    return this->queue->empty();
}
