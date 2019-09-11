#
# @lc app=leetcode id=20 lang=python
#
# [20] Valid Parentheses
#

#栈，字典应用

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack =[]
        paren_map ={'}':'{', ']':'[', ')':'(' }
        
        for item in s:
            if item not in paren_map:  #左括号
                stack.append(item)
            elif not stack or paren_map[item]!=stack.pop():   #遇见右括号
                return False
        
        return not stack  #最后如果stack为空，说明全部匹配完毕

