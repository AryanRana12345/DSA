#include<iostream>
#include<vector>
using namespace std;
int Finding_Rows_With_Maximum_1s(vector<vector<int>> arr, int n, int m){
    int cnt = 0;
    int row = -1;
    for(int i=0;i<n;i++){
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[i][mid] == 0) low = mid+1;
            else high = mid-1;
        }
        if(m-low > cnt){
            cnt = m-low;
            row = i;
        }
    }
    return row;
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
            arr[i-1][j] = temp;
        }
    }
    cout << "Output: " << Finding_Rows_With_Maximum_1s(arr,n,m) + 1; 
}