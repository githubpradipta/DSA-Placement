#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Time Complexity = O(N)
Space Complexity = O(K) where K = size of the window or subarray size
*/

vector<int> firstNegative(vector<int> arr, int k){
    int size = arr.size();
    vector<int> ans;
    queue<int> q;
    int i=0,j=0;

    while(j<size){
        if(arr[j]<0) q.push(arr[j]); //pushing the negative numbers into the Queue
        if(j-i+1==k){
            if(!q.empty()) ans.push_back(q.front()); //inserting the 1st value of queue as the first negative number in that window 
            else ans.push_back(0); // if there are no negative number in the specific window then store 0 for that
            if(q.front()==arr[i]) q.pop(); // while sliding the window if the leftmost value is any negative the pop it from Queue
            i++;
        }
        j++;
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    vector<int> ans;
    int x;

    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    ans = firstNegative(arr,k);

    for(int x:ans){
        cout<<x<<" ";
    }
}