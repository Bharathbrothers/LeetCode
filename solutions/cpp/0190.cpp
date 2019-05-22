class Solution {
public:
    uint32_t reverseBits(uint32_t num) {
        unsigned int NO_OF_BITS = sizeof(num) * 8;
        unsigned int reverse_num = 0, temp;

        for (int i = 0; i < NO_OF_BITS; i++) {
            temp = (num & (1 << i));
            if (temp) reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
        }

        return reverse_num;
    }
};