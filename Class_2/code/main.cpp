#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void swap(int*a, int*b){
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

// sort an array of balls arr using rainbow sort, similar to quick sort.
// general solution for rainbow sort problem
void rainbowSort(vector<int>& arr, int left, int right, int color_from, int color_to){
    if(left==right || color_from == color_to)
        return;
    int pivot = color_from + (color_to - color_from) / 2;
    int i = left;
    int j = right;
    while(i <= j){
        if(arr[i] <= pivot)
            i++;
        else{
            swap(arr[i], arr[j]);
            j--;
        }
    }
    rainbowSort(arr, left, i-1, color_from, pivot);
    rainbowSort(arr, i, right, pivot+1, color_to);
}

// move all the 0s to the right end of the array arr,
// and remain the relative order in the original array.
void moveZeroToEnd(vector<int>& arr){
    int n = arr.size() - 1;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0)
            swap(arr[count++], arr[i]);
    }
}

// find first occurance of integer target in array arr
int first(vector<int>& arr, int target){
    if(arr.empty())
        return -1;
    int left = 0;
    int right = arr.size() - 1;
    while(left < right - 1){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            right = mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    // post-processing
    if(arr[left] == target)
        return left;
    if(arr[right] == target)
        return right;
    return -1;
}

// find last occurance of integer target in array arr
int last(vector<int>& arr, int target){
    if(arr.empty())
        return -1;
    int left = 0;
    int right = arr.size() - 1;
    while(left < right - 1){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            left = mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    // post-processing
    if(arr[right] == target)
        return right;
    if(arr[left] == target)
        return left;
    return -1;
}

// Find closest element to integer target in array arr
int findClosest(vector<int>& arr, int target){
    if(arr.empty())
        return -1;
    int left = 0;
    int right = arr.size() - 1;
    while(left < right - 1){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid;
        else
            right = mid;
    }
    // post-processing
    if(abs(arr[left] - target) <= abs(arr[right] - target))
        return left;
    else
        return right;
}

// Return the index where it would be if it were inserted in order.
int searchInsert(vector<int>& arr, int target) {
    if(arr.empty())
        return 0;
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

//classical version of binary search
int binarySearch(vector<int>& arr, int target){
    if(arr.empty())
        return -1;
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {1,3,5,6};
    int n = arr.size() - 1;
    int target = 0;
//    rainbowSort(arr, 0, n, -1, 1);
//    moveZeroToEnd(arr);
//    ArrayPrint(arr);
//    cout << first(arr, target) << ',' << last(arr, target) << endl;
//    cout << findClosest(arr, target) << endl;
    cout << searchInsert(arr,target) << endl;
    return 0;
}