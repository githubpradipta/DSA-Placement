class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int size = s.length();
        map<int,int> mp;
        int maxLen = 0;

        while(j<size){
            if(mp.find(s[j])!= mp.end()){ // if the char encounter thet present already in the hash means it repeats.
                if(mp[s[j]] >= i) //checking if the char is in the window or not, if in window then only we update the i.
                    i = mp[s[j]]+1; 
                mp[s[j]] = j;  // updating the current index for the repeating char.
            }
             
            else mp[s[j]] = j; //entering the [char with index] into the hash if it occur first time.
            
            int k = j-i+1;  // calculate the size of the window / size of the subarray having no duplicates.
            maxLen = max(maxLen,k); // storing the max len of of the subarrays.
                
            j++;
          
        }
        return maxLen;
    }
};