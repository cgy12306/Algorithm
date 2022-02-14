#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	vector<int> V;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		V.push_back(num);
	}

	sort(V.begin(), V.end());

	cout << V[0] * V[V.size() - 1];
}