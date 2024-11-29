//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int n = s1.size()-1;
        int m = s2.size()-1;
        
        string result = "";
        
        int carry = 0;
        while(n >=0 or m >= 0){
            int sum = carry;
            
            if(n >= 0){
                sum += s1[n] - '0';
                n--;
            }
            if(m >= 0){
                sum += s2[m] - '0';
                m--;
            }
            
            carry = sum / 2;
            sum = sum % 2;
            result.push_back(static_cast<char>(sum + '0'));
        }

        if(carry){
            result.push_back(static_cast<char>(carry + '0'));    
        }
        reverse(result.begin(), result.end());
        int i=0;
        while(result[i] == '0') i++;
        result = result.substr(i);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends