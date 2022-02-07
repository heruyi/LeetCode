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
#include <set>
#include <stack>
#include <cmath>
#include <search.h>
#include <iostream>
#include <numeric>

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

//无序数组
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
        if (s[i] != s[j]){
            s[i] = s[i] ^ s[j];
            s[j] = s[j] ^ s[i];
            s[i] = s[i]^s[j];
        }
//            swap(s[i], s[j]);
        
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
    /**
    ListNode *list = new ListNode(0);
    while (head != NULL) {
        ListNode *next = new ListNode(head->val);
        next->next = list->next;
        list->next = next;
        head = head->next;
    }
    return list->next;
     */
    ListNode *prew = nullptr;
    ListNode *current = prew;
    while (head != nullptr) {
        ListNode *temp = head->next;
        head->next = prew;
        prew = head;
        current = prew;
        head = temp;
    }
    return current;
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
            delete head;
            j++;
        }
        size = j;
    }
    return lists[0];
}

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        if ( (n & 1) == 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

//bool isBadVersion(long version);
//
//int firstBadVersion(int n) {
//    long start = 1;
//    long end = (long)n+1;
//
//    while (start < end) {
//        long mid = (start + end) / 2;
//        if (isBadVersion(mid)) {
//            if (!isBadVersion(mid-1)) {
//                return (int)mid;
//            }
//            end = mid;
//        }else{
//            start = mid;
//        }
//    }
//    return (int)start;
//}

//35. 搜索插入位置
int Solution::searchInsert(vector<int>& nums, int target) {
    
    int size = (int)nums.size();
    if (nums[size-1] < target) {
        return size;
    }
    
    int left = 0, right = size-1;
    while (left < right) {
        int mid = left +(right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    
    return left;
}

ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode *_head = head;
    while (head != NULL && head->next != NULL) {
        if (head->val == head->next->val) {
            head->next = head->next->next;
        }else{
            head = head->next;
        }
    }
    return _head;
}

bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    if (q->val != p->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}



void Solution::sortColors(vector<int>& nums) {
    
    long i=0,j=nums.size()-1,k=0;
    while (i<=j) {
        if (nums[i] == 0) {
            swap(nums[i], nums[k]);
            i++;
            k++;
            continue;
        }
        if (nums[i] == 2) {
            if (nums[j] == 2) {
                j--;
                continue;
            }
            swap(nums[i], nums[j]);
            j--;
            continue;
        }
        i++;
    }
    
}

vector<string> Solution::fizzBuzz(int n) {
    vector<string> *strings = new vector<string>(n);
    int i=1;
    while (i<=n) {
        if (i % 3 == 0 && i % 5 == 0) {
            (*strings)[i-1] = "FizzBuzz";
        }else if (i % 3 == 0) {
            (*strings)[i-1] = "Fizz";
        }else if (i % 5 == 0){
            (*strings)[i-1] = "Buzz";
        }else{
            (*strings)[i-1] = to_string(i);
        }
        
        i++;
    }
    return *strings;
}

int Solution::hammingDistance(int x, int y) {
    int c = 0, i = x ^ y;
    while (i) {
        if (i & 1) {
            c++;
        }
        i >>= 1;
    }
    return c;
}

int Solution::findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int ig=0,sg=0;
    int c = 0;
    while (ig < g.size() && sg < s.size()) {
        if (g[ig] <= s[sg]) {
            c++;
            ig++;
            sg++;
        }else{
            sg++;
        }
    }
    return c;
}

int Solution::islandPerimeter(vector<vector<int>>& grid) {
    
    int i=0,s=0;
    while (i < grid.size()) {
        int j=0;
        while (j < grid[i].size()) {
            
            if (grid[i][j] == 1) {
                s += 4;
                if (j > 0 && grid[i][j-1] == 1) {
                    s -= 2;
                }
                if (i > 0 && grid[i-1][j] == 1) {
                    s -= 2;
                }
            }
            
            j++;
        }
        i++;
    }
    return s;
}

int Solution::maxSubArray(vector<int>& nums) {
    int i=0,sum=0,_max = nums[0];
    while (i<nums.size()) {
        if (sum > 0) {
            sum += nums[i];
        }else{
            sum = nums[i];
        }
        _max = max(sum,_max);
        i++;
    }
    return _max;
}

//int mySqrt(int x) {
//    int i=0,j=x;
//    while (i<j) {
//        int mid = (j+i) / 2;
//        if (mid * mid < x && (mid+1)*(mid+1) > x) {
//            return mid;
//        }
//
//    }
//    return 0;
//}

uint32_t Solution::reverseBits(uint32_t n) {
    uint32_t i = 0;
    int j = 32;
    while (j--) {
        i <<= 1;
        i += (n & 1);
        n >>= 1;
    }
    return i;
}

vector<vector<int>> Solution::generate(int numRows) {
    vector<vector<int>> *soc = new vector<vector<int>>(numRows);
    for (int i=0; i<numRows; i++) {
        vector<int> *v = new vector<int>(i+1);
        for (int j=0; j<=i; j++) {
            if (i<2) {
                (*v)[j] = 1;
            }else{
                if (j==0 || j==i) {
                    (*v)[j] = 1;
                }else{
                    vector<int> *p = &(*soc)[i-1];
                    (*v)[j] = (*p)[j-1] + (*p)[j];
                }
            }
        }
        (*soc)[i] = *v;
    }
    
    return *soc;
}

int Solution::missingNumber(vector<int>& nums) {
    int i = 0,j=(int)nums.size(),res = 0;
    while (i<j) {
        res ^= i;
        res ^= nums[i];
        i++;
    }
    res ^= j;
    return res;
}

int Solution::lengthOfLastWord(string s) {
    
    int end = (int)s.length() - 1;
    
    while (end >= 0 && s[end] == ' ') {
        end--;
    }
    if (end < 0) {
        return 0;
    }
    int start = end;
    while (start >= 0 && s[start] != ' ') {
        start--;
    }
    return end - start;
    
}

int Solution::minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int len = 0;
    deque<TreeNode *> queue;
    TreeNode *lastNode = root;
    queue.push_back(root);
    while (!queue.empty()) {
        TreeNode *p = queue.front();
        queue.pop_front();
        if (p->left == nullptr && p->right == nullptr) {
            len++;
            break;
        }
        if (p->left != nullptr) {
            queue.push_back(p->left);
        }
        if (p->right != nullptr) {
            queue.push_back(p->right);
        }
        if (p == lastNode) {
            len++;
            lastNode = queue.back();
        }
    }
    return len;
}

int Solution::maxDepth(TreeNode* root) {
    
    if (root == nullptr) {
        return 0;
    }
//    return 1 + max(maxDepth(root->left), maxDepth(root->right));
    std::deque<TreeNode*> q;
    q.push_back(root);
    TreeNode *lastNode = root;
    int height = 0;
    while (!q.empty()) {
        TreeNode *p = q.front();
        q.pop_front();
        if (p->left != nullptr) {
            q.push_back(p->left);
        }
        if (p->right != nullptr) {
            q.push_back(p->right);
        }
        
        if (p == lastNode) {
            height++;
            lastNode = q.back();
        }
    }
    return height;
}

bool Solution::isBalanced(TreeNode* root) {
    if(root == nullptr)
        return true;
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    bool balanced = (abs(left - right) <= 1);
    return balanced && isBalanced(root->left) && isBalanced(root->right);
}

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
    vector<vector<int>> p;
    if (root == nullptr) {
        	return p;
    }
    
    vector<int> floot;
    deque<TreeNode *> queue;
    queue.push_back(root);
    TreeNode *lastNode = root;
    while (!queue.empty()) {
        TreeNode *u = queue.front();
        floot.push_back(u->val);
        queue.pop_front();
        if (u->left != nullptr) {
            queue.push_back(u->left);
        }
        if (u->right != nullptr) {
            queue.push_back(u->right);
        }
        if (u == lastNode) {
            p.push_back(floot);
            floot.clear();
            lastNode = queue.back();
        }
    }
    ::reverse(p.begin(), p.end());
    return p;
}

TreeNode* Solution::sortedArrayToBST(vector<int>& nums,int start,int end) {
    if (start == end) {
        return nullptr;
    }
    
    int mid = start + (end - start) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = sortedArrayToBST(nums, 0, mid);
    node->right = sortedArrayToBST(nums, mid+1, end);
    return node;
}

TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, (int)nums.size());
}

void Solution::preOrderWithoutRecursion(TreeNode *root){
    if (root == nullptr) {
        return;
    }
    TreeNode *currentNode = root;
    stack<TreeNode*> stack;
    
    while (currentNode != nullptr || !stack.empty()) {
        /** 前序遍历
        if (currentNode) {
            stack.push(currentNode);
            cout << currentNode->val << " ";
            currentNode = currentNode->left;
        }else{
            currentNode = stack.top()->right;
            stack.pop();
        }
         */
        /**
         * 中序遍历
         */
        if (currentNode) {
            stack.push(currentNode);
            currentNode = currentNode->left;
        }else{
            TreeNode *node = stack.top();
            cout << node->val << " ";
            currentNode = node->right;
            stack.pop();
        }
    }
    
}

bool Solution::hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr || root->val > sum){
        return false;
    }
    
    stack<TreeNode*>  node_stack;
    stack<int>  sum_stack;
    node_stack.push(root);
    sum_stack.push(sum - root->val);
    while (!node_stack.empty()) {
        TreeNode *currentNode = node_stack.top();
        int currentSum = sum_stack.top();
        node_stack.pop();
        sum_stack.pop();
        if (currentNode->left == nullptr && currentNode->right == nullptr && currentSum == 0) {
            return true;
        }
        if (currentNode->left != nullptr) {
            node_stack.push(currentNode->left);
            sum_stack.push(currentSum - currentNode->left->val);
        }
        if (currentNode->right != nullptr) {
            node_stack.push(currentNode->right);
            sum_stack.push(currentSum - currentNode->right->val);
        }
    }
    
    return false;
}

vector<int> Solution::getRow(int rowIndex) {
    
    deque<int>q;
    if (rowIndex == 0) {
        q.push_front(1);
        return vector<int>(q.begin(),q.end());
    }
    if (rowIndex == 1) {
        q.push_front(1);
        q.push_front(1);
        vector<int>(q.begin(),q.end());
    }
    
    int i = 2;
    q.push_front(1);
    q.push_front(1);
    while (i < rowIndex+1) {
        for (int k=0; k<q.size()-1; k++) {
            if(k==i)
                continue;
            else{
                q[k] = q[k] + q[k+1];
            }
        }
        q.push_front(1);
        i++;
    }
    return vector<int>(q.begin(),q.end());
}

int Solution::maxProfit(vector<int>& prices) {
    
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i=0; i<prices.size(); i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }else if (prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}

