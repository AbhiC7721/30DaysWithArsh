/*
	Problem => Remove neighbors if both neighbors are of the same color
	Problem Link => https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.length()<3)
            return false;
        int acnt=0, bcnt=0;
        int alice=0, bob=0;
        int n = colors.size();
        for(int i=0; i<n; i++){
            if(colors[i]=='A' && colors[i+1]=='A' && i+1<n){
                if(acnt==0)
                    acnt+=2;
                else
                    acnt++;
            }
            else{
                if(acnt>=3)
                    alice += (acnt-2);
                acnt = 0;
            }
        }
        
        for(int i=0; i<n; i++){
            if(colors[i]=='B' && colors[i+1]=='B'){
                bcnt = (bcnt==0) ? (bcnt+2) : (bcnt+1);
            }
            else{
                if(bcnt>=3)
                    bob += (bcnt-2);
                bcnt = 0;
            }
        }
        
        cout<<alice<<" "<<bob<<"\n";
        
        if(alice>bob)
            return true;
        else
            return false;
    }
};