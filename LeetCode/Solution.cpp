//
//  Solution.cpp
//  LeetCode
//
//  Created by henry on 6/4/2019.
//  Copyright © 2019 henry. All rights reserved.
//

#include "Solution.hpp"
#include <string>
#include <map>
#include <stack>

int Solution::removeElement(vector<int>& nums, int val){
    
    int size = (int)nums.size();
    int i = 0;
    while (i < size) {
        if (nums[i] == val) {
            nums[i] = nums[size-1];
            size--;
        }else{
            i++;
        }
    }
    return size;
}

bool Solution::isPalindrome(int x) {
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

int Solution::romanToInt(string s) {
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

string Solution::longestCommonPrefix(vector<string>& strs) {
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

bool Solution::isValid(string s) {
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

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
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

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
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

vector<int> Solution::plusOne(vector<int>& digits) {
    
    for (int i= (int)digits.size()-1; i>=0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        }else{
            digits[i]++;
            return digits;
        }
    }
    digits[0] = 1;//走到这里说明所有位都为9
    digits.push_back(0);
    
    
    /**
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
     
     */
    
    return digits;
}

string Solution::addBinary(string a, string b) {
    /**
     string res = "";
     int c = 0,i = (int)a.length()-1, j = (int)b.length() -1;
     while (i >= 0 || j >= 0 || c == 1) {
     c += i >= 0 ? a[i--] - '0' : 0;
     c += j >= 0 ? b[j--] - '0' : 0;
     res = char(c % 2 + '0') + res;
     c /= 2;
     }
     return res;
     */
    
    
    if (a.length() < b.length()) {
        a = string(b.length()-a.length(),'0') + a;
    }else{
        b = string(a.length()-b.length(),'0') + b;
    }
    int i = (int)a.length() - 1;
    int plus = 0;
    string c = "";
    while (i >= 0) {
        int __i = a[i] - 48;
        int __j = b[i] - 48;
        c = to_string((__i + __j + plus) % 2) + c;
        plus = (__i + __j + plus) / 2;
        i--;
    }
    
    if (plus == 1) {
        c = "1" + c;
    }
    return c;
    
}

int Solution::strStr(string haystack, string needle) {
    if (needle.length() == 0) {
        return 0;
    }
    int index = -1;
    
    int i=0;
    while (i < haystack.length()) {
        if (haystack[i] == needle[0]) {
            if (haystack.length() - i >= needle.length()) {
                
                for (int j=0; j<needle.length(); j++) {
                    if (haystack[j+i] != needle[j]) {
                        ++i;
                        break;
                    }
                    if (j == needle.length() -1) {
                        return i;
                    }
                }
                
            }else{
                return -1;
            }
        }else{
           ++i;
        }
    }
    
    return index;
}

int Solution::lengthOfLongestSubstring(string s){
    if (s.length() <= 1) {
        return (int)s.length();
    }
    map<char,int> map;
    int i = 0;
    int j = 0;
    int size = 0;
    int n = (int)s.size();
    while (i < n && j < n) {
        if (map.find(s[j]) == map.end()) {
            map[s[j]] = j;
            j++;
            size = max(j-i, size);
        }else{
            // abcabcabc
            //删除慢指针前面的元素
            map.erase(s[i++]);
        }
    }
    
    return size;
}

int Solution::singleNumber(vector<int>& nums) {
    int value = 0;
    for (int i=0; i<nums.size(); i++) {
        value = value ^ nums[i];
    }
    return value;
}

vector<int> Solution::intersect(vector<int>& nums1, vector<int>& nums2) {
    
    
    vector<int> vt;
    size_t n1Size = nums1.size();
    size_t n2Size = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i=0;
    int j=0;
    while (i<n1Size && j<n2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        }else if(nums1[i] > nums2[j]){
            j++;
        }else{
            vt.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return vt;
    
    /**
    
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }
    if (nums1.size() == 0 || nums2.size() == 0) {
        return vector<int>();
    }
    
    map<int,int> map = std::map<int,int>();
    int size = (int)nums1.size();
    vector<int> vt = vector<int>(size);
    
    for (int i=0; i<nums1.size(); i++) {
        map[nums1[i]] = map[nums1[i]] + 1;
    }
    int index = 0;
    for (int j=0; j<nums2.size(); j++) {
        int va = nums2[j];
        if (map[va] > 0) {
            vt[index++] = va;
            map[va] = map[va] - 1;
            size--;
            if (size == 0) {
                return vt;
            }
        }
    }
    return vector<int>(vt.begin(), vt.begin()+index);
     */
}

void Solution::moveZeroes(vector<int>& nums) {
    int i=0;
    int size = 0;
    while (i<nums.size()) {
        if (nums[i] != 0) {
            i++;
        }else{
            int j = i+1;
            while (j<nums.size()) {
                if (nums[j] == 0) {
                    j++;
                }else{
                    swap(nums[i], nums[j]);
                    size++;
                    break;
                }
            }
            i++;
        }
        if (i == nums.size() - size) {
            break;
        }
    }
}
