//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int evaluate(vector<string>& arr) {
        int n = arr.size();
        stack<int> st;
        
        for(int i=0; i<n; i++){
                
                if(arr[i] == "+"){
                    int num1 = st.top(); st.pop();
                    int num2 = st.top(); st.pop();
                    int result = num1 + num2;
                    st.push(result);
                }else if(arr[i] == "-"){
                    int num1 = st.top(); st.pop();
                    int num2 = st.top(); st.pop();
                    int result = num2 - num1;
                    st.push(result);
                }else if(arr[i] == "*"){
                    int num1 = st.top(); st.pop();
                    int num2 = st.top(); st.pop();
                    int result = num1* num2;
                    st.push(result);
                }else if(arr[i] == "/"){
                    int num1 = st.top(); st.pop();
                    int num2 = st.top(); st.pop();
                    int result = num2 / num1;
                    st.push(result);
                }else{
                    st.push(stoi(arr[i]));
                }
            
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends