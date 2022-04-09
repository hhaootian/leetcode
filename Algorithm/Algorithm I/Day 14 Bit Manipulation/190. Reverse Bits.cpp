class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int power = 31;
        while (n != 0) {
            ans += (n & 1) << power;
            n >>= 1;
            power -= 1;
        }
        return ans;
    }
};