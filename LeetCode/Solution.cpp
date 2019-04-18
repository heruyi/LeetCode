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
#include <cmath>

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

int Solution::myAtoi(string str){
    if (str.size() == 0) {
        return 0;
    }
    long value = 0;
    
    size_t index = 0;
    while( (index = str.find(' ',index)) != string::npos){
        str.erase(index,1);
    }
    
    map<char,int> map = {{'0',0},
        {'1',1},
        {'2',2},
        {'3',3},
        {'4',4},
        {'5',5},
        {'6',6},
        {'7',7},
        {'8',8},
        {'9',9},
    };
    
    index = 0;
    while (index < str.length()) {
        
        int it = map.find(str[index])->second;
        if (map.find(str[index]) != map.end()) {
            if (value == 0 && it == 0 && str[0] == '+') {
                return 0;
            }
            value = value * 10 + it;
            bool isSigned = str[0] == '-';
            if (isSigned && -value < INT_MIN) {//负数
                return INT_MIN;
            }else if (value > INT_MAX){
                return INT_MAX;
            }
        }else{
            if (index == 0) {
                if (str[0] != '-' && str[0] != '+') {
                    return 0;
                }
            }
            if (index != 0) {
                
                if (str[0] == '-') {
                    return -(int)value;
                }
            
                return (int)value;
            }
        }
        index++;
    }
    
    
    return str[0] == '-' ? -(int)value : (int)value;

}

vector<int> Solution::twoSum(vector<int>& nums, int target){

    vector<int> vt;
    map<int, int> _map;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] == target) {
            vt.push_back(i);
            return vt;
        }
        int com = target - nums[i];
        if (_map.find(com) != _map.end()) {
            vt.push_back(_map[com]);
            vt.push_back(i);
            return vt;
        }
        _map[nums[i]] = i;
    }
    return vt;
}

bool Solution::isValidSudoku(vector<vector<string>>& board) {

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==".")
                continue;
            for(int k=j+1;k<9;k++)
                if(board[i][j]==board[i][k])
                    return false;
            for(int k=i+1;k<9;k++)
                if(board[i][j]==board[k][j])
                    return false;
            for(int a=i+1;a<(i/3+1)*3;a++)
            {
                for(int b=j/3*3;b<j;b++)
                    if(board[i][j]==board[a][b])
                        return false;
                for(int b=j+1;b<j/3*3+3;b++)
                    if(board[i][j]==board[a][b])
                        return false;
            }
        }

    return true;
    
    /**
    vector<map<string,string>*> row = vector<map<string,string>*>();
    vector<map<string,string>*> column = vector<map<string,string>*>();
    vector<map<string,string>*> box = vector<map<string,string>*>();
    
    for (int i=0; i<9; i++) {
        map<string,string> *_map = new map<string,string>();
        row.push_back(_map);
        for (int j=0; j<9; j++) {
            string key = board[i][j];
            if (key == ".") {
                continue;
            }
            
            int k = (i / 3) * 3 + j / 3;
            
            if (column.size() < 9 && column.size() == j) {
                map<string,string> *_map = new map<string,string>();
                column.push_back(_map);
            }
            if (box.size() == k && box.size() < 9) {
                map<string,string> *_map = new map<string,string>();
                box.push_back(_map);
            }
            
            if (row[i]->find(key) != row[i]->end()) {
                return false;
            }else{
                (*row[i]).insert(pair<string, string>(key, key));
            }
            if (column[j]->find(key) != column[j]->end()) {
                return false;
            }else{
                column[j]->insert(pair<string, string>(key, key));
            }
            if (box[k]->find(key) != box[k]->end()) {
                return false;
            }else{
                box[k]->insert(pair<string, string>(key, key));
            }
            
        }
    }
    
    return true;
     */
}

void Solution::rotate(vector<vector<int>>& matrix){
//    {24,4,38,2,21,18,33,40},
//    {24,37,25,62,37,15,35,36},
//    {42,23,13,58,17,26,19,8},
//    {32,48,9,58,36,18,40,61},
//    {23,16,0,46,35,34,23,60},
//    {9,49,60,47,1,32,20,45},
//    {56,34,40,11,61,60,20,30},
//    {45,30,25,18,49,3,16,10}}
    for (int i=0; i<matrix.size() / 2; i++) {
        int max = (int)matrix.size() -i -1;
    
        for (int j=i; j<max; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[max-j+i][i];
            matrix[max-j+i][i] = matrix[max][max-j+i];
            matrix[max][max-j+i] = matrix[j][max];
            matrix[j][max] = temp;
        }
    }
}

