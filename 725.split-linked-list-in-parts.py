#
# @lc app=leetcode id=725 lang=python
#
# [725] Split Linked List in Parts
#
# Category	Difficulty	Likes	Dislikes
# algorithms	Medium (49.72%)	427	88
# Tags
# Companies
# Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

# The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

# The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

# Return a List of ListNode's representing the linked list parts that are formed.

# Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
# Example 1:
# Input: 
# root = [1, 2, 3], k = 5
# Output: [[1],[2],[3],[],[]]
# Explanation:
# The input and each element of the output are ListNodes, not arrays.
# For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
# The first element output[0] has output[0].val = 1, output[0].next = null.
# The last element output[4] is null, but it's string representation as a ListNode is [].
# Example 2:
# Input: 
# root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
# Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
# Explanation:
# The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
# Note:

# The length of root will be in the range [0, 1000].
# Each value of a node in the input will be an integer in the range [0, 999].
# k will be an integer in the range [1, 50].


#######################################################################
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


##solution1
##思考：这道题题目很长，所以读懂题目是关键，读懂后就是很普通的链表平均拆分成子链表的问题
# 我们先对给定的链表求长度，然后除以k，会得到一个商和余数，商的数值代表平均分为k段之后每段有多少个节点，余数的数值代表前多少段需要多加一个节点，商和余数总共有以下几个情况：

# （1）商为0，余数为0。

# 此时说明链表长度就是0，也不需要做什么处理，直接返回一个空数组就行。

# （2）商为0，余数不为0。

# 说明此时的链表长度是小于k的，就如例1一样，商为0，余数为3。说明平均分为5段之后，平均每段有0个节点，然后前3段需要多加一个节点，那么正好就是：[1]、[2]、[3]、[]、[]。

# （3）商不为0，余数为0。

# 说明此时正好能够将链表平均分为k段，每段的长度就是商的数值了。

# （4）商不为0，余数不为0。

# Accepted
# 41/41 cases passed (20 ms)
# Your runtime beats 91.78 % of python submissions
# Your memory usage beats 28.57 % of python submissions (12.4 MB)

class Solution(object):
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        length = 0
        cur = root
        ans_list = [] #保存结果

        #获得链表长度
        while cur:
            length +=1
            cur = cur.next
        
        #然后除以k，会得到一个商和余数，商的数值代表平均分为k段之后每段有多少个节点，
        #余数的数值代表前多少段需要多加一个节点
        part_len = length // k
        part_remain = length % k #余数

        cur = root
        while cur:
            sub_len = part_len
            if part_remain > 0:
                sub_len += 1
                part_remain -= 1 
            k -= 1  #k计数，代表切分的段数计数

            sub_linked_list = root
            while cur and (sub_len-1)>0 :
                sub_len -= 1
                cur = cur.next

            root = cur.next #下一段的开头为新的root
            cur.next = None #子段添加None结束
            cur = root      
            ans_list.append(sub_linked_list)#添加子段到ans_list中

        #链表遍历完了，k却还没有为0，后面补空链表
        while k!=0 and cur==None:
            ans_list.append(None)
            k -=1
        return ans_list



# @lc code=end

