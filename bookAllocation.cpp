#include<iostream>

using namespace std;

bool isPossibleSol(int *arr, int mid, int size, int nos) {
    int pageSum = 0;
    int studentCount = 1;
    for(int i = 0;i < size;i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum = pageSum + arr[i];
        } else {
            studentCount++;
            if(studentCount > nos || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }

    return true;
}

int allocateBooks(int *arr, int size, int nos) {
    int start = 0;
    int sum = 0;

    for(int i = 0;i < size;i++) {
        sum += arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start) / 2;

    while(start <= end){
        if(isPossibleSol(arr, mid, size, nos)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main() {
    int arr[] = {10, 20, 30, 40};

    cout<<"Minimum Value : "<<allocateBooks(arr, 4, 2);

    return 0;
}
