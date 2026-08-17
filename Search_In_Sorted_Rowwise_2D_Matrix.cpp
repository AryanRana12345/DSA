#include<iostream>
#include<vector>
using namespace std;
pair<int,int> Search_In_Sorted_Rowwise_2D_Matrix(vector<vector<int>>& arr, int n, int m, int k){
    int i = 0;
    int j = m-1;
    while(i<n && j>=0){
        if(arr[i][j] == k) return {i,j};
        else if(arr[i][j] < k) i+=1;
        else j-=1; 
    }
    return {-1,-1};
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
    if( Search_In_Sorted_Rowwise_2D_Matrix(arr,n,m,k).first == -1){
        cout << "Not found";
    }
    else{
        cout << "Output: (" << Search_In_Sorted_Rowwise_2D_Matrix(arr,n,m,k).first << "," << Search_In_Sorted_Rowwise_2D_Matrix(arr,n,m,k).second << ")";
    }
}