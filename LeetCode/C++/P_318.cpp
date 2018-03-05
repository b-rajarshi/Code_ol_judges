/*
Leet Code Problem # 318.
Given a string array words, find the maximum value of length(word[i]) * length(word[j])
where the two words do not share common letters. You may assume that
each word will contain only lower case letters. If no such two words exist, return 0.
Example:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
    	string word;
    	int num_words = words.size();

    	int bit_num[num_words];

    	for (int i = 0; i < num_words; i++) {
    		bit_num[i] = 0;
    	}

        // Compute the Bit Array.
        for (int i = 0; i < num_words; i++) {
        	word = words[i];
        	for (int j = 0; j < word.size(); j++) {
        		bit_num[i] |= (1 << (word[j] - 'a')); 
        	}
        }

        //Used as flag to indicate if we found two
        //words without any common char. 
        bool match;
        int max_length = 0; // result if found

        // Check for match
        for (int i = 0; i < num_words; i++) {
        	for (int j = i+1; j < num_words; j++) {
        		match = bit_num[i] & bit_num[j];
        		if (!match) {// Found a match
        			int cur_length = words[i].size() * words[j].size();
        			max_length = max(max_length, cur_length);
        		}
        	}
        }
        return max_length;

    }
};