class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        nums = [str(n) for n in nums]
        nums_list = [[] for i in xrange(10)]
        index = []

        n = '*'
        for i, s in enumerate(nums):
            nums_list[int(s[0])].append(s)
            if s[0] != n:
                index.append(int(n))
        index.reverse()

        for i, idx in enumerate(index):
            if len(nums_list[idx][len(nums_list[idx])-1]) == 1:
                   if

        print nums_list
        print index

s = Solution()
print s.largestNumber([3, 30, 34, 5, 9])

