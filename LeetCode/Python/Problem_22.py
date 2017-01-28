# problem : https://leetcode.com/problems/generate-parentheses/
class Solution(object):

    def helper(self, list, current_string, left , right):
        # we should not go further if our closing parenthesis set are empty.
        if (left > right):
            return

        if (left == 0 and right == 0):
            list.append(current_string)
            return

        if (left):
            self.helper(list, current_string + '(' , left - 1, right)
        if (right):
            self.helper(list, current_string +')',  left, right - 1)

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        list = []
        # Recursively generates all the combination.
        self.helper(list, "", n,n)
        return list
