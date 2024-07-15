class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int size = nums.size();
        int cntZero = 0,maxLen = 0;

        while(j<size){
            if(nums[j]==0){
                cntZero++;  //if encountering zero the count the zeros.
            } 

            if(cntZero>k){
                if(nums[i]==0) cntZero--; // if zeros > k then shrink the window till the zeros <= k.
                i++;
            }
            int len = j-i+1; // calculate the size of window.
            maxLen = max(maxLen,len);  // storing the max size of window
            j++; // expandin window.
        }
        
        return maxLen;
    }
};