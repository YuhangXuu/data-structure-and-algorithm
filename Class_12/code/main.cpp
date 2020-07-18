#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;
void arrayPrint(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        cout << arr.at(i) << " ";
    }
    cout << endl;
}

int kthSmallest23(int k){
    priority_queue<int, vector<int>, greater<int> > pq; // min heap
    unordered_map<int, int> umap;
    int minVal = -1;
    pq.push(1);
    for(int i = 0; i < k; i++){
        minVal = pq.top();
        pq.pop();
        int val1 = minVal * 2;
        int val2 = minVal * 3;

        if(umap.find(val1) == umap.end()){
            pq.push(val1);
            umap[val1] = 1;
        }

        if(umap.find(val2) == umap.end()){
            pq.push(val2);
            umap[val2] = 1;
        }
    }
    return minVal;
}

vector<int> superUglyNum(vector<int> primes, int n){
    priority_queue<int, vector<int>, greater<int> > pq; // min heap
    unordered_map<int, int> umap;
    vector<int> res;
    int minVal = -1;
    pq.push(1);
    for(int i = 0; i < n; i++){
        minVal = pq.top();
        res.push_back(minVal);
        pq.pop();
        vector<int> temp;
        for(int j = 0; j < primes.size(); j++){
            int val = minVal * primes[j];
            if(umap.find(val) == umap.end()){
                pq.push(val);
                umap[val] = 1;
            }
        }
    }
    return res;
}

// define input as global parameter
vector<int> a = {1, 3, 5}, b = {2, 4}, c = {3, 6};

struct MyCmp{
    bool operator()(vector<int> loc1, vector<int> loc2) {
        int sum1 = pow(a[loc1[0]], 2) + pow(b[loc1[1]], 2) + pow(c[loc1[2]], 2);
        int sum2 = pow(a[loc2[0]], 2) + pow(b[loc2[1]], 2) + pow(c[loc2[2]], 2);
        return sum1 > sum2;
    }
};

vector<int> kthCloestPoint(vector<int> a, vector<int> b, vector<int> c, int k) {
    priority_queue< vector<int>, vector<vector<int> >, MyCmp> pq;
    map<vector<int>, int> Map;
    vector<int> loc(3, 0);
    pq.push(loc);
    for(int i = 0; i < k; i++){
        loc = pq.top();
        pq.pop();

        loc[0]++;
        if(loc[0] < a.size() && Map.find(loc) == Map.end()){
            pq.push(loc);
            Map[loc] = 1;
        }
        loc[0]--;

        loc[1]++;
        if(loc[1] < b.size() && Map.find(loc) == Map.end()){
            pq.push(loc);
            Map[loc] = 1;
        }
        loc[1]--;

        loc[2]++;
        if(loc[2] < c.size() && Map.find(loc) == Map.end()){
            pq.push(loc);
            Map[loc] = 1;
        }
        loc[2]--;
    }
    return { a[loc[0]], b[loc[1]], c[loc[2]]};
}

// define input as global parameter
vector< vector<int> > matrix = {{1, 3, 5, 7},
                                {2, 4, 8, 9},
                                {3, 5, 11, 15},
                                {6, 8, 13, 18}};

struct MyCmp2 {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        int val1 = matrix[a.first][a.second];
        int val2 = matrix[b.first][b.second];
        return val1 > val2;
    }
};

int kthSmallest(vector<vector<int>> matrix, int k) {
    priority_queue< pair<int, int>, vector<pair<int, int> >, MyCmp2> pq;
    map<pair<int, int>, int> Map;
    pair<int, int> pos(0, 0);
    pq.push(pos);
    for(int i = 0; i < k; i++){
        pos = pq.top();
        pq.pop();

        pos.first++;
        if(pos.first < matrix.size() && Map.find(pos) == Map.end()){
            pq.push(pos);
            Map[pos] = 1;
        }
        pos.first--;

        pos.second++;
        if(pos.second < matrix[0].size() && Map.find(pos) == Map.end()){
            pq.push(pos);
            Map[pos] = 1;
        }
        pos.second--;
    }
    return matrix[pos.first][pos.second];
}

int main() {
    // problem 1
//    for(int i = 1; i <= 8; i++) {
//        cout << i << ", " << kthSmallest23(i) << endl;
//    }

    // problem 2
//    vector<int> primes = {2, 7, 13, 19};
//    vector<int> res = superUglyNum(primes, 12);
//    arrayPrint(res);

    // problem 3
//    vector<int> result = kthCloestPoint(a, b, c, 2);
//    arrayPrint(result);

    // problem 4
    for(int i = 1; i <= 10; i++){
        cout << kthSmallest(matrix, i) << ", ";
    }
}