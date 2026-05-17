class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();

        unordered_map<char, int> mp;
        int result = -1;
        for(int i=0, j=0; i<n; i++){
            mp[s[i]]++;
            
            while(mp.size() > k){
                mp[s[j]]--;
                if(mp[s[j]] == 0) mp.erase(s[j]);
                j++;
            }
            if(mp.size() == k) result = max(result, i-j+1);
        }
        return result;
    }
};