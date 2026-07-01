#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> Merge_Ovarlapping_Subintervals(vector<vector<int>> arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> output;
    int start = arr[0][0];
    int end = arr[0][1];
    //[[1,3],[2,6],[8,10],[15,18]]
    for(int i = 0; i < arr.size()-1; i++){
        if(end >= arr[i+1][0]){
            end = max(end,arr[i+1][1]);
        }else{
            output.push_back({start,end});
            start = arr[i+1][0];
            end = arr[i+1][1];
        }
    }
    output.push_back({start,end});
    return output;
}
int main(){
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> output = Merge_Ovarlapping_Subintervals(input);
    cout << "[";
    for(vector<int> interval : output){
        cout << "[";
        for(int i = 0;i == 0;i++){
            cout << interval[i] << "," << interval[i+1];
        }
        cout << "]";
    }
    cout << "]"; 
}