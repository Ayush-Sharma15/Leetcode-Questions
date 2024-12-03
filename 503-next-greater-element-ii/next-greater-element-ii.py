class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        maxele = max(nums)
        numlen = len(nums)
        for i in range(numlen):
            j = i+1
            if nums[i] == maxele:
                res.append(-1)
            else:
                while True:
                    if nums[j%numlen] > nums[i]:
                        res.append(nums[j%numlen])
                        break
                    j+=1
        return res