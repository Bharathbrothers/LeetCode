class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            nums1.swap(nums2);
            swap(m, n);
        }

        int minVal = 0;
        int maxVal = m;
        int halfLen = (m + n + 1) / 2;

        while (minVal <= maxVal) {
            int i = (minVal + maxVal) >> 1;
            int j = halfLen - i;
            if (i < maxVal && nums2[j - 1] > nums1[i])
                minVal = i + 1;
            else if (i > minVal && nums1[i - 1] > nums2[j])
                maxVal = i - 1;
            else {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = nums2[j - 1];
                else if (j == 0)
                    maxLeft = nums1[i - 1];
                else
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                if ((m + n) & 1) return maxLeft;

                int minRight = 0;
                if (i == m)
                    minRight = nums2[j];
                else if (j == n)
                    minRight = nums1[i];
                else
                    minRight = min(nums2[j], nums1[i]);

                return (maxLeft + minRight) / 2.0;
            }
        }

        return 0.0;
    }
};