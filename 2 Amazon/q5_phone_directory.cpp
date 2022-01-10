/* Phone Directory Implement
Problem Link => https://practice.geeksforgeeks.org/problems/phone-directory4628/1/
*/

class Solution {
	public:
    vector<vector<string>> displayContacts(int n, string contact[], string s){
    	vector<string> uniques = removeDuplicate(contact, n);
        vector<vector<string>>ans;
        ans.push_back(uniques);

         for(int i=0; i<s.size(); i++){
            vector<string>cur;
         for(int j=0; j<(int)ans.back().size(); j++){
                if(ans.back()[j][i]==s[i])cur.push_back(ans.back()[j]);
         }

         if(cur.empty()) cur.push_back("0");

         if(i==0)ans.pop_back();
            ans.push_back(cur);
        }

        return ans;
    }

     vector<string> removeDuplicate(string contact[], int n){
        set<string> uniques(contact, contact+n);
        return vector<string>(uniques.begin(), uniques.end());
    }
};