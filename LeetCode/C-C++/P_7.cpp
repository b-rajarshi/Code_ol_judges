/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
    	int mod = 0;
    	int result = 0;
        
    	while (x/10) {
            if (result > INT_MAX/10 || result < INT_MIN/10){
                return 0;
            }
    		mod = x % 10;
    		result = (result * 10) + mod;
    		x = x /10;
    	}
        result = (result * 10) + x;
    

        return result;
    }
};