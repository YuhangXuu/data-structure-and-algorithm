#include <iostream>
#include <vector>
#include <string>

using namespace std;


void arrayPrint(vector<string>& s){
    int n = s.size();
    for(int i = 0; i < n; i++) {
        cout << " " << s.at(i) << " ";
//        printf(" %d ", arr.at(i));
    }
    cout << endl;
}

void FindSubSet(const string& s, int index, string& result, vector<string>& results){
    if(index == s.length()){
        results.push_back(result);
        return;
    }
    result.push_back(s[index]);
    FindSubSet(s, index+1, result, results);
    result.pop_back();
    FindSubSet(s, index+1, result, results);
}

void FindSubSet1_2(const string& s, int index, string& result, vector<string>& results){
    results.push_back(result);
    for(int i = index; i < s.size(); i++){
        result.push_back(s[i]);
        FindSubSet1_2(s, i+1, result, results);
        result.pop_back();
    }
}

void combinations(int n, int k, int index, vector<int>& result, vector< vector<int> >& results){
    if(result.size() == k){
        results.push_back(result);
        return;
    }
    for(int i = index; i < n; i++){
        result.push_back(i+1);
        combinations(n, k, i+1, result, results);
        result.pop_back();
    }
}

void permutations(const string& s, int level, vector<int>& visited, string& result, vector<string>& results){
    if(level == s.size()) {
        results.push_back(result);
        return;
    }
    for(int i = 0; i < s.length(); i++){
        if(visited[i] == 1)
            continue;
        else
            visited[i] = 1;
        result.push_back(s[i]);
        permutations(s, level+1, visited, result, results);
        result.pop_back();
        visited[i] = 0;
    }
}

// sort string using quick sort
void stringSort(string& s){
    sort(s.begin(), s.end());
}

void FindSubSet2(const string& s, int index, string& result, vector<string>& results){
    results.push_back(result);
    for(int i = index; i < s.size(); i++){
        // add a condition here
        if(i != index && s[i] == s[i-1])
            continue;
        result.push_back(s[i]);
        FindSubSet2(s, i+1, result, results);
        result.pop_back();
    }
}

void permutations2(const string& s, int level, vector<int>& visited, string& result, vector<string>& results){
    if(level == s.size()) {
        results.push_back(result);
        return;
    }
    for(int i = 0; i < s.length(); i++){
        // add a condition here
        if(i > 0 && visited[i-1] == 1 && s[i-1] == s[i])
            continue;
        if(visited[i] == 1)
            continue;
        else
            visited[i] = 1;
        result.push_back(s[i]);
        permutations2(s, level+1, visited, result, results);
        result.pop_back();
        visited[i] = 0;
    }
}

int main() {
    // problem 1
//    string s = "abc";
//    string result;
//    vector<string> results;
//    FindSubSet(s, 0, result, results);
//    arrayPrint(results);

    // problem 2
//    vector<int> result;
//    vector< vector<int> > results;
//    combinations(4, 2, 0, result, results);
//    for(auto& result : results)
//        arrayPrint(result);

    // problem 3
//    string s = "abc";
//    vector<int> visited (s.size(), 0);
//    string result;
//    vector<string> results;
//    permutations(s, 0, visited, result, results);
//    arrayPrint(results);

    // problem 4
//    string s = "abab";
//    string sSorted;
//    string result;
//    vector<string> results;
//    stringSort(s);
////    cout << s << endl;
//    FindSubSet2(s, 0, result, results);
//    arrayPrint(results);

    // problem 5
    string s = "abaa";
    vector<int> visited (s.size(), 0);
    string result;
    vector<string> results;
    stringSort(s);
    permutations2(s, 0, visited, result, results);
    arrayPrint(results);
    return 0;
}