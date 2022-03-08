class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int total1 = accumulate(nums1.begin(), nums1.end(), 0);
        int total2 = accumulate(nums2.begin(), nums2.end(), 0);

        if (total1 > total2) {
            swap(total1, total2);
            swap(nums1, nums2);
        }

        unordered_map<int, int> counter1, counter2;
        for (int num : nums1) counter1[num]++;
        for (int num : nums2) counter2[num]++;
        int min1 = *min_element(nums1.begin(), nums1.end());
        int max2 = *max_element(nums2.begin(), nums2.end());

        int result = 0;
        while (total1 < total2) {
            int prev_diff = total2 - total1;

            while (counter1[min1] == 0 and min1 < 7) min1++;
            while (counter2[max2] == 0 and max2 > 0) max2--;

            result++;

            if (6 - min1 > max2 - 1) {
                total1 += 6 - min1;
                counter1[min1]--;
                counter1[6]++;
            } else {
                total2 -= max2 - 1;
                counter2[max2]--;
                counter2[1]++;
            }

            if (prev_diff == total2 - total1) return -1;
        }
        return result;
    }
};
