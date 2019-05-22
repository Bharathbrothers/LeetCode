class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)

        if m > n:
            nums1, nums2 = nums2, nums1
            m, n = n, m

        minVal = 0
        maxVal = m
        halfLen = (m + n + 1) // 2

        while minVal <= maxVal:
            i = (minVal + maxVal) >> 1
            j = halfLen - i
            if i < maxVal and nums2[j - 1] > nums1[i]:
                minVal = i + 1
            elif i > minVal and nums1[i - 1] > nums2[j]:
                maxVal = i - 1
            else:
                if i == 0:
                    maxLeft = nums2[j - 1]
                elif j == 0:
                    maxLeft = nums1[i - 1]
                else:
                    maxLeft = max(nums1[i - 1], nums2[j - 1])
                if (m + n) & 1:
                    return maxLeft

                if i == m:
                    minRight = nums2[j]
                elif j == n:
                    minRight = nums1[i]
                else:
                    minRight = min(nums1[i], nums2[j])

                return (maxLeft + minRight) / 2.0

        return 0.0