void Solution::reverseString(vector<char>& s) {
    int i=0,j=(int)s.size()-1;
    while (i<j) {
        if (s[i] != s[j])
            swap(s[i], s[j]);
        
        i++;
        j--;
    }
}

bool Solution::isPalindrome(string s) {
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i=0,j=(int)s.size()-1;
    while (i<j) {
        bool isChar_i = isalnum(s[i]);
        if (!isChar_i) {
            i++;
        }
        bool isChar_j = isalnum(s[j]);
        if (!isChar_j) {
            j--;
        }
        if (isChar_i && isChar_j) {
            
            if ((s[i] | 0b100000) == (s[j] | 0b100000)) {
                i++;
                j--;
            }else{
                return false;
            }
            
        }
    }
    
    return true;
}

bool Solution::isAnagram(string s, string t) {
    
    if (s.length() != t.length()) {
        return false;
    }
    
    int hash1[256]{0};
    int hash2[256]{0};
    
    for (int i=0; i<s.length(); i++) {
        hash1[s[i]]++;
        hash2[t[i]]++;
    }
    
    for (int i=0; i<256; i++) {

        if (hash1[i] != hash2[i]) {
            return false;
        }
    }
    
    return true;
}

int Solution::reverse(int x) {
    //321
    long value = 0;
    long min = -pow(2, 31);
    long max = pow(2, 31) - 1;
    
    while (x != 0) {
        value = value * 10 + x % 10;
        x /= 10;
        if (value < min || value > max) {
            return 0;
        }
    }
    
    return (int)value;
    
}

int Solution::firstUniqChar(string s) {
    int idx = -1;
    int array['z'+1]{0};
    
    map<char,int> map {};
    int j=0;
    for (auto& v : s){
        array[v]++;
        map[v] = j++;
    }
    for (auto& v : s) {
        if (array[v] == 1) {
            return map[v];
        }
    }
    return idx;
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    
    ListNode _head = ListNode(0);
    _head.next = head;
    
    ListNode *_pp = head;
    for (int i=0; i<n; i++) {
        head = head->next;
    }
    
    while (head != NULL) {
        _pp = _pp->next;
        head = head->next;
    }
    
    
    _pp->next = _pp->next->next;
    
    return _head.next;
}

ListNode* Solution::reverseList(ListNode* head) {
    ListNode *list = new ListNode(0);
    while (head != NULL) {
        ListNode *next = new ListNode(head->val);
        next->next = list->next;
        list->next = next;
        head = head->next;
    }
    return list->next;
}

bool Solution::isPalindrome(ListNode* head) {
    //判断链表是否回文
    if (head == NULL) {
        return false;
    }
    
    if (head->next == NULL) {
        return true;
    }
    if (head->next->next == NULL) {
        return head->val == head->next->val;
    }
    
    ListNode *prev = NULL;
    ListNode *fast = head;
    ListNode *slow = head;
    bool odd = true;//奇数
    while (fast != NULL) {
        odd = fast->next == NULL;
        if (odd) {
            fast = NULL;
            break;
        }else{
            fast = fast->next->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
        
        if (fast == NULL) {
            break;
        }
        if (fast->next == NULL) {
            odd = true;
            break;
        }
    }
    
    ListNode *h1 = NULL;
    ListNode *h2 = NULL;
    
    if (odd) {
        h1 = slow->next;
        h2 = prev;
    }else{
        h1 = slow;
        h2 = prev;
    }
    while (h1 != NULL && h2 != NULL) {
        if (h1->val != h2->val) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    
    return true;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    int size = (int)lists.size();
    if (size == 0) {
        return nullptr;
    }
    while (size > 1) {
        int j=0;
        for (int k=0; k<size; k+=2) {
            ListNode *head = new ListNode(0);
            ListNode *current = head;
            ListNode *l1 = lists[k];
            ListNode *l2 = nullptr;
            if (k < size-1) {
                l2 = lists[k+1];
            }
            while (l1 != nullptr && l2 != nullptr) {
                if ((l1->val) < (l2->val)) {
                    current->next = l1;
                    current = l1;
                    l1 = l1->next;
                }else{
                    current->next = l2;
                    current = l2;
                    l2 = l2->next;
                }
            }
            if (l1 != nullptr) {
                current->next = l1;
            }
            if (l2 != nullptr) {
                current->next = l2;
            }
            lists[j] = head->next;
            j++;
        }
        size = j;
    }
    return lists[0];
}
