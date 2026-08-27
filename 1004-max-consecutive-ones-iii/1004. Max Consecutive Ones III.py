class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = 0
        zero_count = 0
        max_length = 0

        for right in range(len(nums)):

            # Add the new element
            if nums[right] == 0:
                zero_count += 1

            # Too many zeros → shrink window
            while zero_count > k:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1

            # Current window is valid
            max_length = max(max_length, right - left + 1)

        return max_length