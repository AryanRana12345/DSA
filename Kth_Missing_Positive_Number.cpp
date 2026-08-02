#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int Calculation(vector<int>& arr,int& t,int mid,int low){
    int temp = t + mid - low;
    if(temp >= arr[mid]){
        t = temp + 1;
        return 1;
    }
    else{
        return 0;
    }
}
// {2,3,4,7,11}  t = 5
// {4,7,9,10}, t = 4
int Kth_Missing_Positive_Number(vector<int>& arr,int t){
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int result = Calculation(arr,t,mid,low);
        if(result == 1) low = mid+1;
        else high = mid-1;
    }
    return t;
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
    cout << "Output: " << Kth_Missing_Positive_Number(arr,t);
}