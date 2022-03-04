#include<iostream>

using namespace std;

long long int sqrtRoot(long long int number) {
    int start = 1;
    int end = number;
    int arr[number];
    long long int ans = -1;

    long long int mid = start + ((end - start) / 2);

    while(start <= end) {
        long long int square = mid * mid;
        if(square == number) 
            return mid;
        else if(square > number)
            end = mid -1;
        else    
        {
            start = mid + 1;
            ans = mid;
        }
        
        mid = start + ((end - start) / 2);
    }

    return ans;

}

double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;

    for(int i = 0;i < precision;i++) {
        factor = factor / 10;

        for(double j = ans;j*j<n; j=j+factor) {
            ans = j;
        }
    }

    return ans;
}

int main() {

    long long int number = 37;

    int tempSol = sqrtRoot(number);
    cout<<"Square root of "<<number<<" is "<<morePrecision(number, 3, tempSol);

    return 0;
}
