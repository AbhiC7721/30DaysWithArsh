/*
	Problem => Possible Phone Directories
	Problem Link => https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/
*/

class Solution {
	public: 
		vector<string>ans;

		vector<vector<char>>letters;

		void letterform(int i, int a[], int N, string str){

			if(i>=N){
            	ans.push_back(str);
            	return;
        	}

        	int size = letters[a[i]-2].size();
        	for(int j=0; j<size; j++){
            	letterform(i+1, a, N, str+letters[a[i]-2][j]);
            }
    }

     vector<string> possibleWords(int a[], int N)
     {

      	letters.push_back({'a', 'b', 'c'});
        letters.push_back({'d', 'e', 'f'});
        letters.push_back({'g', 'h', 'i'});
        letters.push_back({'j', 'k', 'l'});
        letters.push_back({'m', 'n', 'o'});
        letters.push_back({'p', 'q', 'r', 's'});
        letters.push_back({'t', 'u', 'v'});
        letters.push_back({'w', 'x', 'y', 'z'});

        letterform(0, a, N, "");

        return ans;
	 }
};