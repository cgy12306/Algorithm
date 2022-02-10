#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K;
	vector<int> V;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		V.push_back(num);
	}
	sort(V.begin(), V.end());
	cout << V[K-1];
}