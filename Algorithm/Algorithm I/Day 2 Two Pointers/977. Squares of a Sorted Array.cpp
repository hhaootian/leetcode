class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int left_square = nums[left] * nums[left];
            int right_square = nums[right] * nums[right];

            if (left_square >= right_square) {
                ans.push_back(left_square);
                left++;
            }
            else {
                ans.push_back(right_square);
                right--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};