class Solution {
public:
    double average(vector<int>& salary) {
        int high = 1000;
        int low = 1e6;
        int sum = 0;
        for (auto num : salary) {
            sum += num;
            high = max(high, num);
            low = min(low, num);
        }
        return (double) (sum - high - low) / (salary.size() - 2);
    }
};