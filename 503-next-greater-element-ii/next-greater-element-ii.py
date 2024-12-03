class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        res = []
        max = float('-inf')
        rotarry = [0]*n
        pos = 0
        for i in range(len(nums)):
            if max<nums[i]:
                pos = i
                max = nums[i]
        print(pos)
        dif = len(nums) -1 - pos
        for i in range(len(nums)):
            rotarry[(i+dif)%n] = nums[i]
        stack = [] 
        print(rotarry)
        for i in range(n-1,-1,-1):

            while(stack != [] and rotarry[i]>=stack[-1]):
                stack.pop(-1)
                continue
            if stack == []:
                res.append(-1)
            else:
                res.append(stack[-1])
            stack.append(rotarry[i])
        res = res[::-1]
        print(res)
        res1 = [0]*n
        for i in range(len(nums)):
            res1[(i-dif+n)%n] = res[i]
        return res1
        