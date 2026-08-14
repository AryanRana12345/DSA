#include<iostream>
#include<vector>
using namespace std;
bool Search_In_Sorted_2D_Matrix(vector<vector<int>>& arr, int n, int m, int k){
    if(k > arr[n-1][m-1] || k < arr[0][0]) return false;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid][0] < k) low = mid+1;
        else if(arr[mid][1] > k) high = mid-1;
        else return true;
    }
    int low2 = 1;
    int high2 = m-1;
    while(low2<=high2){
        int mid = low2 + (high2-low2)/2;
        if(arr[high][mid] < k) low2 = mid+1;
        else if(arr[high][mid] > k) high2 = mid-1;
        else return true;
    }
    return false;
}
int main(){
    int n,m;
    cout << "Number of Rows: ";
    cin >> n;
    cout << "Number of Columns: ";
    cin >> m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int temp;
            cout << j << "th Element of " << i << "th row: ";
            cin >> temp;
            arr[i-1][j-1] = temp;
        }
    }
    int k;
    cout << "K: ";
    cin >> k;
    if(Search_In_Sorted_2D_Matrix(arr,n,m,k)) cout << "True";
    else cout << "False"; 
}