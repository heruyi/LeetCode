//
//  Person.hpp
//  LeetCode
//
//  Created by henry on 2019/4/1.
//  Copyright © 2019 henry. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
class Person {
public:
    char *name;
    unsigned int age;
    Person(char *_name,unsigned int _age);
    Person(const Person &);
    Person();
    ~Person();
    Person & operator=(const Person &);
};
#endif /* Person_hpp */