bool Solution::hasCycle(ListNode *head) {
    /** hash
    map<ListNode*,ListNode*> map;
    while (head != nullptr) {
        if (map.at(head) != nullptr) {
            return true;
        }
        map[head] = head;
        head = head->next;
    }
    return false;
     */
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

ListNode * Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }
    
    ListNode *a = headA;
    ListNode *b = headB;
    while (a != b) {
        a = a == nullptr ? headB : a->next;
        b = b == nullptr ? headA : b->next;
    }
    return a;
}

// 升序数组
vector<int> twoSum(vector<int>& numbers, int target) {
    /** 二分法
    for (int i=0; i<numbers.size(); i++) {
        int start = i+1;
        int end = (int)numbers.size() - 1;
        int num = target - numbers[i];
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (numbers[mid] == num) {
                return vector<int>{i+1,mid+1};
            }else if (numbers[mid] < num){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
     */
    
    /** 双指针法*/
    int start = 0;
    int end = (int)numbers.size() - 1;
    while (start < end) {
        if (numbers[start] + numbers[end] == target) {
            return vector<int>{start+1,end+1};
        }else if (numbers[start] + numbers[end] < target){
            start++;
        }else{
            end--;
        }
    }

    return vector<int>{-1,-1};
}

string Solution::convertToTitle(int n) {
    vector<char> ch = {'a',
        'A','B','C','D','E','F','G',
        'H','I','J','K','L','M','N',
        'O','P','Q','R','S','T',
        'U','V','W','X','Y','Z'
    };
    string str;
    while (n / 26) {
        int x = n / 26;
        int y = n % 26;
        if (y == 0) {
            x -= 1;
            str.insert(str.begin(), 'Z');
        }else{
            str.insert(str.begin(), ch[y]);
        }
        n = x;
    }
    if (n) {
        str.insert(str.begin(), ch[n]);
    }
    return str;
}

int Solution::majorityElement(vector<int>& nums) {
    /**
    if (nums.size() == 1) {
        return nums[0];
    }
    int val = (int)nums.size() / 2;
    map<int, int> map;
    int i = (int)nums.size()-1;
    while (i >= 0) {
        int x = nums[i];
        if (map.find(x) != map.end()) {
            map[x] = map[x] + 1;
            if (map[x] > val) {
                return x;
            }
        }else{
            map[x] = 1;
        }
        i--;
    }
    return -1;
     */
    
    /** 摩尔投票法 */
    int condetion = 0;
    int count = 0;
    for (int i=0; i<nums.size(); i++) {
        if (count == 0) {
            condetion = nums[i];
        }
        count += (condetion == nums[i]) ? 1 : -1;
    }
    return condetion;
}

int Solution::titleToNumber(string s) {
    s = "ZZ";
    int i=0;
    int res = s[i] - 'A' + 1;
    while (s[++i] != '\0') {
        res *= 26;
        res += s[i] - 'A' + 1;
    }
    return res;
}

    //198 打家劫舍 f(x) = max(f(x-2)+x,f(x-1));
int rob(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 0) {
        return 0;
    }
    vector<int> dp = vector<int>(nums.size()+1,0);
    dp[1]=nums[0];
    for (int i=2; i<=nums.size(); i++) {
        dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
    }
    return dp[nums.size()];
}

bool isHappy(int n) {
    map<int, int> _dic = map<int,int>();
    
start:
    int x = 0;
    while (n / 10 || n > 0) {
        x += pow(n%10, 2);
        n = n / 10;
    }
    if (_dic.find(x) != _dic.end()) {
        return false;
    }else if(x == 1){
        return true;
    }else{
        _dic[x] = x;
    }
    
    n = x;
    goto start;
    
    return false;
}

ListNode* Solution::removeElements(ListNode* head, int val) {
    ListNode *warp = new ListNode(0);
    warp->next = head;
    ListNode *current = warp;

    while (current) {
        if(current->next && current->next->val == val){
            current->next = current->next->next;
        }else{
            current = current->next;
        }
    }
    return warp->next;
}

int Solution::countPrimes(int n) {
    if(n < 2)
        return 0;
    int count = 0;
    vector<bool> signs(n,true);
    for (int i=2; i<n; i++) {
        if (signs[i]) {
            count++;
            for (int j=i+i; j<n; j+=i) {
                signs[j] = false;
            }
        }
    }
    return count;
}

bool Solution::isIsomorphic(string s, string t) {
    
    //ab ca
    /**
    if (s.length() != t.length()) {
        return false;
    }
    map<char, char> _map;
    map<char, char> reverseMap;
    int i=0;
    while (i < s.length()) {
        
        char ss = s[i];
        char tt = t[i];
        
        if (_map.find(ss) != _map.end() ) {
            if (_map[ss] != t[i]) {
                return false;
            }
        }else{
            if (reverseMap.find(tt) != reverseMap.end()) {
                return false;
            }
            _map[ss] = tt;
            reverseMap[tt] = ss;
        }
        i++;
    }
     */
    size_t length = s.size();
    vector<int> smap(256, -1);
    vector<int> tmap(256, -1);
    for(size_t i = 0; i < length; ++i)
        {
        if(smap[s[i]] == -1 && tmap[t[i]] == -1){
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        }
        else if(smap[s[i]] != t[i] || tmap[t[i]] != s[i])
            return false;
    }
    return true;
}

