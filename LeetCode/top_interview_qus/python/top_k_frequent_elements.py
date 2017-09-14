class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        dict = {}

        for num in nums:
            if (num in dict):
                dict[num] = dict[num] + 1
            else:
                dict[num] = 1

        heap = []  # construct a heap of max k elements

        for item in dict:
            # print item, dict[item]
            if (len(heap) < k):
                heapq.heappush(heap, (dict[item], item))
            else:
                heapq.heappushpop(heap, (dict[item], item))

        return [x[1] for x in heap]
