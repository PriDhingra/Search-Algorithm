#include <iostream>

using namespace std;

int search(int* arr, int start, int end, int mid, int eleToSearch) {
    if(start > end) 
        return 0;
    
    if(arr[mid] == eleToSearch) {
        cout<<"\n"<<"Element found at position : "<<mid + 1;
        return 1;
    }
    else if(arr[mid] > eleToSearch) {
        end = mid - 1;
        mid = start + (end - start) / 2;
        search(arr, start, end, mid, eleToSearch);
    }    
    else if(arr[mid] < eleToSearch){
        start = mid + 1;
        mid = start + (end - start) / 2;
        search(arr, start, end, mid, eleToSearch);
    }
}

int main()
{
   int arr[] = {2, 4, 10, 12, 60, 422};
   int start = 0;
   int end = (sizeof(arr)/sizeof(arr[0])) - 1;
   int mid = start + (end - start) / 2;
   int eleToSearch = 1;
   
   for(int i = 0;i <= end;i++) {
       cout<<arr[i]<<" ";
   }
   
   int result =search(arr, start, end, mid, eleToSearch);
   
   if(result == 0) {
    cout<<"\n"<<"Element not found!";
   }
  
   return 0;
}