bool Solution::containsNearbyDuplicate(vector<int>& nums, int k) {
    if (nums.size() == 0) {
        return false;
    }
    
    map<int, size_t> _map;
    
    size_t len = nums.size();
    for (size_t i=0; i<len; i++) {
        /**
        if (_map.find(nums[i]) != _map.end()) {
            if (i - _map[nums[i]] <= k) {
                return true;
            }else{
                _map[nums[i]] = i;
            }
        }else{
            _map[nums[i]] = i;
        }
         */
        if (_map.find(nums[i]) != _map.end()) {
            return true;
        }
        _map[nums[i]] = i;
        if (_map.size() > k) {
            _map.erase(nums[i-k]);
        }
    }
    return false;
}

TreeNode* Solution::invertTree(TreeNode* root) {
    
    deque<TreeNode*> queue;
    queue.push_front(root);

    while (!queue.empty()) {
        TreeNode *node = queue.front();
        queue.pop_front();
        
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
        if (node->left) {
            queue.push_front(node->left);
        }
        if (node->right) {
            queue.push_front(node->right);
        }
    }
    
    return root;
}

bool isPowerOfTwo(int n) {
    if (n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    
    while (n) {
        int m = n % 2;
        if (m != 0) {
            return false;
        }
        n /= 2;
        if (n == 1) {
            return true;
        }
    }
    
    return true;
}
///235 二叉搜索树的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    /**
    if ((root->val < q->val && root->val < p->val)) {
        return lowestCommonAncestor(root->right, p, q);
    }else if ((root->val > q->val && root->val > p->val)){
        return lowestCommonAncestor(root->left, p, q);
    }else{
        return root;
    }
     */
    
    while (root) {
        if ((root->val < q->val && root->val < p->val)) {
            root = root->right;
        }else if ((root->val > q->val && root->val > p->val)){
            root = root->left;
        }else{
            return root;
        }
    }
    return nullptr;
}
/**
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> vet;
    deque<TreeNode*> q;
    deque<string> s;
    
    q.push_back(root);
    s.push_back(to_string(root->val));
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop_front();
        
        string str = s.front();
        s.pop_front();
        
        if (node->left) {
            s.push_back(string(str + "->" + to_string(node->left->val)));
            q.push_back(node->left);
        }
        if (node->right) {
            s.push_back(string(str + "->" + to_string(node->right->val)));
            q.push_back(node->right);
        }
        if (node->left == nullptr && node->right == nullptr) {
            vet.push_back(str);
        }
    }
    
    return vet;
}
*/
vector<string> Solution::binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if (!root) return res;
    
    string s;
    s += to_string(root->val);
    
    if(!root->left&&!root->right) {
        res.push_back(s);
    }
    
    
    if (root->left) {
        vector<string> left = binaryTreePaths(root->left);
        for (int i = 0; i < left.size(); ++i) {
            res.push_back(s + "->" + left[i]);
        }
    }
    
    if (root->right) {
        vector<string> right = binaryTreePaths(root->right);
        for (int j = 0; j < right.size(); ++j) {
            res.push_back(s + "->" + right[j]);
        }
    }
    
    return res;
}

int Solution::addDigits(int num){
    int x = num;
    while (num > 9) {
        x = 0;
        while (num) {
            x += num % 10;
            num = num / 10;
        }
        num = x;
    }
    return x;
    
}

bool Solution::wordPattern(string pattern, string str) {

    vector<string> vet;
    while (str.length() > 0) {
        string s = str.substr(0,str.find_first_of(' '));
        vet.push_back(s);
        str = str.erase(0, s.length()+1);
    }
    if (pattern.length() != vet.size()) {
        return false;
    }
    
    map<char,string> map1;
    map<string,char> map2;
    
    int i=0;
    while (i < pattern.length()) {
        char c = pattern[i];
        if (map1.find(c) != map1.end()) {
            if (vet[i] != map1[c]) {
                return false;
            }
        }else{
            if (map2.find(vet[i]) != map2.end()) {
                return false;
            }
            map1[c] = vet[i];
            map2[vet[i]] = c;
        }
        i++;
    }

    return true;
}


string Solution::reverseVowels(string s){
    if (s.length() == 0) {
        return s;
    }
    
    map<char,char> map{
        {'a','a'},
        {'e','e'},
        {'i','i'},
        {'o','o'},
        {'u','u'},
        {'A','a'},
        {'E','e'},
        {'I','i'},
        {'O','o'},
        {'U','u'},
    };
//    set<char> map{
//        'a','A','e','E','i','I','o','O','u','U'
//    };
    int i = 0, j = (int)s.length() - 1;
    while (i < j) {
        while (i < j) {
            if (map.find(s[i]) != map.end()) {
                break;
            }else{
                i++;
            }
        }
        while (i < j) {
            if (map.find(s[j]) != map.end()) {
                break;
            }else{
                j--;
            }
        }
        if (i < j && s[i] != s[j]) {
            s[i] = s[i] ^ s[j];
            s[j] = s[j] ^ s[i];
            s[i] = s[i] ^ s[j];
        }
        i++;
        j--;
    }
    return s;
}


vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
    /**
    set<int> vet;
    size_t i = 0;
    while (i < nums1.size()) {
        size_t j = 0;
        int val = nums1[i];
        if (vet.find(val) == vet.end()) {
            while (j < nums2.size()) {
                if (val == nums2[j]) {
                    vet.insert(val);
                    break;
                }
                j++;
            }
        }
         i++;
    }
    
    
     */
    map<int,int> map;
    for (int i=0; i<nums1.size(); i++) {
        map[nums1[i]] = nums1[i];
    }
    set<int> vet;
    for (int i=0; i<nums2.size(); i++) {
        if (map.find(nums2[i]) != map.end() ) {
            vet.insert(nums2[i]);
        }
    }
    return vector<int>(vet.begin(),vet.end());
}


