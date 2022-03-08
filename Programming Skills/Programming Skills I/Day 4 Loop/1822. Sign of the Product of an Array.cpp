class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        int zero = 0;
        for (auto num : nums) {
            neg += num < 0 ? 1 : 0;
            zero += num == 0 ? 1 : 0;
        }
        return zero > 0 ? 0 : (neg % 2 == 0 ? 1 : -1);
    }
};