//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        int i=0;
        int sign = 1;
        long long result = 0;
        
        while(s[i] == ' ' or s[i] == '0'){
            i++;
        }
        
        if(s[i] == '+' or s[i] == '-'){
            sign = (s[i] == '-') ? -1:1;
            i++;
        }
        
        while(s[i] >= '0' and s[i] <= '9'){
            result = result * 10 + (s[i] - '0');
            
            if(result > INT_MAX){
                return (sign == 1) ? INT_MAX:INT_MIN;
            }
            i++;
        }
        
        return sign * (int)result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends