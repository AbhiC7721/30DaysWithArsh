// find maximum of 10 numbers in a list having 10M entries
#include<bits/stdc++.h>
using namespace std;

vector<int> largestK(vector<int>arr, int n, int K){
	vector<int>ans;
	priority_queue<intpq;
	for(int i=0; i<n; i++){
		pq.push(arr[i]);
	}

	for(int i=0; i<k; i++){
		ans.push_back(pq.top());
		pq.pop();
	}

	return ans;
}

int main(){
	int N, k;
	cin>>N>>k;
	// k = k largest
	vector<int>arr(N, 1000000);
	for(int i=0; i<N; i++){
		cin>>arr[i];
	}
	vector<int>result = largestK(arr, N, k);

}