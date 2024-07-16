class Solution {
    int smaller(map<char,int> mp){
        int small = INT_MAX;
        for(auto x:mp){
            small = min(small,x.second);
        }
        return small;
    }
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int size = s.size();
        int cnt=0;

        for(int i=0;i<size;i++){
            mp[s[i]] = i;

            if(mp.find('a')!=mp.end() && mp.find('b')!=mp.end() && mp.find('c')!=mp.end()){
                cnt += smaller(mp)+1;
            }
        }
        return cnt;

    }
};