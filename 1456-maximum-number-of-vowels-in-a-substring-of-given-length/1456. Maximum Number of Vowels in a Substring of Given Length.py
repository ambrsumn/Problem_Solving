class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = set("aeiou")

        # Count vowels in the first window
        count = sum(c in vowels for c in s[:k])
        max_count = count

        # Slide the window
        for i in range(k, len(s)):
            # Add the new character
            if s[i] in vowels:
                count += 1

            # Remove the old character
            if s[i - k] in vowels:
                count -= 1

            max_count = max(max_count, count)

        return max_count
        