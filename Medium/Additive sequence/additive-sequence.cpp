//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  
    string findSum(string a, string b){
        string ans = "";
        int i=a.length()-1, j=b.length()-1, carry = 0;
        
        while(i>=0 and j>=0){
            int sum = (a[i]-'0') + (b[j]-'0') + carry;
            ans += (sum % 10 + '0');
            carry = sum / 10;
            i--, j--;
        }
        while(i>=0){
            int sum = (a[i]-'0') + carry;
            ans += (sum % 10 + '0');
            carry = sum / 10;
            i--;
        }
        while(j>=0){
            int sum = (b[j]-'0') + carry;
            ans += (sum % 10 + '0');
            carry = sum / 10;
            j--;
        }
        if(carry){
            ans += carry + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
  
    bool solve(string a, string b, string c){
        string sum = findSum(a, b);
        int i=0, j=0;
        
        while(i < c.length() and j < sum.length()){
            if(c[i] != sum[j]) return false;
            i++, j++;
        }
        if(j != sum.length()) return false;
        if(i == c.length()) return true;
        c = c.substr(i);
        return solve(b, sum, c);
    }
    
    bool isAdditiveSequence(string s) {
        int n = s.length();
        
        for(int i=0; i<n/2; i++){
            for(int j=i+1; j<n-1; j++){
                string a = s.substr(0, i+1);
                string b = s.substr(i+1, j-i);
                string c = s.substr(j+1);
                if(solve(a,b, c)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends