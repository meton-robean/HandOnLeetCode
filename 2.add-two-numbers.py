#
# @lc app=leetcode id=2 lang=python
#
# [2] Add Two Numbers
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#思考:
#1 常规的链表遍历相加 
#2 注意l1,l2链表对应的数是倒序表示的，一开始没有注意到（以为顺序表示），所以先各自遍历了链表把数存到了list数据结构里了
#3 注意l1,l2可能不一样长度 ，注意carry进位

# ✔ Accepted  2019-0-15
#   ✔ 1563/1563 cases passed (56 ms)
#   ✔ Your runtime beats 63.35 % of python submissions
#   ✔ Your memory usage beats 51.47 % of python submissions (11.8 MB)


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """    
        dummy = ListNode(0)   #新的链表以待链接新的结果
        head = dummy
        tmp = 0
        carry = 0
        while l1 or l2:
            if l1:
                tmp+=l1.val
                l1 = l1.next
            if l2:
                tmp+=l2.val
                l2 = l2.next
            tmp+=carry
            #print(tmp)
            new_node = ListNode(tmp%10) 
            dummy_next_copy = dummy.next
            dummy.next = new_node
            new_node.next = dummy_next_copy
            dummy = dummy.next

            #reset
            carry = tmp//10
            tmp =0

        if carry:
            new_node = ListNode(carry)
            dummy_next_copy = dummy.next
            dummy.next = new_node
            new_node.next = dummy_next_copy
            dummy = dummy.next

        return head.next



############################

# local test 本地测试

#Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# def create_new_listnode(alist):
#     dummy = ListNode(float('inf'))
#     head = dummy
#     for i in range(len(alist)):
#         curnode = ListNode(alist[i])
#         dummy_next_copy = dummy.next
#         dummy.next = curnode
#         curnode.next = dummy_next_copy
#         dummy  =dummy.next
#     return head.next


## soulution 1
# def addTwoNumbers(l1, l2):
#     """
#     :type l1: ListNode
#     :type l2: ListNode
#     :rtype: ListNode
#     """    
#     dummy = ListNode(float('inf'))#新的链表以待链接新的结果
#     head = dummy
#     tmp = 0
#     carry = 0
#     while l1 or l2:
#         if l1:
#             tmp+=l1.val
#             l1 = l1.next
#         if l2:
#             tmp+=l2.val
#             l2 = l2.next
#         tmp+=carry
#         #print(tmp)
#         new_node = ListNode(tmp%10) 
#         dummy_next_copy = dummy.next
#         dummy.next = new_node
#         new_node.next = dummy_next_copy
#         dummy = dummy.next

#         #reset
#         carry = tmp//10
#         tmp =0

#     if carry:
#         new_node = ListNode(carry)
#         dummy_next_copy = dummy.next
#         dummy.next = new_node
#         new_node.next = dummy_next_copy
#         dummy = dummy.next

#     return head.next

# ##local test
# l1 = create_new_listnode([8,2,9]) 
# l2 = create_new_listnode([3,7])
# new_node = addTwoNumbers(l1, l2)
# while new_node:
#     print(new_node.val)
#     new_node = new_node.next

