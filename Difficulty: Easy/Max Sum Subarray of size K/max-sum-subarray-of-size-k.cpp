class Solution {
  public:
    int maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int currSum = 0, maxSum = 0;
        int size = k;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            size--;
            if(size == 0){
                maxSum = max(maxSum, currSum);
                currSum -= nums[i-k+1];
                size++;
            }
        }
        return maxSum;
        
    }
};