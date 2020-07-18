#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;
#define h 26
int substrSearch(string txt, string pat){
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

string commonPrefix(string a, string b){
    int index;
    while(index < a.length() && index < b.length()){
        if(a[index] != b[index])
            break;
        else
            index++;
    }
    return a.substr(0, index);
}

string longestCommonPrefix(vector<string> strs){
    string prefix = strs[0];
    for(int i = 1; i < strs.size(); i++)
        prefix = commonPrefix(prefix, strs[i]);
    return prefix;
}

bool oneEditDistance(string str1, string str2){
    int m = str1.length();
    int n = str2.length();
    if(abs(m - n) > 1)
        return false;
    int i = 0, j = 0;
    int count = 0;
    while(i < m && j < n){
        if(str1[i] != str2[j]){
            count++;
            if(count == 2)
                return false;
            if(m > n)
                i++;
            else if(n > m)
                j++;
            else{
                i++;
                j++;
            }
        }
        else{
            i++;
            j++;
        }
    }
    while(i < m){
        i++;
        count++;
    }
    while(j < n){
        j++;
        count++;
    }
    return count == 1;
}

// remove a specific char from string
void removeChar(string& s, char c){
    int slow = 0, fast = 0;
    while(1){
        while(fast < s.size() && s[fast] == c)
            fast++;
        if(fast == s.size())
            break;
        while(fast < s.size() && s[fast] != c)
            s[slow++] = s[fast++];
    }
    s.resize(slow);
    return;
}

void remove(string&s, string t){
    for(int i = 0; i < t.length(); i++)
        removeChar(s, t[i]);
    return;
}

int main() {
    // problem 1
//    string txt = "bcabc";
//    string pat = "ab";
//    cout << substrSearch(txt, pat) << endl;

    // problem 2
//    vector<string> strs = {"abcalksjd", "abcqwek", "abcertoid", "abcoert"};
//    vector<string> strs = {"a", "a"};
//    cout << longestCommonPrefix(strs) << endl;

    // problem 3
//    string str1 = "aa";
//    string str2 = "aab";
//    oneEditDistance(str1, str2) ? cout << "Yes" : cout << "No";

    // problem 4
    string s = "cbabs";
    string c = "cb";
    remove(s, c);
    cout << s << endl;
    return 0;
}