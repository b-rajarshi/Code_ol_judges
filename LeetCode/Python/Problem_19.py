# Problem : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        length = 0
        if not head:
            return length

        # store the head
        temp = head
        while head:
            length = length + 1
            head = head.next

        # check the length of the list
        if (n > length):
            return 0

        # restore the head and adjust the length where we have to remove
        head = temp
        length = length - n

        # find the object previous to the object that needs to be removed
        if length == 0:
            # remove the head
            head = temp.next
        else:
            while length != 1:
                length = length - 1
                temp = temp.next
            # Make it point the next to next node
            temp.next = temp.next.next

        return head






