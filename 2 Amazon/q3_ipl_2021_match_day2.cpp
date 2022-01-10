/*  IPL 2021 Match Day 2 - gfg problem
    Link - https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/
*/

class Solution {
    public:
        vector<int> max_of_subarrays(vector<int> arr, int n, int k){
            deque<int>dq;
            vector<int>ans;
            for(int i=0; i<n; i++){

                // if dq is not empty and arr[i] >= arr[dq.back()]; then just pop it out
                while(!dq.empty() && arr[i] >= arr[dq.back()])
                    dq.pop_back();
                // this is necessary to keep track of latest elements
                dq.push_back(i);

                //pushing result only after i is greater than k
                if(i>=k-1)
                    ans.push_back(arr[dq.front()]);

                //next range will eb from i-k+2 to i+1, so remvoe that element
                if(dq.front() <= i-k+1)
                    dq.pop_front();

            }

            return ans;
        }
};