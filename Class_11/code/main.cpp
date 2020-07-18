#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;
void printArray(vector<int> result){
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

int differentBits(int a, int b){
    int count = 0;
    for(unsigned int c = a ^ b; c != 0; c = c >> 1){
        count += (c & 1);
    }
    return count;
}

bool isUnique(string s){
    vector<int> dic(8, 0);
    for(int i = 0; i < s.length(); i++){
        int row = s[i] / 32;
        int col = s[i] % 32;
        if( (dic[row] >> col) & 1)
            return false;
        else
            dic[row] = dic[row] | (1 << col);
    }
    return true;
}

vector<int> countBits(int num){
    vector<int> result(num+1, 0);
    for(int i = 1; i <= num; i++){
        result[i] = result[i >> 1] + (i & 1);
    }
    return result;
}

int missingNum(vector<int> nums){
    if(nums.empty())
        return 1;
    int n = nums.size();
    int x1 = nums[0];
    int x2 = 1;
    for(int i = 1; i < n; i++){
        x1 = x1 ^ nums[i];
    }
    for(int i = 2; i <= n + 1; i++){
        x2 = x2 ^ i;
    }
    return int(x1 ^ x2);
}

int rangeAnd(int a, int b){
    int count = 0;
    while(a != b){
        a = a >> 1;
        b = b >> 1;
        count ++;
    }
    return int (a << count);
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
            string nums = to_string(count);
            for(int i = 0; i < nums.length(); i++){
                s[slow++] = nums[i];
            }
        }
    }
    s.resize(slow);
    return;
}

int main() {
    // problem 1
//    int a = 8;
//    int b = 5;
//    cout << differentBits(a, b) << endl;

    // problem 2
//    string s = "abA+\\a88";
//    cout << isUnique(s) << endl;

    // problem 3
//    vector<int> result = countBits(5);
//    printArray(result);

    // problem 4
//    vector<int> nums = {2, 1, 4};
//    cout << missingNum(nums) << endl;

    // problem 5
//    int a = 5, b = 7;
//    cout << rangeAnd(a, b) << endl;

    // problem 6
    string s = "bbcaaaaaaaaaaaadee"; // 12 'a'
    cout << s << endl;
    compressString(s);
    cout << s << endl;
    return 0;
}