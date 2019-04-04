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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        unsigned int _x = x;
        unsigned int num = 0;
        while (x != 0) {
            num = num * 10 +  x % 10;
            x /= 10;
        }
        return _x == num;
    }
    
    int romanToInt(string s) {
        std::map<char,int> map = {{'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        bool b = false;
        char last_c = NULL;
        unsigned int value = 0;
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            value += (*map.find(c)).second;
            bool flag = false;
            if (b) {
                if (last_c == 'X') {
                    if (c == 'L' || c == 'C') {
                        flag = true;
                    }
                }
                if (last_c == 'I') {
                    if (c == 'V' || c == 'X') {
                        flag = true;
                    }
                }
                if (last_c == 'C') {
                    if (c == 'D' || c == 'M') {
                        flag = true;
                    }
                }
            }
            
            
            if (flag) {
                value -= 2 * (*map.find(last_c)).second;
            }
            
            if (c == 'I' || c == 'X' || c == 'C') {
                b = true;
                last_c = c;
            }else{
                b = false;
            }
        }
        
        return value;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return string("");
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        
        for (int i=0; i<strs[0].length(); i++) {
            char c = strs[0][i];

            for (int j=1; j<strs.size(); j++) {
                if (i == strs[j].length()) {
                    return strs[j];
                }
                if (c != strs[j][i]) {
                    return strs[0].substr(0,i);
                }
            }
            
        }

        return strs[0];
    }
    
    bool isValid(string s) {
        stack<char> stc = stack<char>();
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                stc.push(')');
            }else if(s[i] == '['){
                stc.push(']');
            }else if(s[i] == '{'){
                stc.push('}');
            }else{
                if (stc.empty()) {
                    return false;
                }
                if (stc.top() != s[i]) {
                    return false;
                }
                stc.pop();
            }
        }
        
        return stc.empty();
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0) ;
        ListNode *current = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val ) {
                current->next = l1;
                l1 = l1->next;
                current = current->next;
            }else{
                current->next = l2;
                l2 = l2->next;
                current = current->next;
            }
        }
        if (l1 != NULL) {
            current->next = l1;
        }
        if (l2 != NULL) {
            current->next = l2;
        }
        return head->next;
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if (n == 0) {
            return;
        }
        if (m == 0) {
            for (int i=0; i<n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        }
        
        int i = m - 1;
        int j = n - 1;
        int current = m + n - 1;
        while (current > 0 && i >= 0 && j>= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[current] = nums1[i];
                i--;
                current--;
            }else{
                nums1[current] = nums2[j];
                j--;
                current--;
            }
        }
//        while (i >= 0) {
//            nums1[current] = nums1[i];
//            current--;
//            i--;
//        }
        while (j >= 0) {
            nums1[current] = nums2[j];
            current--;
            j--;
        }
    }
    
    vector<int> plusOne(vector<int>& digits) {
        bool allValueIs9 = true;
        for (vector<int>::iterator it = digits.begin(); it != digits.end(); it++) {
            if (*it != 9) {
                allValueIs9 = false;
                break;
            }
        }
        if (allValueIs9) {
            size_t size = digits.size()+1;
            vector<int> ve = vector<int>(size,0);
            ve[0] = 1;
            return ve;
        }else{
            int plus = 1;
            for (int it = (int)digits.size() - 1; it >= 0; it--) {
                int k = digits[it];
                digits[it] = (k + plus) % 10;
                plus = (k + plus) / 10;
                if (plus == 0) {
                    break;
                }
            }
        }
        
        return digits;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution so;
    vector<string> strs = {"flower","flow","flight"};
    vector<int> num1 = {1,2,3,0,0,0};
    vector<int> num2 = {2,5,6};
//    so.merge(num1, 3, num2, 3);
//    so.longestCommonPrefix(strs);
    so.plusOne(num1);
    return 0;
}
