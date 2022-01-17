/*
	Problem => Generate Binary
	Problem Link => https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/
*/

void genBinary(vector<string>&ans, int N){
	string bin;
	while(N!=0){
		char c = N%2 + '0';
		bin += c;
		N/=2;
	}

	reverse(bin.begin(), bin.end());
	ans.push_back(bin);
}

vector<string> generate(int N){
	vector<string>ans;
	for(int i=1; i<=N; i++){
		genBinary(ans, i);
	}

	return ans;
}

