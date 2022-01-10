/*
Problem => Column name from a given column number
Link => https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/
*/

class Solution{
    public:
        string colname (long long int n){
            string ans = "";
            int cur = 0;
            while(n){
                cur = n%26;
                if(cur==0){
                    ans += 'Z';
                    n = (n/26) - 1;
                }
                else {
                    ans += (cur - 1 + 'A');
                    n/=26;
                }
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
};

// O(logn) and space is just the one use by ans string O(K);
// ** Important to consider is the 0 remainder case, when we need to add '0' to the string