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
#include "Solution.hpp"
#include "PathSum.hpp"
#include<algorithm>

using namespace std;

/**
void ProOrderTraverse(TreeNode *tree)
{
    if (tree == NULL)
        return;
    cout << tree->val << " ";
    ProOrderTraverse(tree->left);
    ProOrderTraverse(tree->right);
}

void preOrderTraverse2(TreeNode *root){
    
    stack<TreeNode *> stack;
    TreeNode *pNode = root;
    while (pNode != NULL || !stack.empty()) {
        if (pNode != NULL) {
            cout << pNode->val << " ";
            stack.push(pNode);
            pNode = pNode->left;
        }else{
            TreeNode *node = stack.top();
            pNode = node->right;
            stack.pop();
        }
    }
}



void helper(TreeNode *root,int sum,vector<vector<int>> &rst, vector<int>curr){
    sum -= root->val;
    curr.push_back(root->val);
    if (!root->left && !root->right && sum == 0) {
        rst.push_back(vector<int>(curr));
        return;
    }
    
    if (root->left) {
        helper(root->left, sum, rst, curr);
        curr.pop_back();
    }
    if (root->right) {
        helper(root->right, sum, rst, curr);
        curr.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    
    vector<int> curr;
    
    helper(root, sum, result, curr);
    return result;
}

*/

/*
int main(){
	int n;
	
	while(cin >> n) {
		
		if(n < 3) {
			cout << -1 << endl;
		}else {
			vector<vector<int>> vet(n, vector<int>(n * 2, 0));
			for(int i = 1; i <= n; i++){
				vector<int> &arr = vet[i - 1];
				if(i < 3){
					for(int k = 0; k < (i * 2) - 1; k++){
						arr[k] = 1;
					}
				} else {
					for(int k = 0; k < (i * 2) - 1; k++){
						if(k == 0 || k == (i * 2) - 2) {
							arr[k] = 1;
						} else if(k == 1) {
							arr[k] = vet[(i - 2)][k] + vet[(i - 2)][k-1];
						} else if(k == (i * 2) - 3) {
							arr[k] = vet[(i - 2)][k -1] + vet[(i - 2)][k - 2];
						} else {
							arr[k] = vet[(i - 2)][k] + vet[(i - 2)][k -1] + vet[(i - 2)][k - 2];
						}
					}
				}
			}
			
			auto it = vet[n - 1];
			int val = -1;
			int idx = 0;
			while(idx < 2 * n - 1) {
				if(it[idx] % 2 == 0) {
					val = idx + 1;
					break;
				}
				idx++;
			}
			cout << val << endl;
		}
	}
	return 0;
}
*/


/*
int main() {
	string str;

	while(getline(cin, str))
	{
		int idx = 0;
		int cpyIdx = 0;
		char copy[10001] = {0};
		while(idx < str.size()){
			if((str[idx] >= 'a' && str[idx] <= 'z') || (str[idx] >= 'A' && str[idx] <= 'Z')) {
				copy[cpyIdx++] = str[idx];
			} else {
				if(cpyIdx != 0 && copy[cpyIdx - 1] != ' ') {
					copy[cpyIdx++] = ' ';
				}
			}
			idx++;
		}
		if(cpyIdx != 0 && copy[cpyIdx - 1] == ' ') {
			copy[idx] = '\0';
		}
		str = copy;
		auto n = str.rfind(' ');
		while(n != string::npos) {
			cout << str.substr(n + 1) << ' ';
			str = str.substr(0, n);
			n = str.rfind(' ');
		}
		if(!str.empty()) {
			cout << str << endl;
		}
	}
	return 0;
}

*/

/*
int main(){
	
	int n;
	while(cin >> n){
		int ma = 0;
		int count = 0;
		while(n){
			if(n & 0x1){
				count++;
				ma = max(ma, count);
			}else{
				count = 0;
			}
			n >>= 1;
		}
		cout << ma << endl;
	}

	string str;
	while(getline(cin, str)){
		char help[1001] = {0};
		int idx = 0;
		while(idx < str.size()){
			if((str[idx] >= 'a' && str[idx] <= 'z') ||
			   (str[idx] >= 'A' && str[idx] <= 'Z')){
				help[idx]++;
			}
			idx++;
		}
		idx = 0;
		for(int j=0; j<26; j++){
			for(int i=0; i<str.size();i++){
				if(help[idx] == 0){
					cout<<str[idx];
					idx++;
					continue;
				}
				if(str[i] == (j + 'a') || str[i] == (j + 'A')){
					cout << str[i];
					idx++;
				}
			}
		}
	}
	return 0;
}
 */

int main(){
	string str;
	while(cin >> str){
		char pwd[101] = {0};
		int idx = 0;
		while(idx < str.size()){
			char c = str[idx];
			if(c >= 'A' && c <= 'Z') {
				pwd[idx] = c - ('A' - 'a') + 1;
			} else if(c >= 'a' && c <= 'c') {
				pwd[idx] = '2';
			} else if(c >= 'd' && c <= 'f') {
				pwd[idx] = '3';
			} else if(c >= 'g' && c <= 'i') {
				pwd[idx] = '4';
			} else if(c >= 'j' && c <= 'l') {
				pwd[idx] = '5';
			} else if(c >= 'm' && c <= 'o') {
				pwd[idx] = '6';
			} else if(c >= 'p' && c <= 's') {
				pwd[idx] = '7';
			} else if(c >= 't' && c <= 'v') {
				pwd[idx] = '8';
			} else if(c >= 'w' && c <= 'z') {
				pwd[idx] = '9';
			}
			else {
				pwd[idx] = c;
			}
			idx++;
		}
		cout << string(pwd) << endl;
	}
	return 0;
}

/**
bool checkPassword(string &pwd){
	if(pwd.size() <= 8){
		return false;
	}
	
	int low = 0;
	int up = 0;
	int num = 0;
	int sym = 0;
	int idx = 0;
	map<char,int>map;
	while(idx < pwd.size()) {
		char c = pwd[idx];
		if(c >= 'a' && c <= 'z') {
			low = 1;
		} else if(c >= 'A' && c <= 'Z') {
			up = 1;
		} else if (c >= '0' && c <= '9') {
			num = 1;
		} else {
			sym = 1;
		}
		map[c]++;
		idx++;
	}
	if(low + up + num + sym < 3){
		return false;
	}

	for(int i = 0; i < pwd.size() - 5; i++) {
		auto it = map.find(pwd[i]);
		if(it->second < 2) {
			continue;
		}
		
//         int count = it->second - 1;
//         while(count){
			for(int k = i + 1; k < pwd.size() - 2; k++) {
				if(pwd[k] == it->first && k - i > 2){
					if(pwd[i] == pwd[k] && pwd[i+1] == pwd[k+1] && pwd[i+2] == pwd[k+2]){
						return false;
					}
				}
			}
//             count--;
//         }
		
	}
	return true;
}
 */

/**
int main(){
	string str;
	while(getline(cin, str)){
		if(checkPassword(str)){
			cout << "OK" << endl;
		} else {
			cout << "NG" << endl;
		}
	}
	return 0;
}
 */

/*

#include<iostream>
using namespace std;
int main(){
	string str;
	while(getline(cin, str))
	{
		size_t len = str.size();
		int begin = 0;
		int end = len - 1;
		int idx = end;
		while(idx >= 0) {
			
			while(end >= 0) {
				if (str[end] != ' ')
					break;
				end--;
			}
			idx = end;
			while (idx >= 0) {
				if (str[idx] == ' ') {
					cout << str.substr(idx + 1, end - idx) << " ";
					end = idx;
					idx--;
					break;
				}
				idx--;
			}
		}

		if (end >= begin) {
			cout << str.substr(0, end - begin + 1);
		}
	}
	return 0;
}
 
 */

/**
int main() {
	string str;
	while (getline(cin, str)) {
		int len = str.length();
		int cnt = len / 8;
		int k = len;
		for (int i = 0; i <= cnt; i++) {
			if (k >= 8) {
				cout << str.substr(i * 8, 8) << endl;
				k -= 8;
			}
		}
		if (k != 0) {
			str = str.substr(cnt * 8);
			while (k++ < 9) {
				str = str.append("0");
			}
			cout << str << endl;
		}
	}
	return 0;
}
 */

/*
int main() {
	string str;
	getline(cin, str);
	int end = str.size() - 1;
	int right = -1;
	while (end >= 0) {
		if (str[end] != ' ' && right == -1) {
			right = end;
		}
		if (right != -1 && (str[end] == ' ')) {
			return end - right;
		}
		cout << end;
		end--;
	}
	return 0;
}
*/

/**
int main(int argc, const char * argv[]) {
    // insert code here...

    std::cout << "Hello, World!\n";
    Solution so;
    vector<int> vector{3,1,4,1,5};
    so.quickSort(vector, 0, 4);
	int k = so.findSubstringInWraproundString("a");
    return 0;
 
}
*/




