#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int Calculation(vector<int>& arr,int t,int mid){
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        ans = ans + ceil((double)arr[i]/mid);
    }
    if(ans > t) return 0;
    if(ans <= t) return 1;
}
int Find_Smallest_Divisor_Given_Threashold_Using_Binary_Search(vector<int>& arr,int t){
    // {1,2,3,4,5}, limit = 8
    // {8,4,2,3}, limit = 10
    if(arr.size() > t) return -1;
    int low = 1;
    int high = *max_element(arr.begin(),arr.end());
    while(low <= high){
        int mid = low + (high-low)/2;
        cout << "Tried low: " << low << endl;
        cout << "Tried mid: " << mid << endl;
        cout << "Tried high: " << high << endl;
        int result = Calculation(arr,t,mid);
        if(result == 1) high = mid-1;
        else if(result == 0) low = mid + 1;
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
    cout << "Threashold: ";
    cin >> t;
    cout << "Output: " << Find_Smallest_Divisor_Given_Threashold_Using_Binary_Search(arr,t);
}