bool isPerfectSquare(int num) {
    long long ans = 0;
    for(int i = 1 ; ans < num ; i += 2)
        ans += i;
    return ans == num;
}

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    
    vector<int> vet = vector<int>(256,0);
    int i = (int)s.size();
    while (--i >= 0) {
        vet[s[i]] += 1;
    }
    
    i = (int)t.size();
    while (--i >= 0) {
        vet[t[i]] -= 1;
    }
    i = (int)vet.size();
    while (--i >= 0) {
        if (vet[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int getSum(int a, int b) {
    //不用+运算符实现加法
    while (b) {
        auto c = (unsigned int) (a & b) << 1;
        a = a ^ b;
        b = c;
    }
    return a;
}

bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) {
        return false;
    }
    int a[256]{0};
    int i = 0;
    /**
    while (i < ransomNote.size()) {
        a[magazine[i]]++;
        a[ransomNote[i]]--;
        i++;
    }
    
    while (i < magazine.size()) {
        a[magazine[i]]++;
        i++;
    }
     */
    while (i < magazine.size()) {
        a[magazine[i]]++;
        i++;
    }
    i = 0;
    while (i < ransomNote.size()) {
        if (a[ransomNote[i]]) {
            a[ransomNote[i]]--;
        }else{
            return false;
        }
        i++;
    }
    /*
    i = 256;
    while (--i >= 0) {
        if (a[i] < 0) {
            return false;
        }
    }
     */
    return true;
}


int firstUniqChar(string s) {
    int a[26]{0};
    for (int i=0; i<s.size(); i++) {
        a[s[i] - 'a']++;
    }
    for (int i=0; i<s.size(); i++) {
        if(a[s[i] - 'a']  == 1)
            return i;
    }
    return -1;
}

char findTheDifference(string s, string t) {
    char a = 0;
    for (int i=0; i<s.size(); i++) {
        a ^= s[i];
        a ^= t[i];
    }
    a ^= t[s.size()];
    return a;
}

int Solution:: findNthDigit(int n) {
    
//    1*9 * + 2 * 90 + 3 * 990 + 4 * 9990
//    101112
    
    if (n < 10) {
        return n;
    }
    
    int i = 0;
    long x = 0;
    while (x < n) {
        x += ((i+1) * 9 * pow(10, i));
        i++;
    }
    
    i--;//数字位数
    int k = n - (x - ((i+1) * 9 * pow(10, (i))));
    int j = k / (i+1);
    int m = k % (i+1);
    if (m != 0) {
        j++;
    }
    
    int p = pow(10, i) + j -1;
    
    int index = (k-1) % (i+1);
    
    string a = to_string(p);
    char c = a[index];
    int q = c - '0';
    return q;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
        return 0;
    }
    
    int left =  0;
    if (root->left && root->left->left == 0 && root->left->right == 0) {
        left = root->left->val;
    }
    return left + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

string Solution::toHex(int num) {
    
    if (num == 0) {
        return "0";
    }
    if (num == -2147483648)
        return "80000000";
    string str = "";
    vector<string> vet{"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
    
    if (num > 0) {
        while (num) {
            str.insert(0, vet[num % 16]);
            num /= 16;
        }
        return str;
    }
    
    vector<string> mapb{"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
    int i = 0;
    num = abs(num);
    while (num) {
        str.insert(0, mapb[num % 16]);
        num /= 16;
        i++;
    }
    while (i<8) {
        str.insert(0, "0000");
        i++;
    }
    
    string rev = "";
    for (int i=0; i<str.length(); i++) {
        rev.append(str[i] == '0' ? "1":"0");
    }
    
    int k = (int)rev.length();
    int v = 1;
    while (--k >= 0 && v) {
        int s = (rev[k] - '0' + v) % 2;
        v = (rev[k] - '0' + v) / 2;
        rev[k] = char('0' + s);
    }
    
    map<string,string> mapf{{"0000","0"},{"0001","1"},{"0010","2"},{"0011","3"},{"0100","4"},{"0101","5"},{"0110","6"},{"0111","7"},{"1000","8"},{"1001","9"},{"1010","a"},{"1011","b"},{"1100","c"},{"1101","d"},{"1110","e"},{"1111","f"}};
    i = 0;
    string ss = "";
    while (i<8) {
        ss.append(mapf[rev.substr(i*4,4)]);
        i++;
    }

    return ss;
}

int longestPalindrome(string s) {
    int a[256]{0};
    int x = 0;
    for (int i=0; i<s.length(); i++) {
        a[s[i]]++;
        if (a[s[i]] == 2) {
            x += 2;
            a[s[i]] = 0;
        }
    }
    if (x < s.length()) {
        x++;
    }
    return x;
}

int Solution::thirdMax(vector<int>& nums) {
    size_t size = nums.size();
    
    vector<int> vet;
    for (int i=0; i<size; i++) {
        int x = nums[i];
        
        if (vet.size() == 0) {
            vet.push_back(x);
        }else if(vet.size() == 1){
            if (x < vet[0]) {
                vet.push_back(x);
            }else if (x > vet[0]){
                vet.push_back(x);
                vet[1] = vet[0];
                vet[0] = x;
            }
        }
        else if(vet.size() == 2){
            if (x < vet[1]) {
                vet.push_back(x);
            }else if(x < vet[0] && x > vet[1]){
                vet.push_back(x);
                vet[2] = vet[1];
                vet[1] = x;
            }else if(x > vet[0]){
                vet.push_back(x);
                vet[2] = vet[1];
                vet[1] = vet[0];
                vet[0] = x;
            }
        }
        else if(vet.size() == 3){
            if (x > vet[2] && x < vet[1]) {
                vet[2] = x;
            }else if (x > vet[1] && x < vet[0]){
                vet[2] = vet[1];
                vet[1] = x;
            }else if(x > vet[0]){
                vet[2] = vet[1];
                vet[1] = vet[0];
                vet[0] = x;
            }
        }
    }
    if (vet.size() >= 3) {
       return vet.back();
    }
    return vet.front();
}

string Solution::addStrings(string num1, string num2) {
    string str = "";
    int i = (int)num1.size() -1;
    int j = (int)num2.size() -1;
    int v = 0;
    
    while (i >= 0 || j >= 0) {
        
        int s = 0;
        if (j >= 0)
            s = (num2[j] - '0');
        
        int t = 0;
        if (i >= 0)
            t = (num1[i] - '0');
        
        int k = s + t + v;
        int r = k % 10;
        v = k / 10;
        
        str.insert(str.begin(), char(r+'0'));
        i--;
        j--;
    }
    if (v) {
        str.insert(str.begin(), char(v+'0'));
    }
    
    return str;
}

vector<vector<int>> Solution::levelOrder(Node* root) {
    vector<vector<int>> vv;
    if (root == nullptr) {
        return vv;
    }
    
    
    deque<Node*> q;
    q.push_back(root);
    Node *last = root;
    
    vector<int> v;
    while (!q.empty()) {
        Node *node = q.front();
        q.pop_front();
        
        v.push_back(node->val);
        
        q.insert(q.end(), node->children.begin(),node->children.end());
        
        if (node == last) {
            last = q.back();
            vv.push_back(vector<int>(v));
            v.clear();
        }
    }
    return vv;
}

int Solution::countSegments(string s) {
    int count = 0;
    long i = 0;
    bool sig = false;
    while (i < s.length()) {
        if (sig && s[i] == ' ') {
            count++;
        }
        sig = s[i] != ' ';
        i++;
    }
    if (sig) {
        count++;
    }
    return count;
}


bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return false;
    }
    
    int val = sum - root->val;
    
    if (!root->left && !root->right) {
        return val == 0;
    }
    
    return hasPathSum(root->left, val) || hasPathSum(root->right, val );
}

/**
 
层序遍历 解法
 113 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    
    if (!root) {
        return vector<vector<int>>();
    }
    
    deque<TreeNode *> dq;
    dq.push_back(root);
    
    deque<int> sm;
    sm.push_back(root->val);
    
    vector<int> v;
    v.push_back(root->val);
    
    deque<vector<int>> dv;
    dv.push_back(v);
    
    vector<vector<int>> result;
    
    while (!dq.empty()) {
        
        TreeNode *node = dq.front();
        dq.pop_front();
        
        vector<int> vet = dv.front();
        dv.pop_front();
        
        int _sum = sm.front();
        sm.pop_front();
        
        if (!node->left && !node->right && sum == _sum) {
            result.push_back(vector<int>(vet));
        }
        
        if (node->left) {
            vector<int> ln = vector<int>(vet);
            ln.push_back(node->left->val);
            
            dv.push_back(ln);
            sm.push_back(_sum+node->left->val);
            
            dq.push_back(node->left);
        }
        
        if (node->right) {
            vector<int> rn = vector<int>(vet);
            rn.push_back(node->right->val);
            
            dv.push_back(rn);
            sm.push_back(_sum+node->right->val);
            
            dq.push_back(node->right);
        }
    }
    
    return result;
}
*/


vector<int> Solution::findAnagrams(string s, string p) {
    vector<int> vet;
    int left = 0, right = 0;
    int match = 0;
    map<char,int>needs;
    map<char,int>windows;
    for (int i=0; i<p.size(); i++) {
        needs[p[i]]++;
    }
    
    while (right < s.length()) {
        if (needs.count(s[right])) {
            windows[s[right]]++;
            if (windows[s[right]] == needs[s[right]]) {
                match++;
            }
        }
        right++;
        
        while (match == needs.size()) {
            
            if (right - left == p.size()) {
                vet.push_back(left);
            }
            
            if (windows.count(s[left])) {
                windows[s[left]]--;
                if (windows[s[left]] < needs[s[left]]) {
                    match--;
                }
            }
            left++;
        }
    }
    
    return vet;
}


int Solution::arrangeCoins(int n) {
    /**
    if (n == 0) {
        return 0;
    }
    int i=1;
    long res = 0;
    for (; i<n; i++) {
        res +=i;
        if (res > n) {
            return --i;
        }
    }
    return --i;
     */
    
//    1+2+3+4+5+....n = (n * (n+1)) / 2;
    
    int left = 0,right = n;
    while (left < right) {
        int mid = left + (right + 1 - left) / 2;
        if (((mid * (mid+1)) >> 1) > n) {
            right = mid - 1;
        }else{
            left = mid;
        }
    }
    return right;
}

int Solution::compress(vector<char>& chars) {
    int left =0, right=0, current =0;
    while (right < chars.size()) {
        while (chars[left] == chars[right] && right < chars.size()) {
            right++;
        }
        
        chars[current] = chars[left];
        if (right - left > 1) {
            chars[current+1] = right - left + '0';
            current += 2;
        }else{
            current += 1;
        }
        left = right;
    }
    
    return current;

}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    stack<ListNode*> stk1;
    stack<ListNode*> stk2;
    while (l1) {
        stk1.push(l1);
        l1=l1->next;
    }
    while (l2) {
        stk2.push(l2);
        l2=l2->next;
    }
    
    ListNode *ll1 = nullptr;
    ListNode *ll2 = nullptr;
    int val = 0;
    bool gl = stk1.size() >= stk2.size();
    while (!stk1.empty() && !stk2.empty()) {
        
        ll1=stk1.top();
        ll2=stk2.top();
        stk1.pop();
        stk2.pop();
        
        int m = (ll1->val + ll2->val + val) % 10;
        val = (ll1->val + ll2->val + val) / 10;
        if (gl) {
            ll1->val = m;
        }else{
            ll2->val = m;
        }
    }
    
    while (!stk1.empty()) {
        ll1 = stk1.top();
        stk1.pop();
        int m = (ll1->val + val) % 10;
        val = (ll1->val+ val) / 10;
        ll1->val = m;
    }
    
    while (!stk2.empty()) {
        ll2 = stk2.top();
        stk2.pop();
        int m = ( ll2->val + val) % 10;
        val = ( ll2->val + val) / 10;
        ll2->val = m;
    }
    
    if (val) {
        ListNode* root = new ListNode(1);
        if (gl) {
            root->next = ll1;
        }else{
            root ->next = ll2;
        }
        return root;
    }
    
    return gl ? ll1 : ll2;
}


