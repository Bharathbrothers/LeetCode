class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        isAllNine = True

        for i in range(len(digits) - 1, -1, -1):
            if digits[i] != 9:
                digits[i] += 1
                isAllNine = False
                break
            else:
                digits[i] = 0

        if isAllNine:
            digits = [1] + digits

        return digits
