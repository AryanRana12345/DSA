#include <vector>
#include <iostream>
using namespace std;
int Merge(int low,int mid,int high,vector<int>& arr){
    int count = 0;
    int left = low;
    int right = mid+1;
    int sleft = low;
    int sright = mid+1;
    int fcount = 0;
    bool ongoing = false;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(arr[left] > 2LL * arr[right]){
            count++;
            right++;
            ongoing = true;
        }
        else{
            fcount += count;
            left++;
            ongoing = false;
        }
    }
    while(sleft <= mid && sright <= high){
        if(arr[sleft] <= arr[sright]){
            temp.push_back(arr[sleft]);
            sleft++;
        }
        else{
            temp.push_back(arr[sright]);
            sright++;
        }
    }
    while(sleft <= mid){
        temp.push_back(arr[sleft]);
        sleft++;
    }
    while(sright <= high){
        temp.push_back(arr[sright]);
        sright++;
    }
    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    if(ongoing == true){
        fcount += count;
    }
    return fcount;
}
int MergeSort(int low,int high,vector<int>& arr){
    int count = 0;
    if(low >= high) return count;
    int mid = (low+high)/2;
    count = MergeSort(low,mid,arr);
    count += MergeSort(mid+1,high,arr);
    count += Merge(low,mid,high,arr);
    return count;
}
int Count_Reverse_Pairs(int n,vector<int>& arr){
    int low = 0;
    int high = n-1;
    return MergeSort(low,high,arr);
}
int main(){
    int n;
    cout << "Number of elements in array: ";
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cout << "Element " << (i+1) << ": ";
        cin >> temp;
        arr.push_back(temp);
    }
    cout << "Output: " << Count_Reverse_Pairs(n,arr);
}