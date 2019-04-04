//
//  Person.cpp
//  LeetCode
//
//  Created by henry on 2019/4/1.
//  Copyright © 2019 henry. All rights reserved.
//

#include "Person.hpp"
#include <string>

Person::Person(){
    name = new char[3];
    strcpy(name, "C++");
    age = 20;
}

Person::Person(char *_name, unsigned int _age){
    name = new char[strlen(_name)+1];
    std::strcpy(name, _name);
    age = _age;
}

Person::Person(const Person & p){
    name = new char[strlen(p.name)+1];
    strcpy(name, p.name);
    age = p.age;
}

Person & Person::operator=(const Person & p) {
    if (&p == this) {
        return *this;
    }
    delete [] name;
    name = new char[strlen(p.name+1)];
    strcpy(name, p.name);
    age = p.age;
    return *this;
}

Person::~Person(){
    delete [] name;
}

