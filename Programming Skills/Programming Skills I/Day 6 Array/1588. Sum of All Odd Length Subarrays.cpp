class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 1; j < n + 1; j += 2) {
                ans += prefix[j] - prefix[i];
            }
        }
        return ans;
    }
};