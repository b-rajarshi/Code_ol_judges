#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int main() {
	int nums[] = {2,7,11,15};
	int numSize = 4;
	int target = 9;
	int i,j;
    for (i = 0; i < numSize; i++) {
        for (j = i+1; j < numSize; j++) {
            if ((nums[i] + nums[j]) == target) {
                goto done;
            }
        }
    }
    done:
    printf ("i = %d,j = %d", i, j);
    return 0;
    
}
