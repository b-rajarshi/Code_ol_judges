/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

int climbStairs(int n) {

	int climb_table[n];

	for(int i = 0; i < n; i++) 
		climb_table[i] = 0;

	climb_table[1] = 1;
	climb_table[2] = 2;

	for(int i = 3; i <= n; i++) {
			climb_table[i] = climb_table[i-1] + climb_table[i-2];
	}
	return climb_table[n];
   
}