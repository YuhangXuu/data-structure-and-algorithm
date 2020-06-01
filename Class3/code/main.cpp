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

int removeDuplicates2(vector<int>& arr){
    if(arr.empty())
        return 0;
    int n = arr.size();
    int curIndex = 0;
    for(int i = 0; i < n; i++) {
        if (curIndex < 2 || arr[i] > arr[curIndex - 2])
            arr[curIndex++] = arr[i];
    }
    return curIndex;
}

void removeDuplicates3(vector<int>& arr){
    if(arr.empty())
        return;
    int n = arr.size();
    int slow = 0, fast = 0, cur = 0;
    int count = 0;
    while(fast < n){
        if(arr[fast] == arr[slow]) {
            fast++;
            continue;
        }
        if(fast - slow == 1)
            arr[cur++] = arr[slow];
        slow = fast;
    }
    // check if the last element is unique
    if(slow == n - 1)
        arr[cur++] = arr[slow];
    // erase the elements at the end of the array
    arr.erase(arr.begin() + cur, arr.end());
}

int findMin(vector<int>& arr){
    if(arr.empty())
        return -1;
    int left = 0, right = arr.size() - 1;

    // it is a sorted array without rotation
    if(arr[left] < arr[right])
        return arr[left];

    while(left < right){
        int mid = left + (right - left) / 2;
        if(arr[mid] > arr[mid + 1])
            return arr[mid + 1];
        if(arr[mid] > arr[0])
            left = mid + 1;
        else
            right = mid;
    }
    return arr[left];
}

// Find closest element to integer target in array arr using binary search
// Same code in homework 2
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

vector<int> findClosestElements(vector<int>& arr, int k, int target) {
    int n = arr.size() - 1;
    if(target <= arr[0])
        return vector<int> (arr.begin(), arr.begin() + k);
    else if(target >= arr[n])
        return vector<int> (arr.end() - k, arr.end());
    int index = findClosest(arr, target);
    int left = max(0, index - k + 1);
    int right = min(n, index + k - 1);
    while(right - left + 1 > k){
        if(abs(arr[left] - target) <= abs(arr[right] - target))
            right--;
        else
            left++;
    }
    return vector<int> (arr.begin() + left, arr.begin() + right + 1);
}

// same code in homework2
int partition(vector<int>& arr, int left, int right){
    int i = left;
    int j = right - 1;
    int& pivot = arr[right];
    while(i<=j){
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

void quickSort(vector<int>& arr, int left, int right){
    if(left < right) {
        int pos = partition(arr, left, right);
        quickSort(arr, left, pos - 1);
        quickSort(arr, pos + 1, right);
    }
}

// Find the pair of elements in arr that sum to a value that is closest to target
vector<int> twoSumClosest(vector<int>& arr, int target){
    vector<int> result;
    int n = arr.size() - 1;
    // sort the array arr using quick sort
    quickSort(arr, 0, n);
    int left = 0, right = n;
    while(left < right - 1){
        int sum = arr[left] + arr[right];
        if(sum > target) {
            if(abs(sum - target) < abs(arr[left] + arr[right - 1] - target))
                break;
            right--;
        }
        else {
            if(abs(sum - target) < abs(arr[left + 1] + arr[right] - target))
                break;
            left++;
        }
    }
    result.push_back(arr[left]);
    result.push_back(arr[right]);
    return result;
}

int twoSumSmaller(vector<int>& arr, int target){
    int n = arr.size() - 1;
    // sort the array arr using quick sort
    quickSort(arr, 0, n);
    int left = 0, right = n;
    int count = 0;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum < target){
            count += (right - left);
            left++;
        }
        else
            right--;
    }
    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();
    int target = 7;
//    cout << removeDuplicates2(arr) << endl;
//    removeDuplicates3(arr);
//    vector<int> arrResult = findClosestElements(arr, 3, 2);
//    ArrayPrint(arrResult);
//    vector<int> arrResult = twoSumClosest(arr, target);
//    ArrayPrint(arrResult);
    cout << twoSumSmaller(arr, target)<< endl;
    return 0;
}