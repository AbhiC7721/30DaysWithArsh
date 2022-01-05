#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long pdt = 1, ans =0;
        int start=0, end=0;
        for(; end<n; end++){
          pdt *= a[end];

          while(start<end && pdt>= k){
                pdt /= a[start];
                start++;
          }
            
          if(pdt<k){
                ans += end-start+1;  
          }
        }

        return ans;
        }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
      int n, i;
      long long int k;
      vector<int> arr(n);
      for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}