class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> all;
        for (int num : nums) {
            if (all.count(num))
                return true;
            all.insert(num);
        }
        
        return false;
    }
};