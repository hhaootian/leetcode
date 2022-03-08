class Solution {
public:

    int helper(int n) {
        int ans = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            ans += digit * digit;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            int squared = helper(n);
            if (seen.count(squared))
                return false;
            n = squared;
            seen.insert(n);
        }
        return true;
    }
};