//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        int n = arr.size();
        vector<double> ans(n, 0);
        
        priority_queue<int> leftMax;
        priority_queue<int, vector<int>, greater<int>> rightMin;
        
        for(int i=0; i<n; i++){
            leftMax.push(arr[i]);
            
            int top = leftMax.top();
            leftMax.pop();
            
            rightMin.push(top);
            
            if(rightMin.size() > leftMax.size()){
                int el = rightMin.top();
                rightMin.pop();
                
                leftMax.push(el);
            }
            
            double median = 0.0;
            if(leftMax.size() != rightMin.size()){
                median = leftMax.top();
            }else{
                median = double(leftMax.top() + rightMin.top())/2;
            }
            ans[i] = median;
        }
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
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends