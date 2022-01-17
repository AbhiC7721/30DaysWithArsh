/*
	Problem => Minimum steps to reach destination
	Problem Link => https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/
*/

class Solution {
	public:
    	int minSteps(int D){
    		int steps = 0;
        	int sum = 0;
        	while(sum<D){
            	sum += steps;
            	steps++;
        	}
        	while((sum-D)%2==1){
            	sum += steps;
            	steps++;
            }

            return steps-1;
    }
};