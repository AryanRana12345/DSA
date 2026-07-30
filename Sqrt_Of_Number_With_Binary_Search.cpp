#include <vector>
#include <iostream>
using namespace std;
int Sqrt_Of_Number_With_Binary_Search(int n){
    int low=1;
    int high = n;
    int ans = 1;
    while(low<=high){
        int mid = (low+high)/2;
        if((mid*mid) <= n){
            ans = mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cout << "Enter Number: ";
    cin >> n;
    cout << "Output: " << Sqrt_Of_Number_With_Binary_Search(n);
}