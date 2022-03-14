class Solution {
public:
    string freqAlphabets(string s) {
        string ns = "";
        for (int i = s.size() - 1; i >= 0; ) {
            if (s[i] == '#') {
                string nw = ""; 
                nw += s[i - 2];
                nw += s[i - 1];
                int n = stoi(nw);
                ns = (char)('a' + n - 1) + ns; 
                i = i - 3;
            } 
            else {
                int n = s[i] - '1';
                ns = (char)('a' + n) + ns; 
                i--;
            }
        }
        return ns;
    }
};