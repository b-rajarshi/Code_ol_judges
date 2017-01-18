#include <stdio.h>
#include <stdbool.h>

bool is_unique(char string[]) {
	printf("The String: %s\n", string);
	int i, j, string_length = 0;
	bool result = true;
	while (string[string_length] != '\0') {
		string_length++;
	}
	for (i = 0; i < string_length; i++) {
		for (j = i+1; j < string_length; j++) {
			if (string[i] == string[j]) {
				result = false;
				goto done;
			}
		}
	}
done:
	return result;
}

int main() {
	printf ("Result (1: Unique)- %d\n", is_unique("Raj"));
	return 0;
}
