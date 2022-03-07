class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int len1 = nums1.size();
        int len2 = nums2.size();
        int p1 = 0, p2 = 0;
        vector<int> ans;

        while (p1 < len1 && p2 < len2) {
            if (nums1[p1] < nums2[p2])
                p1++;
            else if (nums1[p1] > nums2[p2])
                p2++;
            else {
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }

        return ans;
    }
};