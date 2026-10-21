class Solution(object):
    def twoSum(self, nums, target):
        elist = []
        for i in range(len(nums)):
            if len(elist) == 2:
                break
            if i in elist:
                continue
            for j in range(len(nums)):
                if i==j:
                    continue
                if j in elist:
                    continue
                if(nums[i]+nums[j] == target):
                    elist.append(i)
                    elist.append(j)
                    return elist