/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and
there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
    	int length = s.length(); // Get the lenght of the string.
    	bool table[length][length]; // Construct a boolean array to store the results.
    	int max_length = 1;
    	int start_index = 0;
    	
    	for (int i = 0; i < length ;i++)
    	    for (int j = 0; j < length; j++)
    	        table[i][j] = false;

    	for (int i = 0; i < length; i++) {
    		table[i][i] = true; // Single character is always a palindrom.
    	}

    	for (int i = 0; i < length; i++) { // Find the double character palindroms.
    		if (s[i] == s[i+1]) {
    			table[i][i+1] = true;
    			max_length = 2;
    			start_index =  i;
    		}
    	}

    	for (int i = 3; i <= length; i++) { // Length of the substring

    		for (int j = 0; j <= length - i; j++) { // Index
    		    
    		    int end = j + i -1;
    			
    			if (table[j+1][end-1] && (s[j] == s[end])) {
    				table [j][end] = true;
    				
    				if (i > max_length) {
    					start_index = j; // Change the max length.
    					max_length = i;
    				}
    			}
    		}
    	}
 
    	return s.substr(start_index, max_length);

        
    }
};