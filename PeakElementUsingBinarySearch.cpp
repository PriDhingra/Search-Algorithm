#include <iostream>

using namespace std;

int peakEl(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    
    while(start < end) {
        if(arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    int arr[] = {0, 10, 11, 18, 16, 7, 3, 1, 0};
    
    cout<<peakEl(arr, 9);
   
    return 0;
}
