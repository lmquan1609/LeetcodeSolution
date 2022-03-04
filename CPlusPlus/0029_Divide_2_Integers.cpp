class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int needToFlip = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long dvd = labs(dividend);
        long div = labs(divisor);
        long result = 0;

        while (dvd >= div) {
            long currDivisor = div;
            long count = 1;
            while (dvd >= currDivisor) {
                result += count;
                dvd -= currDivisor;
                count <<= 1;
                currDivisor <<= 1;
            }
        }
        return result * needToFlip;
    }
};
