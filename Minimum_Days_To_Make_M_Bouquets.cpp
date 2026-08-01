#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int bouquet(vector<int>& arr,int n,int mid){
    int count = 0;
    int bouquet_counter = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] <= mid){
            count++;
        }
        else{
            bouquet_counter = bouquet_counter + count/n;
            count = 0;
        }
    }
    bouquet_counter = bouquet_counter + count/n;
    return bouquet_counter;
}
// {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, n = 3, mid = 10
int Minimum_Days_To_Make_M_Bouquets(int m, int n, vector<int>& arr){
    if((m*n) > arr.size()) return -1;
    int low = *min_element(arr.begin(),arr.end());
    int high = *max_element(arr.begin(),arr.end());
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(bouquet(arr,n,mid) >= m){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    int n1;
    cout << "Number of elements: ";
    cin >> n1;
    vector<int> arr;
    for(int i=0;i<n1;i++){
        int temp;
        cout << "Element " << i+1 << ": ";
        cin >> temp;
        arr.push_back(temp);
    }
    int m,n;
    cout << "Number of Bouquets: ";
    cin >> m;
    cout << "Number of Adjacent Flower required: ";
    cin >> n;
    cout << "Output: " << Minimum_Days_To_Make_M_Bouquets(m,n,arr);
}