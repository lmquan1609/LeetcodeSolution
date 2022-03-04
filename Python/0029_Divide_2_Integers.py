class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        is_flip = -1 if (dividend < 0) ^ (divisor < 0) else 1
        dividend, divisor = map(abs, [dividend, divisor])
        
        result = 0
        while dividend >= divisor:
            curr_divisor, count = divisor, 1
            while dividend >= curr_divisor:
                dividend -= curr_divisor
                result += count
                count <<= 1
                curr_divisor <<= 1
        return min(2147483647, result * is_flip)
