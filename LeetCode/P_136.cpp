/*
Leet code problem # 136 : Single number.
Given an array of integers, every element
appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int singleNumber = 0;
    	for (int i = 0; i < nums.size(); i++) {
    		singleNumber = singleNumber ^ nums[i];
    	}
        return singleNumber;
    }
};