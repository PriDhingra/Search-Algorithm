#include <iostream>

using namespace std;

int firstOcc(int arr[], int n, int key) {
    int start = 0;
    int end  = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    
    while(start <= end) {
        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        } else if(arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    
    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int start = 0;
    int end  = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    
    while(start <= end) {
        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        } else if(arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    
    return ans;
}

int main()
{
    int arr[12] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 35};
   
    cout<<"First Occurence of 3 is at "<<firstOcc(arr, 12, 3)<<" index"<<"\n";
    cout<<"Last Occurence of 3 is at "<<lastOcc(arr, 12, 3)<<" index";
   
   return 0;
}
