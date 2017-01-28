/*
	Determine whether an integer is a palindrome.
	Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
    	int temp = x;
        // find the number of digits 
    	int digits = 1;
    	temp = temp / 10;
        while (temp != 0) {
        		temp = temp / 10;
        		digits = digits * 10;
        }
        

        while (num != 0) {
        	if (num / digits != num %10)
        		return false;
        	//1234
        	num = num - digits;
        	//234
        	num = num / 10;
        	// 23
        	digits = digits / 10;
        }
    return true;
    }
};