int Solution::numberOfBoomerangs(vector<vector<int>>& points) {
    // 解法错误
    map<_Point, _Point,cmplKey> map;
    
    for (int i=0; i<points.size(); i++) {
        vector<int> t = points[i];
        _Point p = _Point(t[0],t[1]);
        map[p] = p;
    }
    
    int count = 0;
    for (int i=0; i<points.size(); i++) {
        vector<int> v1 = points[i];
        for (int j = i+1; j<points.size(); j++) {
            vector<int> v2 = points[j];
            vector<int> cnt = vector<int>{(v1[0] + v2[0])/2,(v1[1] + v2[1])/2};
            _Point s = _Point(cnt[0], cnt[1]);
            if ((cnt[0] != v1[0] || cnt[1] != v1[1]) && (cnt[0] != v2[0] || cnt[1] != v2[1]) && map.find(s) != map.end()) {
                count += 2;
            }
        }
    }
    return count;
}

vector<int> Solution::findDisappearedNumbers(vector<int>& nums) {
    //将
    
    vector<int > vet;
    for (int i=0; i<nums.size(); i++) {
        int index = (nums[i]-1) % nums.size();
        nums[index] += (int)nums.size();
    }
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] <= nums.size()) {
            vet.push_back(i+1);
        };
    }
    return vet;
}

