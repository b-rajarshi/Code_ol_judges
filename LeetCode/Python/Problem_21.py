# Problem : https://leetcode.com/problems/merge-two-sorted-lists/
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # Both the lists are empty
        if not l1 and not l2:
            return l1
        # if one of them empty
        if not l1:
            return l2
        elif not l2:
            return l1

        head = ListNode(0)
        runner = head

        # merge the lists
        # The head is just a dummy node to make the traversal easy
        while (l1 and l2):

            if (l1.val > l2.val):
                runner.next = l2
                l2 = l2.next
                runner = runner.next
            else:
                runner.next = l1
                l1 = l1.next
                runner = runner.next
        if (l1):
            runner.next = l1
        else:
            runner.next = l2

        # return the head.next node the actual starting point.
        return head.next
