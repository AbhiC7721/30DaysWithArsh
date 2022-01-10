/* Ways to nth stair (order doesn't matter)
Problem link => https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/#
*/

class Solution {
public:
	long long countWays(int m){
		return m/2 + 1;
	}
};

//O(1) tim complexity