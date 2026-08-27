class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left = 0
        zero_count = 0
        max_length = 0

        for right in range(len(nums)):

            # Add new element
            if nums[right] == 0:
                zero_count += 1

            # Too many zeros -> shrink window
            while zero_count > 1:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1

            # Window has at most one zero
            max_length = max(max_length, right - left + 1)

        return max_length - 1