class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int total = 0,sum=0,ans=0;
        int size = arr.size();
    
        for(int x:arr){
            total += x;
        }

        if(k==size) return total;

        int i=0,j=0;
      
        while(j<size){
            sum += arr[j];
            if((j-i+1)==(size-k)){
                ans = max(ans,total-sum);
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};