bool Solution::repeatedSubstringPattern(string s) {
    int len = (int)s.size(),i = 0, t = 0;
    for (t=1; t<len/2; t++) {
        if (len % t) {//有余数 不为周期串
            continue;
        }
        for (i=t; i<len && s[i%t] == s[i]; i++);
        if (i == len) {
            return true;
        }
    }
    
    return false;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int i=0; i<houses.size(); i++) {
        int cur = INT_MAX;
        // lower_bound 返回第一个大于等于这个元素的迭代器
        // 此时larger就是这座房子右边的供暖器
        //使用*larger 来取值或者heaters[larger-heaters.begin()]
        auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
        if (larger != heaters.end()) {
            //如果存在 那么久计算他们之间的距离
            cur = *larger - houses[i];
        }
        //如果这个房子没有小于最开始的取暖器 那么意味着它左边也有一个供暖器
        if (larger != heaters.begin()) {
            auto smaller = larger - 1;//相当于取迭代器前面一个元素;
            cur = min(cur,houses[i] - *smaller);
        }
        ans = max(cur,ans);
    }
    return ans;
}

int Solution::findComplement(int num) {
    
    // 0101
    int ans = 0;
    int i = 0;
    while (num) {
        int x = (num & 1) ? 0 : 1;
        ans = (x << i) | ans;
        num >>= 1;
    }
    return ans;
}

string Solution::licenseKeyFormatting(string S, int K) {
    
//    string ans = "";
//    int n = 0, j = 0;
//    while(S[j] == '-') j++;
//    for(int i = S.size() - 1; i >= j; i--){
//        if(S[i] == '-') continue;
//        ans += toupper(S[i]);
//        if( !(++n % K) && i != j) ans += '-';
//    }
//    ::reverse(ans.begin(), ans.end());
//    return ans;
    

//    for (auto it=S.begin(); it != S.end(); it++) {
//        if (*it == '-') {
//            S.erase(it);
//            it--;
//        }
//    }
    
    int begin = (int)S.size() - 1, count = 0;
    
    string res = "";
    
    for (int i = begin; i >= 0; i--) {
        
        
        char c = S[i];
        if (c == '-') continue;
        if (c >= 'a' && c <= 'z') {
            c += 'A' - 'a';
        }
        
        res += c;
        count++;
        if (count % K == 0) {
            res += '-';
        }
    }
    ::reverse(res.begin(), res.end());
    if (*res.begin() == '-') {
        res.erase(res.begin());
    }
    
    return res;
}

