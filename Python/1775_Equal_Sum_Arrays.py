class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        total1, total2 = map(sum, (nums1, nums2))
        if total1 > total2:
            total1, total2 = total2, total1
            nums1, nums2 = nums2, nums1

        counter1, counter2 = map(Counter, (nums1, nums2))
        max1, min1 = max(nums1), min(nums1)
        max2, min2 = max(nums2), min(nums2)

        result = 0
        while total1 < total2:
            prev_diff = total2 - total1
            while counter1[min1] == 0 and min1 < 7:
                min1 += 1

            while counter2[max2] == 0 and max2 > 0:
                max2 -= 1

            delta = total2 - total1
            result += 1
            if 6 - min1 > max2 - 1:
                total1 += 6 - min1
                counter1[min1] -= 1
                counter1[6] += 1
            else:
                total2 -= (max2 - 1)
                counter2[max2] -= 1
                counter2[1] += 1

            if prev_diff == total2 - total1:
                return -1

        return result
