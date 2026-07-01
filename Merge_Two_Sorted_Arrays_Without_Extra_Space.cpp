#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Merge_Two_Sorted_Arrays_Without_Extra_Space(vector<int> arr1,vector<int> arr2, int m, int n){
    int i = m-1; // i=3
    int j = n-1; // j=2
    int k = m+n-1;//k=6
    int count = 0;
    //[0, 2, 7, 8, 0, 0, 0]
    //[-7, -3, -1]
    while(count < m+n-1){
        while(i>=0 && j>=0){
            if(arr1[i] > arr2[j]){
            arr1[k] = arr1[i];
            i--;
            k--;
            }
            else{
                arr1[k] = arr2[j];
                j--;
                k--;
            }
        }
        while(i>=0){
            arr1[k] = arr1[i];
            i--;
            k--;
        }
        while(j>=0){
            arr1[k] = arr2[j];
            j--;
            k--;
        }
        count++;
    }
    return arr1;
}
int main(){
    vector<int> arr1 = {-5, -2, 4, 5, 0, 0, 0};
    int m = 4;
    int n = 3;
    vector<int> arr2 = {-3, 1, 8};
    vector<int> Output = Merge_Two_Sorted_Arrays_Without_Extra_Space(arr1,arr2,m,n);
    for(int val : Output){
        cout << val << " ";
    }
}