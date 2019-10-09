#
# @lc app=leetcode id=147 lang=python
#
# [147] Insertion Sort List
# Category	Difficulty	Likes	Dislikes
# algorithms	Medium (38.38%)	417	473
# Tags
# Companies
# Sort a linked list using insertion sort.


# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

###思考
#按照插入排序的思路进行
#dummy 是sorted list,, head是unsorted list
#如果从head取出的元素大于dummy最后一个，则直接插入到dummy最后去。否则重新重头遍历dummy，选择合适的位置插入。

###
# 22/22 cases passed (184 ms)
# Your runtime beats 69.25 % of python submissions
# Your memory usage beats 85.71 % of python submissions (15.3 MB)

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None

        #插入第一个元素到dummy list中
        dummy = ListNode(float('-inf'))
        dummy.next = head
        head = head.next
        dummy.next.next = None
        cur = dummy.next

        while head:
            #直接插到dummy最后面
            if cur.val <= head.val:
                cur.next = head
                head = head.next
                cur.next.next = None
                cur = cur.next

            #从头遍历dummy，选择合适位置插入
            else:
                start = dummy
                while start and start.next.val <=head.val:
                    start = start.next
                tmp = start.next
                head_next_copy = head.next
                start.next = head
                head.next = tmp
                head = head_next_copy
                
        return dummy.next




# @lc code=end

