class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dict1 = {}
        dict2 = {}
        for item in nums1:
            if item in dict1.keys():
                dict1[item] += 1
            else:
                dict1[item] = 1
        for item in nums2:
            if item in dict2.keys():
                dict2[item] += 1
            else:
                dict2[item] = 1
        res = []
        for key, value in dict1.items():
            if key in dict2.keys():
                nums = min(value, dict2[key])
                while nums > 0:
                    res.append(key)
                    nums -= 1
        return res
