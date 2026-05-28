class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and st.top() <= nums[i]){
                st.pop();
            }
            if(!st.empty() and st.top() > nums[i]){
                result[i] = st.top();
            }
            st.push(nums[i]);
        }
        
        return result;
    }
};