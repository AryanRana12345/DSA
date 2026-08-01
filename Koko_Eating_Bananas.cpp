#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int Koko_Eating_Bananas(int h,vector<int>& arr){
    // {7, 15, 6, 3}, h = 8
    // {25, 12, 8, 14, 19}, h = 5
    int low = 1;
    int high = *max_element(arr.begin(),arr.end());
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int hour = 0;
        for(int i=0;i<arr.size();i++){
            hour = hour + ceil(arr[i]/mid);
        }
        if(hour <= h){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}
int main(){
    int n;
    cout << "Number of elements: ";
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cout << "Element " << i+1 << ": ";
        cin >> temp;
        arr.push_back(temp);
    }
    int Target;
    cout << "Target Number: ";
    cin >> Target;
    cout << "Output: " << Koko_Eating_Bananas(Target,arr);
}