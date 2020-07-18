#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ArrayPrint(vector<string>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        cout << " " << arr.at(i) << " ";
//        printf(" %d ", arr.at(i));
    }
    cout << endl;
}

// return smallest k elements from an unsorted array
vector<int> kSmallest(vector<int> arr, int k){
    // define a min heap
    priority_queue <int, vector<int>, greater<int>> pq;
    vector<int> result;
    // push the elements to min heap
    for(int i = 0; i < arr.size(); i++)
        pq.push(arr[i]);
    // output the top element and pop it
    for(int i = 0; i < k; i++){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}


// return a list of the top K most frequent words
vector<string> kFrequentWords(vector<string> words, int k){
    vector<string> result;
    unordered_map<string, int> wordFreq;
    // store the frequency of words
    for(int i = 0; i < words.size(); i++){
        wordFreq[words[i]]++;
    }
    // define the comparasion rules in the heap
    struct MyCmp {
        bool operator() (const pair<string, int>& a, const pair<string, int>& b){
            if(a.second != b.second)
                return a.second < b.second;
            else
                return a.first > b.first;
        }
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, MyCmp> pq;
    // store words and their freqency in heap;
    for(auto& it : wordFreq){
        pq.push(make_pair(it.first, it.second));
    }
    // output the top element and pop it
    for(int i = 0; i < k; i++){
        result.push_back(pq.top().first);
        pq.pop();
    }
    return result;
}

// two heap to keep tracking median
class MedianFinder{
    priority_queue<int> lo; // max heap
    priority_queue<int, vector<int>, greater<int>> hi; // min heap
public:
    void read(int value){
        lo.push(value);
        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }

    double median(){
        if(lo.size() == hi.size())
            return (lo.top() + hi.top()) * 0.5;
        else
            return lo.top();
    }
};

const int GATE = 0;
const int EMPTY = 2147483647;
const int WALL = -1;
vector< vector<int> > directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // up, down, left, right
void wallsAndGates(vector< vector<int> >& rooms){
    queue< vector<int> > q;
    // find all the gate locations in mxn matrix, and push to the queue
    int m = rooms.size();
    if(m == 0) return;
    int n = rooms[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(rooms[i][j] == GATE)
                q.push({i ,j});
        }
    }
    while(q.size()){
        vector<int> first = q.front();
        q.pop();
        int row = first[0];
        int col = first[1];
        for(auto& direction : directions){
            int r = row + direction[0];
            int c = col + direction[1];
            if(r < 0 || r >= m || c < 0 || c >= n || rooms[r][c] != EMPTY)
                continue;
            rooms[r][c] = rooms[row][col] + 1;
            q.push({r, c});
        }
    }
}

// compute sum of two 2d matrix, store the result in a
void vectorSum(vector< vector<int> >& a, vector< vector<int> > b) {
    int m = a.size();
    int n = a[0].size();
    vector< vector<int> > result(m, vector<int> (n, 0));
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            a[r][c] += b[r][c];
        }
    }
}

// return the location of minimum value in 2d matrix
vector<int> vectorMin(vector< vector<int> > a){
    int m = a.size();
    int n = a[0].size();
    int row = -1;
    int col = -1;
    int min = 10000000;
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            if(a[r][c] > 0 && a[r][c] <= min){
                min = a[r][c];
                row = r;
                col = c;
            }
        }
    }
    return {row, col};
}

// return distance from a  'E' to each 'C' in the matrix
vector< vector<int> > distanceFromEquipment(vector< vector<char> > gym, vector<int> eLoc){
    int m = gym.size();
    int n = gym[0].size();
    vector< vector<int> > count(m, vector<int> (n, 0)); // initialize a mxn zero matrix
    vector< vector<int> > test(m, vector<int> (n, 0));
    queue< vector<int> > q;
    q.push(eLoc);
    while(!q.empty()){
        vector<int> first = q.front();
        q.pop();
        int row = first[0];
        int col = first[1];
        for(auto& direction : directions){
            int r = row + direction[0];
            int c = col + direction[1];
            if(r < 0 || r >= m || c < 0 || c >= n || gym[r][c] != 'C' || count[r][c] != 0)
                continue;
            count[r][c] = count[row][col] + 1;
            q.push({r, c});
        }
    }
    return count;
}

vector<int> putChair(vector< vector<char> > gym){
    vector< vector<int> > eLocation;
    int m = gym.size();
    int n = gym[0].size();
    vector< vector<int> > countSum(m, vector<int> (n, 0));
    // find the location of all E
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            if(gym[r][c] == 'E') {
                vector<vector<int> > count = distanceFromEquipment(gym, {r, c});
                vectorSum(countSum, count);
            }
        }
    }
    return vectorMin(countSum);
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    vector<string> words = {"a", "a", "b", "b", "b", "c", "c", "c", "d"};
    vector< vector<int> > rooms = {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},
                                   {2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    vector< vector<char> > gym = { { 'E', 'O', 'C' },
                                  {  'C', 'E', 'C' },
                                  {  'C', 'C', 'C' } };
//    vector<int> result = kSmallest(arr, 3);
//    ArrayPrint(result);
//    vector<string> result = kFrequentWords(words, 2);
//    ArrayPrint(result);

//    wallsAndGates(rooms);
//    int m = rooms.size();
//    int n = rooms[0].size();
//    for(int i = 0; i < m; i++){
//        for(int j = 0; j < n; j++){
//            cout << " " << rooms[i][j] << " ";
//        }
//        cout << endl;
//    }
//    vector< vector<int> > count = distanceFromEquipment(gym, {1, 1});
    vector<int> chairLocation = putChair(gym);
    cout << chairLocation[0] << " " << chairLocation[1] << endl;

    return 0;
}