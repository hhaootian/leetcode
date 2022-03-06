class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int ans = cur;
        
        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        
        return ans;
    }
};