#include<stdio.h>

void reverse(char *str) {
	int strLen = 0, i, j;
	while(*(str + strLen) != '\0') {
		//printf("Calculating Length %d\n", strLen);
		strLen++;
		// Additional Check to see if StrLen
		// exceeds INT_MAX.
	}
	j = strLen - 1;
	for (i = 0; i < j; i++) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j--;
		//dprintf("-%d, %d-\n", i, j);
	}
	printf("Reverse String : %s\n", str);
}

int main() {
	char string[] = "a";
	reverse(string);
	return 0;
}
