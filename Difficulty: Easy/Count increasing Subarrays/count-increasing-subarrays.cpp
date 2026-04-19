class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int cnt = 0, start = 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > arr[i-1]){
                cnt += (i - start);
            }else{
                start = i;
            }
        }
        return cnt;
    }
};
