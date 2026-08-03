// Allocate_Minimum_Number_Of_Pages
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int Calculation(vector<int>& arr,int t,int mid){
    int ans = 0;
    int book_allocated = 0;
    for(int i=0;i<arr.size();i++){
        if(ans+arr[i] > mid){
            book_allocated++;
            ans = 0;
            i--;
        }
        else{
            ans = ans + arr[i];
        }
    }
    book_allocated++;
    if(book_allocated == t) return 1;
    else if(book_allocated > t) return 2;
    else return 0;
}
int Allocate_Minimum_Number_Of_Pages(vector<int>& arr,int t){
    if(t>arr.size()) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int result = Calculation(arr,t,mid);
        if(result == 1){
            ans = mid;
            high = mid-1;
        }
        else if(result == 2) low = mid+1;
        else high = mid-1;
    }
    return ans;
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        int temp;
        cout << "Enter " << i << " element: ";
        cin >> temp;
        arr.push_back(temp);
    }
    int t;
    cout << "Target: ";
    cin >> t;
    cout << "Output: " << Allocate_Minimum_Number_Of_Pages(arr,t);
}