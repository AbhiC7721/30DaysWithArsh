#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        long long ans = (n*(n+1)*(2*n+1))/6;
        return ans;
    }
};    


int main() {
  int t;
  cin>>t;
  while(t--){
    long long N;

    cin>>N;

    Solution ob;
    cout<<ob.squaresInChessBoard(N)<<endl;
  }
}