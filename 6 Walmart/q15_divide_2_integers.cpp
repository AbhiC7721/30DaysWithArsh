/*
    Problem => Divide two integers
    Problem Link => https://leetcode.com/problems/divide-two-integers
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        long long quotient = 0;
        int sign = ( (dividend<0)^(divisor<0) )? -1 : 1;
        
        // cout<<sign<<" ";
        long long dvd = llabs(dividend);
        long long dvs = llabs(divisor);
        // cout<<dvd<<" "<<dvs<<"\n";
        int ans;
        while(dvd >=dvs){
            long long temp = dvs,cnt=1;
            while(temp<<1 <= dvd){
                temp<<=1;
                cnt<<=1;
            }
            dvd-=temp;
            quotient+= cnt;
        }
        
        // cout<<quotient<<" "<<sign;
        
        return (quotient*sign);
    }
};