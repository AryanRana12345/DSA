#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int Calculation(vector<int>& arr,int t,int mid){
    int days = 0;
    int point = 0;
    while(point < arr.size()){
        int temp = mid;
        while(temp>=arr[point]){
            temp = temp - arr[point];
            point++;
        }
        days++;
    }
    if(days <= t) return 1;
    else return 0;
}
int Least_Capacity_To_Ship_Packages_In_D_Days(vector<int>& arr,int t){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid = low + (high-low)/2;
        int result = Calculation(arr,t,mid);
        if(result == 1) high = mid-1;
        else low = mid+1;
    }
    return low;
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
    cout << "Output: " << Least_Capacity_To_Ship_Packages_In_D_Days(arr,t);
}