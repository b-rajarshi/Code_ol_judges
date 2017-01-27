class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        list =[]
        start_set = ['(','{','[']
        for i in range(len(s)):
            if (s[i] in start_set):
                list.append(s[i])
            else:
                # if the list is empty cant pop
                if (len(list) == 0):
                    return False
                pop_elem = list.pop();
                if (s[i] == ')'):
                    if (pop_elem != '('):
                        return False
                elif (s[i] == '}'):
                    if (pop_elem != '{'):
                        return False
                elif (s[i] == ']'):
                    if (pop_elem != '['):
                        return False
        # is the list is not empty that means than not
        # all matching closing brackets are found.
        if (len(list) != 0):
            return False
        return True

