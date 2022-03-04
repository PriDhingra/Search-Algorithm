#include<iostream>

using namespace std;

int pivotEl(int *arr, int start, int end) {
    if(arr[start] < arr[end]) 
        return -1;

    int mid = start + ((end - start) / 2);

    while(start <= end) {
        if(arr[mid] > arr[mid+1])
            return mid + 1;
        else if(arr[mid] >= arr[start]) {
            start = mid + 1;
        } else {
            end = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }

    return 0;
}

int binarySearch(int *arr, int start, int end, int elementToSearch) {
    int mid = start + (end - start) / 2;

    while(start <= end) {
        if(arr[mid] == elementToSearch) 
            return mid;
        else if(arr[mid] < elementToSearch) 
            start = mid + 1;
        else    
            end = mid - 1;

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main() {
    int arr[] = {10, 13, 15, 16, 5, 6, 7};
    int elementToSearch = 16;
    int start = 0;
    int end = 6;

    int pivot = pivotEl(arr, start, end);

    if(pivot == -1)
        cout<<"Array is not rotated sorted";
    else if(arr[pivot] <= elementToSearch && elementToSearch <= arr[end]) 
        cout<<"Element found at position "<<binarySearch(arr, pivot, end, elementToSearch);
    else 
        cout<<"Element found at position "<<binarySearch(arr, start, pivot - 1, elementToSearch);

    return 0;
}