int Solution::findMaxConsecutiveOnes(vector<int>& nums) {
    int num = 0;
    int count = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
        }else{
            num = max(num,count);
            count = 0;
        }
    }
    num = max(num,count);
    return num;
}

vector<int> Solution::constructRectangle(int area) {
    
    vector<int> vet;
    return vet;
}


vector<int> Solution:: nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    /** 暴利破解
    vector<int> vet;
    map<int, int> map;
    for (int i=0; i<nums1.size(); i++) {
        int val = nums1[i];
        
        bool eq = false;
        bool find = false;
        int index = map[val];
        for (int idx = index; idx < nums2.size(); idx++) {
            map[nums2[idx]] = idx;
            if (nums2[idx] == val) {
                eq = true;
                continue;
            }
            if (eq && nums2[idx] > val) {
                vet.push_back(nums2[idx]);
                find = true;
                break;
            }
        }
        if (!find) {
            vet.push_back(-1);
        }
    }
    return vet;
     */
    
     // 4 1 2     1 3 4 2
    vector<int> output;//保存答案
    map<int,int> mp;//元素为数组2的元素，值为数组2内比该元素更大的元素（如不不存在则为-1）
    stack<int> s;//单调栈
    
    for (int i= (int)nums2.size()-1; i>=0; i--) {
        int val = nums2[i];
        while (!s.empty() && s.top() < val) {
            s.pop();
        }

        mp[val] = s.empty() ? -1 : s.top();
        s.push(val);
    }
    
    for (int i=0; i<nums1.size(); i++) {
        int val = nums1[i];
        output.push_back(mp[val]);
    }
    
    return output;
    
}

vector<string> Solution::findWords(vector<string>& words) {
    vector<string> vet;
    if (words.size() == 0) {
        return vet;
    }
    
    int arr[] = {1,2,2,1,0,1,1, 1,0,1,1,1,2,2, 0,0,0, 0,1,0, 0,2,0, 2,0,2};
    for (int i=0; i<words.size(); i++) {
        string s = words[i];
        if (s.size() == 1) {
            vet.push_back(s);
            continue;
        }
        int j=1;
        for (;j<s.size(); j++){
            int c1 = std::tolower(s[j]);
            int c2 = std::tolower(s[j-1]);
            if (arr[c1  - 'a'] != arr[c2 - 'a']) {
                break;
            }
        }
        
        if (j==s.length()) {
            vet.push_back(s);
        }
    }
    return vet;
}

struct _Comp{
public:
    bool operator()(const int &k1, const int &k2) const {
        return (k1 > k2);
    }
};

vector<string> Solution::findRelativeRanks(vector<int>& nums) {
    map<int,int,_Comp>  map; // <value,index>
    for (int i=0; i<nums.size(); i++) {
        map[nums[i]] = i;
    }
    
    sort(nums.begin(), nums.end(), _Comp());
    
    vector<string> vet(nums.size(),"");
    
    for (int i=0; i<nums.size(); i++) {
        
        int index = map[nums[i]];
        if(i < 3){
            if (i == 0) {
                vet[index] = "Gold Medal";
            }else if (i == 1){
                vet[index] = "Silver Medal";
            }else if (i == 2){
                vet[index] = "Bronze Medal";
            }
        }
        else{
            vet[index] = to_string(i+1);
        }
    }
    
    return vet;
}

bool Solution::detectCapitalUse(string word) {
    
    if (word.size() < 2) {
        return true;
    }
    
    bool hasL = false; //含有小写字母
    int lastH = -1; //上次的大写字母位置
    for (int i=0; i<word.size(); i++) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') {
            if (lastH > 0) {
                return false;
            }
            hasL = true;
        }
        if (c >= 'A' && c <= 'Z') {
            
            if (hasL) {
                return false;
            }
            lastH = i;
        }
    }
    
    return true;
}

int Solution::findPairs(vector<int>& nums, int k) {
    int count = 0;
    if (nums.size() == 0) {
        return count;
    }
    sort(nums.begin(), nums.end());
    for (int index=0; index<nums.size()-1; index++) {
        int i = nums[index];
        int j = i+k;
        if (index > 0 && nums[index-1] == i) {
            continue;
        }
        int start = index+1;
        int end = (int)nums.size()-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == j) {
                count++;
                break;
            }else if (nums[mid] > j){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
    }
    
    return count;
}

int findPosion(vector<int> &v,int low,int high){
	
	int tmp = v[low];
	while (low < high) {
		while (low < high && v[high] >= tmp) {
			high--;
		}
		v[low] = v[high];
		while (low < high && v[low] < tmp) {
			low++;
		}
		v[high] = v[low];
	}
	v[low] = tmp;
		
	return low;
}

void Solution::quickSort(vector<int> &v,int low,int high) {
	if (low < high) {
		int index = findPosion(v, low, high);
		quickSort(v,low,index-1);
		quickSort(v,index+1,high);
	}
}

int Solution::findSubstringInWraproundString(string p) {
	if (p.size() == 0) {
		return 0;
	}
	vector<int> dp(26, 0);
	int cnt = 0;
	for (int i = 0; i < p.size(); i++) {
		if (i > 0 && ((p[i] - p[i-1] == 1) || (p[i-1] - p[i] == 'z' - 'a'))) {
			cnt += 1;
		}else{
			cnt = 1;
		}
		dp[p[i] - 'a'] = max(dp[p[i] - 'a'], cnt);
	}
	return std::accumulate(dp.begin(), dp.end(), 0);
}
