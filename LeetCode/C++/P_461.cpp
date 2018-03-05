/*
Leet Code Problem # 461.
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
URL: https://leetcode.com/problems/hamming-distance/#/description
Tag : Easy
Key concept: Brian Kernighan’s Algorithm bit counting algorithm
https://stackoverflow.com/questions/12383002/please-explain-the-logic-behind-kernighans-bit-counting-algorithm
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;

        int xor_num = x ^ y; // only set when bits are different in the same location.

        // Count the number of 1s in the number.
        while (xor_num != 0) {
            xor_num = xor_num  & (xor_num - 1);
            count++;
        }
        return count;
    }
};

