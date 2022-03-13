#include<iostream>

using namespace std;

bool isPossibleSol(int * arr, int nop, int mid, int size) {
    int painterCount = 1;
    int unitSum = 0;

    for(int i = 0;i < size;i++) {
        if(unitSum + arr[i] <= mid) {
            unitSum += arr[i];
        } else {
            painterCount++;
            if(painterCount > nop || arr[i] > mid) {
                return false;
            }
            unitSum = arr[i];
        } 
    }
    return true;
}

int painters(int *arr, int nop, int size) {
    int ans = -1;
    int sum = 0;
    int start = 0;

    for(int  i = 0;i < size;i++) {
        sum += arr[i];
    }

    int end = sum;
    int mid = start + ((end - start) / 2);

    while(start <= end) {
        if(isPossibleSol(arr, nop, mid, size)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }

    return ans;
}

int main() {
    int arr[] = {5, 5, 5, 5};

    cout<<"Minimum Unit assigned to paitner "<<painters(arr, 2, 4);

    return 0;
}
