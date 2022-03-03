#include<iostream>

using namespace std;

int firstOccurence(int *arr, int start, int end, int key) {
    int mid = start + ((end - start) / 2);
    int first = -1;

    while(start <= end) {
        if(arr[mid] == key) {
            first = mid;
            end = mid - 1;
        } 

        if(arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        mid = start + ((end - start) / 2);
    }

    return first;
}

int lastOccurence(int *arr, int start, int end, int key) {
    int mid = start + ((end - start) / 2);
    int last = -1;

    while(start <= end) {
        if(arr[mid] == key) {
            last = mid;
            start = mid + 1;
        } 

        if(arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        mid = start + ((end - start) / 2);
    }

    return last;
}

int main() {
    int arr[] = {5, 5, 5, 5, 6, 6, 7, 7};

    int first = firstOccurence(arr, 0, 7, 5);
    int last = lastOccurence(arr, 0, 7, 5);

    cout << "First Occurence of 5 is "<<first<< endl;
    cout << "Last Occurence of 5 is "<<last;
    
    return 0;
}
