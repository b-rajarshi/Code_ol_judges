# problem statement:
# https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution(object):
    def removeDuplicates(self, num):
        # check whether the array is empty or not
        if not num:
            return 0
        # Store the first element. One element array so length is 1
        current = num[0]
        length = 1

        for i in range(len(num)):
            # now just check if there is a mismatch
            if (current != num[i]):
                num[length] = num[i]
                current = num[i]
                length = length + 1

        # return the non duplicate array length
        return length