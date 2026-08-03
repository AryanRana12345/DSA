#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int Calculation(vector<int>& arr,int t,int mid){
    int ans = 0;
    int completed_painter_work = 0;
    for(int i=0;i<arr.size();i++){
        if(ans + arr[i] > mid){
            completed_painter_work++;
            ans = 0;
            i--;
        }
        else{
            ans+=arr[i];
        }
    }
    completed_painter_work++;
    if(completed_painter_work > t) return 0;
    else return 1;
}
int Painters_Problem(vector<int>& arr,int t){
    if(t>arr.size()) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid = low + (high-low)/2;
        int result = Calculation(arr,t,mid);
        if(result == 1){
            high = mid-1;
        }
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
    cout << "Output: " << Painters_Problem(arr,t);
}