#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;
void ArrayPrint(vector<string>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        cout << " " << arr.at(i) << " ";
    }
}

void RemoveSpace(string& s){
    int slow = 0, fast = 0;
    int wordCount = 0;
    while(1){
        while(fast < s.size() && s[fast] == ' ')
            fast++;
        if(fast == s.size())
            break;
        if(wordCount > 0)
            s[slow++] = ' ';
        while(fast < s.size() && s[fast] != ' ')
            s[slow++] = s[fast++];
        wordCount++;
    }
    s.resize(slow);
    return;
}

string rightShift(string s, int k){
    string result;
    int mid = s.length() - k % s.length();
    // result = s[mid, :] + s[:mid]
    return string(s.begin() + mid, s.end()) + string(s.begin(), s.begin() + mid);
}

void reverse(string& s, int left, int right){
    char temp;
    while(left < right){
        temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

void reverseWords(string& s){
    int slow = 0, fast = 0;
    if(s.length() == 0)
         return;
    while(fast <= s.length()) {
        if(s[fast] == '\0') {
            reverse(s, slow, fast - 1);
            // reverse the whole string after reversing every words
            reverse(s, 0, fast - 1);
            return;
        }
        if(s[fast] == ' ') {
            reverse(s, slow, fast - 1);
            slow = fast + 1;
        }
        fast++;
    }
    return;
}

string addBinary(string a, string b){
    string result = "";
    int i = a.length() - 1, j = b.length() - 1;
    int sum = 0, carry = 0;
    while(i >= 0 || j >= 0 || carry == 1){
        sum = 0;
        sum += (i >= 0) ? a[i] - '0' : 0;
        sum += (j >= 0) ? b[j] - '0' : 0;
        sum += carry;

        result = char(sum % 2 + '0') + result;
        // compute new carry
        carry = sum / 2;
        i--;
        j--;
    }
    return result;
}

// Problem in HW5
// convert string to int in the vector
vector<int> binaryTreeConvert(vector<string> binaryTreeString){
    vector<int> binaryTree;
    for(auto it : binaryTreeString){
        if(it[0] != '#')
            binaryTree.push_back(stoi(it));
        else
            binaryTree.push_back(-1);
    }
    return binaryTree;
}

// iterative, in-order traversal of binary tree.
vector<string> inOrder(vector<string> binaryTreeString){
    // convert string to int
    vector<int>binaryTree = binaryTreeConvert(binaryTreeString);
    vector<int> resultIdx;
    vector<string> result;
    stack<int> s;
    int n = binaryTree.size();
    int curr = 0;
    while(binaryTree[curr] != -1 || !s.empty()){
        while(binaryTree[curr] != -1 && curr <= n - 1){
            s.push(curr);
            curr = 2 * curr + 1;
        }
        curr = s.top();
        s.pop();
        resultIdx.push_back(curr);
        curr = 2 * curr + 2;
    }
    for(int i = 0; i < resultIdx.size(); i++)
        result.push_back(binaryTreeString[resultIdx[i]]);
    return result;
}

int main() {
    // problem 1
//    string s = "    I    love  you.   ";
//    RemoveSpace(s);
//    cout << s << endl;

    // problem 2
//    string s = "abcde";
//    string result = rightShift(s, 3);
//    cout << result << endl;

    // problem 3
//    string s = "I love you";
//    reverseWords(s);
//    cout << s << endl;

    // problem 4
//    string s = "     I   love   you    ";
//    RemoveSpace(s);
//    reverseWords(s);
//    cout << s << endl;

    // problem 5
    string a = "1101", b="100";
    cout << addBinary(a, b) << endl;
    // problem 6
//    vector<string> binaryTreeString = {"11", "22", "33", "#", "#", "44", "#"};
//    vector<string> result = inOrder(binaryTreeString);
//    ArrayPrint(result);
}