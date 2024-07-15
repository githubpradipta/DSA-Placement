class Solution {
    int helper(vector<int> nums,int goal){
        if(goal<0) return 0; // edge case for [goal < 0] there are no subArrays because the array is a binary array having only (0,1).

        int i=0,j=0;
        int sum = 0;
        int subArray = 0;

        while(j<nums.size()){
            sum+=nums[j];

            while(sum>goal){
                sum-=nums[i]; // Shrinking the window.
                i++;
            }
            if(sum <= goal){
                subArray+=j-i+1; // For calculating the number of subArrays for [sum <= goal] / It is actually the length of the window.
            } 
            j++; //Expanging the window.
            
        }
        return subArray;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1); //geting the number of subArrays for [sum == goal].
    }
};