#include <iostream>
#include <stdio.h>
#include <vector>

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

// return an index of local minimum
int localMin(vector<int>& arr){
    if(arr.empty())
        return -1;
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if((mid == 0 || arr[mid - 1] > arr[mid]) && (mid == arr.size()-1 || arr[mid] < arr[mid + 1]))
            return mid;
        else if(mid > 0 && arr[mid] > arr[mid - 1])
            right = mid - 1;
        else
            left = mid + 1;
    }
}

// search an element in a sorted array using binary search
int search(vector<int>& arr, int target){
    if(arr.empty())
        return -1;
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] >= arr[left]){ // mid is on the left side of tuning point
            if(target >= arr[left] && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else{ // mid is on the right side of tuning point
            if(target <= arr[right] && target > arr[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}


int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    int n = arr.size();
//    cout << localMin(arr) << endl;
    cout << search(arr, 0);
//    ArrayPrint(arr);
    return 0;
}