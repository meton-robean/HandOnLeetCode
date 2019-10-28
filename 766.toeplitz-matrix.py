#
# @lc app=leetcode id=766 lang=python
#
# [766] Toeplitz Matrix
# Category	Difficulty	Likes	Dislikes
# algorithms	Easy (62.45%)	719	68
# Tags
# Companies
# A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

# Now given an M x N matrix, return True if and only if the matrix is Toeplitz.

# Example 1:

# Input:
# matrix = [
#   [1,2,3,4],
#   [5,1,2,3],
#   [9,5,1,2]
# ]
# Output: True
# Explanation:
# In the above grid, the diagonals are:
# "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
# In each diagonal all elements are the same, so the answer is True.

##############################################################################
##solution 1
# 可以按正常顺序来遍历数组，对于每个遍历到的数字，都跟其右下方的数字对比，
# 如果不相同，直接返回false即可。为了防止越界，我们不遍历最后一行和最后
# 一列，遍历完成后，返回true

# Accepted
# 482/482 cases passed (64 ms)
# Your runtime beats 93.91 % of python submissions
# Your memory usage beats 17.65 % of python submissions (11.9 MB)

# @lc code=start
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        for i in range(len(matrix)-1):
            for j in range(len( matrix[0]) -1 ):
                if matrix[i][j]!= matrix[i+1][j+1]:
                    return False
        return True



# @lc code=end

