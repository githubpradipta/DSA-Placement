#include <iostream>
#include <vector>
using namespace std;


int maxSumSubarray(vector<int> arr, int k){
    int size = arr.size();
    int i=0,j=0;
    int sum = 0,maxSum = 0;

    while(j<size){
        sum+=arr[j]; //adding new element in window
        if(j-i+1<k) j++;
        else{
            maxSum = max(maxSum,sum);
            sum -= arr[i];   //removing leftmost element from window
            i++;
            j++;
        }
    }
    return maxSum;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int x;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    cout<<maxSumSubarray(arr,k);
}