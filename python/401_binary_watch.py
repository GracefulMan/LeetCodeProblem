class Solution:
    def get_time_list(self, array, nums, hour=True):
        if nums == 0 : return [0]
        max_num = 12 if hour else 59
        import itertools
        tmp_list = list(itertools.combinations(array, nums))
        res = []
        for i in range(len(tmp_list)):
            tmp_sum = 0
            for j in range(nums):
                tmp_sum += tmp_list[i][j]
            if tmp_sum < max_num:
                res.append(tmp_sum)
        return res


    def readBinaryWatch(self, num):
        if num == 0: return ["0:00"]
        hour = [1, 2, 4, 8]
        mins = [1, 2, 4, 8, 16, 32]
        hour_list = []
        min_list = []
        for i in range(num + 1):
            print(i)
            hour_list.append(self.get_time_list(hour, i))
            min_list.append(self.get_time_list(mins, num - i, False))
        res = []
        for k in range(len(hour_list)):
            tmp_1 = hour_list[k]
            tmp_2 = min_list[k]
            for i in range(len(tmp_1)):
                for j in range(len(tmp_2)):
                    if tmp_2[j] < 10:
                        res.append("{}:{}".format(tmp_1[i], "0" + str(tmp_2[j])))
                    else:
                        res.append("{}:{}".format(tmp_1[i], tmp_2[j]))
        return res


res = Solution()
print(res.readBinaryWatch(1))


