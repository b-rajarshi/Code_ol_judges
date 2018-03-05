/*
LEET Code : Problem 3.
Given a string, find the length of the longest substring without repeating characters.
Examples:
	Given "abcabcbb", the answer is "abc", which the length is 3.
	Given "bbbbb", the answer is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    if (s.length() == 0) { // Base Case.
        return 0;
    }

	int max_length = 1; // Maximum length seen so fur.
	int cur_length = 1; // Current length of the substring.

	int string_hash[256]; // To store the index of the last seen.
	for(int i = 0; i < 256; i++) {
		string_hash[i] = -1;
	}

	string_hash[s[0]] = 0; // Store the index of the first char.

	for (int i = 1; i <s.length(); i++) {
		int last_index = string_hash[s[i]];

		if (last_index == -1 || last_index < (i - cur_length))  { // char Not seen. 
			cur_length++;
		} else { // Seen in the current substring.
			if (cur_length > max_length) {
				max_length = cur_length;
			}
			cur_length = i - last_index;
		}

		string_hash[s[i]] = i; // Store the last index.
	}

	// Check finaly if we have to modify the max length.
	if (cur_length > max_length) {
		max_length = cur_length;
	}

	return (max_length);
        
    }
};
