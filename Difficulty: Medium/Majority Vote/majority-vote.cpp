//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        int ele1=INT_MIN, ele2=INT_MIN;
        int cnt1=0, cnt2=0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(cnt1==0 and nums[i]!=ele2){
                cnt1=1;
                ele1=nums[i];
            }else if(cnt2==0 and nums[i]!=ele1){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else {cnt1--, cnt2--;}
        }
         
        int mini = int(n/3)+1;

        cnt1=0, cnt2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }

        vector<int>ans;
        if(cnt1>=mini) ans.push_back(ele1);
        if(cnt2>=mini) ans.push_back(ele2);
        
        if(ans.size() == 0) return {-1};

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends