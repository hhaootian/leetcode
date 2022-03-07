class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1, right = n - 1;
        for (int i = nums1.size() - 1; i >= 0; i--) {
            int left_val = left >= 0 ? nums1[left] : INT_MIN;
            int right_val = right >= 0 ? nums2[right] : INT_MIN;

            if (left_val >= right_val) {
                nums1[i] = left_val;
                left--;
            }
            else {
                nums1[i] = right_val;
                right--;
            }
        }
    }
};