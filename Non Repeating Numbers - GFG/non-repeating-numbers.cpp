//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n= nums.size();
        set<int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                mp.erase(nums[i]);
            }else{
                mp.insert(nums[i]);
            }
        }
        vector<int> ans;
        
        ans.push_back(*(mp.begin()));
        mp.erase(mp.begin());
        ans.push_back(*(mp.begin()));
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends