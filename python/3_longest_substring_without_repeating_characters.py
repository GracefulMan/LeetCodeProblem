class Solution:
    def lengthOfLongestSubstring(self, s):
        maxLength = 0
        i = 0
        while i < len(s):
            k = i
            while k < len(s) - 1 and s[k + 1] not in s[i: k + 1]:
                k += 1
            maxLength = max(k - i + 1,maxLength)
            i  +=  1
        return maxLength

my_string = "pwwkew"
test = Solution()
print(test.lengthOfLongestSubstring(my_string))

