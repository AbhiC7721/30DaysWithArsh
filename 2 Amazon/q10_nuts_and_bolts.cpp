/*
 Problem => Nuts and Bolts Problem
 Problem Link => https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
*/

class Solution{
public: 
    void matchPairs(char nuts[], char bolts[], int n) {
        vector<char>temp(9, 'A');
        for(int i=0; i<n; i++){
            if(nuts[i]=='!')
                temp[0] = '!';
            else if(nuts[i]=='#')
                temp[1] = '#';
            else if(nuts[i]=='$')
                temp[2] = '$';
            else if(nuts[i]=='%')
                temp[3] = '%';
            else if(nuts[i]=='&')
                temp[4] = '&';
            else if(nuts[i]=='*')
                temp[5] = '*';
            else if(nuts[i]=='@')
                temp[6] = '@';
            else if(nuts[i]=='^')
                temp[7] = '^';
            else if(nuts[i]=='~')
                temp[8] = '~';
        }
        int j =0;
        for(int i=0; i<9; i++){
            if(temp[i]!='A'){
                nuts[j] = temp[i];
                bolts[j] = temp[i];
                j++;
            }
        }

    }
};