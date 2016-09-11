class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        #f[i][j] = [least, total]
        f = [ [None for n in l] for l in dungeon]
        f[0][0] = dungeon[0][0], dungeon[0][0]
        for i in xrange(1, len(dungeon[0])):
            left_total =  f[0][i-1][1] + dungeon[0][i]
            f[0][i] = min(f[0][i-1][0], left_total), left_total
                
        for i, row in enumerate(dungeon[1:], 1):
            for j, curr in enumerate(row):
                up_total =  f[i-1][j][1] + curr
                if j == 0:
                    f[i][j] = min(up_total, f[i-1][j][0]), up_total
                    continue
                
                left_total = f[i][j-1][1] + curr
                up_least = min(up_total, f[i-1][j][0])
                left_least = min(left_total, f[i][j-1][0])
                
                if up_least > left_least:
                    f[i][j] = up_least, up_total
                else:
                    f[i][j] = left_least, left_total

        for l in f:
            print l
        if -f[-1][-1][0] > 0:
            return 1-f[-1][-1][0]
        else:
            return 1

s = Solution()
print s.calculateMinimumHP([[-1,-1,-1], [1,-1,-2],[-2, -3, 5],[9, -1, 0]])
[[1,-3,3],
 [0,-2,0],
 [-3,-3,-3]]
