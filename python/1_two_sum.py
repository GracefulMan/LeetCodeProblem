class Solution:
    def twoSum(self, nums, target):
        mydict = {}
        for index, value in enumerate(nums):
            if value in mydict:
                return [mydict[value], index]
            mydict[target - value] = index
