#include<iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPossibleSol(int *arr, int mid, int noc, int size) {
    int cowCount = 1;
    int lastPos = arr[0];

    for(int i = 0;i < size;i++) {
        if(arr[i] - lastPos >= mid) {
            cowCount++;
            if(cowCount == noc) {
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
} 

int aggressiveCows(int *arr, int size, int noc) {
    sort(arr, arr + size);

    int start = 0;
    int maxi = -1;

    for(int i = 0;i < size;i++) {
        maxi = max(maxi, arr[i]);
    }

    int end = maxi;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start <= end) {
        if(isPossibleSol(arr, mid, noc, size)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int main() {

    int arr[] = {4, 2, 1, 3, 6};

    cout<<"Maximum Possible distance between 2 cows is "<<aggressiveCows(arr, 5, 2);

    return 0;
}
