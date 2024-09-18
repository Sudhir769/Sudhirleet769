//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n = x.length();
        stack<char> st;
        
        for(int i=0; i<n; i++){
            char ch = x[i];
            if(ch == '{' or ch == '(' or ch == '['){
                st.push(x[i]);
            }else{
                if(st.empty()) return false;
                
                char top = st.top();
                if((top == '(' and ch == ')') or 
                    (top == '{' and ch == '}' or 
                        (top == '[' and ch == ']'))){
                            st.pop();
                        }else{
                            return false;
                        }
            }
        }
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends