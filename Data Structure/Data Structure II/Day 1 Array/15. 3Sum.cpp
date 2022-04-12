class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() <= 2)
            return ans;

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int cur = nums[i] + nums[left] + nums[right];
                if (cur == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < nums.size() && nums[left] == nums[left - 1])
                        left++;
                    while (right >= 0 && nums[right] == nums[right + 1])
                        right--;
                }
                else if (cur > 0)
                    right--;
                else
                    left++;
            }
        }
        
        return ans;
    }
};