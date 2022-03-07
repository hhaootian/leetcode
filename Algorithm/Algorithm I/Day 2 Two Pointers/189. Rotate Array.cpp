class Solution {
public:
    void helper(vector<int>& nums, int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
        reverse(nums.begin(), nums.end());
        helper(nums, 0, k - 1);
        helper(nums, k, nums.size() - 1);

    }
};