#include<iostream>

using namespace std;

int peakElement(int *arr, int start, int end) {
    int mid = start + ((end - start) / 2);
    while(start < end) {
        if(arr[mid] < arr[mid+1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = start + ((end - start) / 2);
    }
    return start;
}

int main() {
    int arr[] = {3, 4, 5, 1};

    cout<<"Peak Element "<<arr[peakElement(arr, 0, 3)];

    return 0;
}
