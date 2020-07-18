//
// Created by 徐宇航 on 5/25/20.
//
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ArrayPrint(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        cout << arr.at(i) << endl;
    }
}

// sort an array arr using insertion sort.
void InsertionSort(vector<int>& arr){
    int n = arr.size();
    int temp, j;
    if(arr.empty()) {
        cout << "arr is empty." << endl;
        return;
    }
    for(int i = 1; i < n; i++){ // number of iterations
        temp = arr[i];
        j = i - 1;
        // move the arr[j] one position head if it's greater than temp
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        // find the position for temp
        arr[j + 1] = temp;
    }
}

// sort an array arr using selection sort.
void SelectionSort(vector<int>& arr){
    int n = arr.size();
    int temp, global;
    if(arr.empty()) {
        cout << "arr is empty." << endl;
        return;
    }
    for(int i = 0; i < n - 1; i++){
        global = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[global])
                global = j;
        }
        // switch arr[i] and arr[global] (min value)
        swap(arr[i], arr[global]);
    }
}

// use the last element in arr as the pivot, move it to the correct position in sorted array.
int partition(vector<int>& arr, int low, int high){
    int& pivot = arr[high];
    int i = low;
    int j = high - 1;
    while(i <= j){
        if(arr[i] < pivot)
            i++;
        else{
            swap(arr[i], arr[j]);
            j--;
        }
    }
    swap(arr[i], pivot);
    return i;
}

// sort an array arr using quick sort.
void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos+1, high);
    }
}

// Merge two sorted sub-array of arr from the end
void merge(vector<int>& arr, int low, int mid, int high){
    int n1 = mid - low;
    int n2 = high - mid - 1;
    int n3 = high;
    vector<int> lArr, rArr;
    // copy two sub-arrays to lArr, rArr
    for(int i = 0; i <= n1; i++)
        lArr.push_back(arr[low + i]);
    for(int i = 0; i <= n2; i++)
        rArr.push_back(arr[mid + 1 + i]);
    // merge two sub-arrays from the end
    while(n1 >= 0 && n2 >= 0){
        if(rArr[n2] > lArr[n1])
            arr[n3--] = rArr[n2--];
        else
            arr[n3--] = lArr[n1--];
    }
    // copy the remaining elements in lArr or rArr (if any) to arr
    while(n1 >= 0) {
        arr[n3--] = lArr[n1--];
    }
    while(n2 >= 0) {
        arr[n3--] = rArr[n2--];
    }
}

// sort an array arr using merge sort.
void mergeSort(vector<int>& arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

// Sort arr1 in such a way that the relative order among the elements will be same as those are in arr2.
void relativeSortArray(vector<int>& arr1, vector<int>& arr2){
    unordered_map<int, int> map;
    int m = arr1.size();
    int n = arr2.size();
    // use a hash table to store count of each element in arr, it takes O(m) time
    for(int i = 0; i < m; i++){
        if(map.find(arr1[i]) == map.end())
            map[arr1[i]] = 1;
        else
            map[arr1[i]]++;
    }
    // If the element in arr2 present in map, put in arr1 that many times, it takes O(n) time
    int p = 0;
    for(int i = 0; i < n; i++){
        if(map.find(arr2[i]) == map.end())
            continue;
        while(map[arr2[i]] > 0) {
            arr1[p++] = arr2[i];
            map[arr2[i]]--;
        }
    }
    // put the rest of numbers to restArr
    vector<int> restArr;
    for(auto& it : map){
        while(it.second != 0) {
            restArr.push_back(it.first);
            it.second--;
        }
    }
    // sort restArr using quick sort and put in arr1, it takes O(qlogq) time
    int q = restArr.size();
    quickSort(restArr, 0, q-1);
    for(int i = 0; i < q; i++)
        arr1[p++] = restArr[i];
}

int main() {
//    vector<int> arr = {12,11,13,5,6,1};
//    vector<int> arr = {4, 2, -3, 6, 1};
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
//    int n = arr.size() - 1;
//    SelectionSort(arr);
//    InsertionSort(arr);
//    quickSort(arr, 0, n);
//    mergeSort(arr, 0, n);
    relativeSortArray(arr1, arr2);
    ArrayPrint(arr1);

    return 0;

}