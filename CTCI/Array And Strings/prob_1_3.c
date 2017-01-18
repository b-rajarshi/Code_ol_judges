#include <stdio.h>
#include <stdbool.h>
#define charSet 256

bool find_if_perm(const char s1[], const char s2[]) {
	// Create a char count map for the words.
	// Here assuming that the string set is consists of 256 chars). 
	int charCount[charSet];
	int i;
	for (i = 0; i < charSet; i++) {
		charCount[i] = 0;
	}
	i = 0;
	while(s1[i] != '\0' || s2[i] != '\0') {
		printf("i = %d, %d\n", s1[i], s2[i]);
		charCount[s1[i]]++;
		charCount[s2[i]]--;
		i++;
	}

	// One more optimization could be check if the two strings are of equal length.
	if (s1[i] != '\0' || s2[i] != '\0') {
		return false; // Not same lenght.
	}
	
	for (i = 0; i < charSet; i++) {
		if (charCount[i] != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	bool result = find_if_perm("ab\0", "abc\0");
	printf("Yes 1 / NO 0  - %d\n",result);
}
