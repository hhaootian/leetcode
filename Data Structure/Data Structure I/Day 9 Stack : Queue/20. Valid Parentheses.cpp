class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        for (auto c : s) {
            if (mp.count(c))
                st.push(c);
            else {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if (c != mp[top])
                    return false;
            }
        }
        return st.empty() ? true : false;
    }
};