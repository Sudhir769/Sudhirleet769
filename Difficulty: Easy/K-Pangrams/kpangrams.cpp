//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        int n = str.length();
        
        if(n < 26){
            return false;
        }
        
        vector<int> hash(26, 0);
        for(int i=0; i<n; i++){
            if(str[i] != ' ') hash[str[i] - 'a']++;
        }
        
        int sum = 0, zero = 0;
        for(int i=0; i<26; i++){
            if(hash[i] > 0){
                sum += hash[i];
            }else{
                zero++;
            }
        }
        if(sum < 26) return false;
        if(zero > k){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends