class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (i < s.size()) {
            int left = i;
            while (i < s.size() && s[i] != ' ')
                i++;
            int right = i - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            while (i < s.size() && s[i] == ' ')
                i++;
        }

        return s;
        
    }
};