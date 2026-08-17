#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int Adjacent_Cell_Checked(vector<vector<int>>& arr, int index, int mid){
    if(arr[index][mid] < arr[index][mid-1]) return 0;
    else if(arr[index][mid] < arr[index][mid+1]) return 2;
    else return 1;
}
pair<int,int> Find_Peak_Element_In_2D_Matrix(vector<vector<int>>& arr, int n, int m){
    int low = 0;
    int high = m-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int max_el = INT_MIN;
        int index = -1;
        for(int i=0;i<n;i++){
            if(arr[i][mid] > max_el){
                max_el = arr[i][mid];
                index = i;
            }
        }
        int result = Adjacent_Cell_Checked(arr,index,mid);
        if(result == 1) return {index,mid};
        else if(result == 0) high = mid-1;
        else low = mid+1;
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
    if(Find_Peak_Element_In_2D_Matrix(arr,n,m).first == -1){
        cout << "No Peak Available";// i dont think this is possible
    }
    cout << "Output: (" << Find_Peak_Element_In_2D_Matrix(arr,n,m).first << "," << Find_Peak_Element_In_2D_Matrix(arr,n,m).second << ")";
}