class Solution {
public:
    string interpret(string command) {
        string ans;
        int idx = 0;
        while (idx < command.size()) {
            if (command[idx] == 'G') {
                ans += "G";
                idx++;
            }
            else {
                if (command[idx + 1] == ')') {
                    ans += "o";
                    idx += 2;
                }
                else {
                    ans += "al";
                    idx += 4;
                }
            }
        }
        return ans;
    }
};