/*      
    Problem => Find the 
    Problem Link => https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/

int number(const string& str, int i, int n){
   
    if(i+n>str.size())
        return -1;
        
        
    int num = 0;
    for(int j=i; j<i+n; j++){
        int digit = str[j]-'0';
        if(digit<0 && digit>9)
            return -1;
        num = num*10 + digit;
    }
    
    return num;
}

int missingNumber(const string& str)
{
    for(int n=1; n<=6; n++){
        
        int num = number(str, 0, n);
        if(num==-1)
            break;
        int ans = -1;
        bool ok = true;
        
        for(int i=n; i<str.size(); i+=1+log10l(num)){
            
            if((ans==-1) && (number(str, i, 1+log10l(num+2)) == num+2)){
                ans = num+1;
                num+=2;
            }
            
            else if(number(str, i, 1+log10l(num+1))==num+1)
                num++;
            
            else{
                ok = false;
                break;
            }
        }
        
        if(ok)
            return ans;
    }
    
    return -1;
}