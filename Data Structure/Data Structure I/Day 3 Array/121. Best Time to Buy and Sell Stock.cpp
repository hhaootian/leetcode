class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> stack;
        prices.push_back(-1);

        for (auto price : prices) {
            while (!stack.empty() && stack.back() > price) {
                ans = max(ans, stack.back() - stack.front());
                stack.pop_back();
            }
            stack.push_back(price);
        }

        return ans;
    }
};