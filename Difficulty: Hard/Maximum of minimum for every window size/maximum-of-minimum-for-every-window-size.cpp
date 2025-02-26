//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>preSmall(n);
        vector<int>nextSmall(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                preSmall[i] = -1;
            }
            else{
                preSmall[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nextSmall[i] = n;
            }
            else{
                nextSmall[i] = st.top();
            }
            st.push(i);
        }

        vector<pair<int,int>>maxEle;
        for(int i=0;i<n;i++){
            maxEle.push_back({arr[i],nextSmall[i]-preSmall[i]-1});
        }
        
        sort(maxEle.begin(),maxEle.end(),greater<pair<int,int>>());

        vector<int>ans(n);
        int start = 0;
        for(int i=0;i<n;i++){
            if(maxEle[i].second<=start){
                continue;
            }
            for(int j=start;j<maxEle[i].second;j++){
                ans[j] = maxEle[i].first;
            }
            start = maxEle[i].second;
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends