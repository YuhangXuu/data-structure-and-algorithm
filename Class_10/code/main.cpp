#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <string>
#include<queue>

using namespace std;
void ArrayPrint(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        cout << arr.at(i) << endl;
    }
}

void decompressString(string& s){
    int d = 0;
    int sLen = s.length();
    // compute the length of new string
    for(int i = 0; i < sLen; i++){
        if(isdigit(s[i]))
            d += s[i] - '2';
    }
    int slow = sLen + d - 1, fast = sLen - 1;
    // modify length of string if necessary
    s.resize(slow+1);
    while(fast >= 0){
        int num = 0;
        // when we encounter a digit, store the num
        if(isdigit(s[fast])) {
            num = s[fast] - '0';
            fast--;
            while(num > 0){
                s[slow--] = s[fast];
                num--;
            }
            // move to next element (next digit or character)
            fast--;
        }
        else
            s[slow--] = s[fast--];
    }
}

void encodeSpace(string &s){
    int sLen = s.length();
    int d = 0;
    // compute length of new string
    for(int i = 0; i < sLen; i++){
        if(s[i] == ' ')
            d += 2;
    }
    int fast = sLen - 1, slow = sLen + d - 1;
    // modify the length of string if necessary
    s.resize(slow+1);
    while(fast >= 0){
        if(s[fast] == ' '){
            s[slow--] = '0';
            s[slow--] = '2';
            s[slow--] = '%';
            fast--;
        }
        else
            s[slow--] = s[fast--];
    }
}

// Rabin-Karp method to find all substring (HW9)
#define h 26
int substrSearch(string txt, string pat){
    vector<int> result;
    int patLen = pat.length();
    int txtLen = txt.length();
    int t = 0, p = 0, q = 1;

    // compute pow(h, patLen - 1)
    for(int i = 0; i < patLen - 1; i++)
        q = q * h;
    // compute the hash value of txt and pat window
    for(int i = 0; i < pat.length(); i++){
        t =  t * h + (txt[i] - 'a');
        p = p * h + (pat[i] - 'a');
    }
    // move the window from left to right and compute new hash value for txt window
    for(int i = 0; i <= txtLen - patLen; i++){
        if(t == p)
            return i;
        t = (t - (txt[i] - 'a') * q) * h + (txt[i + patLen] - 'a');
    }
    return -1;
}

// if length of s >= length of t, traverse from left to right
void longToShort(string& input, string s, string t, int index){
    if(index == -1)
        return;
    int sLen = s.length();
    int tLen = t.length();
    int slow = index, fast = index + sLen;
    for(int i = 0; i < tLen; i++){
        input[slow++] = t[i];
    }
    while(fast < input.length()){
        input[slow++] = input[fast++];
    }
    input.resize(slow);
}

// if length of s < length of t, traverse from right to left
void shortToLong(string& input, string s, string t, int index){
    if(index == -1)
        return;
    int fast = input.length() - 1, slow = input.length() + (t.length() - s.length()) - 1;
    input.resize(slow+1);
    int rIndex = index + s.length() - 1;
    while(fast > rIndex){
        input[slow--] = input[fast--];
    }
    for(int i = t.length() - 1; i >= 0; i--){
        input[slow--] = t[i];
    }
    return;
}

void stringReplace(string& input, string s, string t){
    int index = substrSearch(input, s);
    if(index == -1)
        return;
    int sLen = s.length();
    int tLen = t.length();
    while(index != -1) {
        if(sLen >= tLen){
            longToShort(input, s, t, index);
            index = substrSearch(input, s);
        }else{
            shortToLong(input, s, t, index);
            index = substrSearch(input, s);
        }
    }
    return;
}

void compressString(string& s){
    int slow = 0;
    for(int i = 0; i < s.length(); i++){
        int count = 1;
        while(i < s.length() - 1 && s[i] == s[i+1]){
            i++;
            count++;
        }
        s[slow++] = s[i];
        if(count > 1) {
            s[slow++] = char(count + '0');
        }
    }
    s.resize(slow);
    return;
}

void kthSmallest23(int k){
    priority_queue<int, vector<int>, greater<int> > pq; // min heap
    unsorted_map<int, int> umap;
    pq.push(1);
    for(int i = 0; i < k; i++){
        int minVal = pq.top();
        pq.pop();
        int val1 = minVal * 2;
        int val2 = minVal * 3;

        if(umap.find(val1) == umap.end()){
            pq.push(val1);
            umap[val1] = 1;
        }

        if(umap.find(val2) == umap.end()){
            pq.push(val2);
            umap[val1] = 1;
        }
    }
    return minVal;
}

int main() {
    // problem 1
//    string s = "d2abrgc3"; // -> acbbcccc
//    decompressString(s);
//    cout << s << endl;

    // problem 2
//    string s = "  I Love  You  ";
//    encodeSpace(s);
//    cout << s << endl;

    // problem 3
//    string input = "a";
//    string s = "a";
//    string t = "ct";
//    stringReplace(input, s, t);
//    cout << input << endl;

    // problem 4
    string s = "abbcccdeee";
    cout << s << endl;
    compressString(s);
    cout << s << endl;
    return 0;
}