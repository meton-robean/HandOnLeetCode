#
# @lc app=leetcode id=138 lang=python
#
# [138] Copy List with Random Pointer
#
# Category	Difficulty	Likes	Dislikes	Discuss
# algorithms	Medium (28.81%)	1904	499	–
# Tags
# Companies
# A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
# Return a deep copy of the list.



### 思考：
# 1. 在原链表的每个节点后面拷贝出一个新的节点。
# 2. 依次给新的节点的随机指针赋值，而且这个赋值非常容易 cur->next->random = cur->random->next。
# 3. 断开链表可得到深度拷贝后的新链表。

# 举个例子来说吧，比如原链表是 1(2) -> 2(3) -> 3(1)，括号中是其 random 指针指向的结点，那么这个解法是首先比遍历一遍原链表，在每个结点后拷贝一个同样的结点，但是拷贝结点的 random 指针仍为空，则原链表变为 1(2) -> 1(null) -> 2(3) -> 2(null) -> 3(1) -> 3(null)。然后第二次遍历，是将拷贝结点的 random 指针赋上正确的值，则原链表变为 1(2) -> 1(2) -> 2(3) -> 2(3) -> 3(1) -> 3(1)，注意赋值语句为：
# cur->next->random = cur->random->next;

# 这里的 cur 是原链表中结点，cur->next 则为拷贝链表的结点，cur->next->random 则为拷贝链表的 random 指针。cur->random 为原链表结点的 random 指针指向的结点，因为其指向的还是原链表的结点，所以我们要再加个 next，才能指向拷贝链表的结点。最后再遍历一次，就是要把原链表和拷贝链表断开即可

# @lc code=start

### Accepted
# 9/9 cases passed (380 ms)
# Your runtime beats 94.02 % of python submissions
# Your memory usage beats 44.74 % of python submissions (14.7 MB)

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None

        #在原链表的每个节点后面拷贝出一个新的节点
        cur = head
        while cur:
            cur.next = Node(cur.val, cur.next, cur.random)
            cur = cur.next.next
        
        #依次给新的节点的随机指针赋值，而且这个赋值非常容易 cur->next->random = cur->random->next
        cur = head
        while cur and cur.next:
            if cur.next.random:
                cur.next.random = cur.next.random.next
            cur = cur.next.next
        
        #断开链表可得到深度拷贝后的新链表
        copy = head.next
        while head and head.next:
            n = head.next
            head.next = head.next.next
            head = n
        
        return copy




#### solution2
#这道链表的深度拷贝题的难点就在于如何处理随机指针的问题，由于每一个节点都有一个随机指针，
#这个指针可以为空，也可以指向链表的任意一个节点，如果在每生成一个新节点给其随机指针赋值时，
#都要去遍历原链表的话，OJ 上肯定会超时，所以可以考虑用 HashMap 来缩短查找时间，
#第一遍遍历生成所有新节点时同时建立一个原节点和新节点的 HashMap，第二遍给随机指针
#赋值时，查找时间是常数级。代码如下：

class Solution(object):
    """
    """
    def copyRandomList(self, head):
        dic, prev, node = {}, None, head
        while node:
            if node not in dic:
                # Use a dictionary to map the original node to its copy
                dic[node] = Node(node.val, node.next, node.random)
            if prev:
                # Make the previous node point to the copy instead of the original.
                prev.next = dic[node]
            else:
                # If there is no prev, then we are at the head. Store it to return later.
                head = dic[node]
            if node.random:
                if node.random not in dic:
                    # If node.random points to a node that we have not yet encountered, store it in the dictionary.
                    dic[node.random] = Node(node.random.val, node.random.next, node.random.random)
                # Make the copy's random property point to the copy instead of the original.
                dic[node].random = dic[node.random]
            # Store prev and advance to the next node.
            prev, node = dic[node], node.next
        return head


# @lc code=end

