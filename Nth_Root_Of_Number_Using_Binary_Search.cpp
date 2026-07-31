#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int Nth_Root_Of_Number_Using_Binary_Search(int m,int n){
    int low = 1;
    int high = m;
    while(low<=high){
        long long mid = low + (high-low)/2;
        if(round(pow(mid,n)) == m){
            return mid;
        }
        else if(pow(mid,n) < m){
            low=mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}
int main(){
    int m;
    int n;
    cout << "Enter Number: ";
    cin >> m;
    cout << "Which root you want to find? ";
    cin >> n; 
    cout << "Output: " << Nth_Root_Of_Number_Using_Binary_Search(m,n);
}