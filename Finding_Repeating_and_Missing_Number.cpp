#include<iostream>
#include<vector>
using namespace std;
vector<int> Finding_Repeating_and_Missing_Number(int n,vector<int>& arr){
    int ElementSum = 0;
    int ElementSquareSum = 0;
    for(int i=0;i<n;i++){
        ElementSum = ElementSum + arr[i];
        ElementSquareSum = ElementSquareSum + (arr[i]*arr[i]);
    }
    int PerfectSum = (n*(n+1))/2;
    int PerfectSquareSum = (n*(n+1)*(2*n+1))/6;
    int DiffSquare = PerfectSquareSum - ElementSquareSum;
    int DiffSum = PerfectSum - ElementSum;
    int Sum_A_B = DiffSquare/DiffSum;
    int Missing = (Sum_A_B + DiffSum)/2;
    int repeating = Sum_A_B - Missing;
    return {repeating,Missing};
}
int main(){
    int NumberOfElements;
    cout << "Number of elements: ";
    cin >> NumberOfElements;
    vector<int> arr;
    for(int i=0;i<NumberOfElements;i++){
        cout << "Element " << i+1 << ": ";
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int> Output = Finding_Repeating_and_Missing_Number(NumberOfElements,arr);
    cout << "Repeating Number: " << Output[0] << endl;
    cout << "Missing Number: " << Output[1] << endl;
}