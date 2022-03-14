class Solution {
public:
    bool check(string a, string b, int num []) {
        int size = min(a.size(), b.size());
        for (int i = 0; i < size; i++) {
            if (num[a[i] - 'a'] > num[b[i] - 'a'])
                return false;
            else if (num[a[i] - 'a'] < num[b[i] - 'a'])
                return true;
        }
        return a.size() > b.size() ? false : true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        int num [26];
        for (int i = 0; i < 26; i++) {
            int idx = order[i] - 'a';
            num[idx] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i];
            string b = words[i + 1];
            if (!check(a, b, num))
                return false;
        }
        return true;
    }
};