/*  IPL 2021 Match Day 2 - gfg problem
    Link - https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/
*/

class Solution {
    public:
        vector<int> max_of_subarrays(int* arr, int n, int k){

            deque<int>dq;
            vector<int>ans;

            for(int i=0; i<n; i++){

                while(!dq.empty() && arr[dq.back()] <= arr[i])
                    dq.pop_back();
                dq.push_back(i);
                
                if(i>=k-1)
                     res.push_back(arr[dq.front()]);

                if(dq.front<=i-k+1)
                    dq.pop_front();

            }
            return ans;
        }
};