// https://www.acmicpc.net/problem/11399
// ATM

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;


int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int num;

		cin >> num;
		V.push_back(num);
	}
	sort(V.begin(), V.end());

	int ans = 0, sum = 0;
	for (auto v : V) {
		sum += v;
		ans += sum;
	}
	cout << ans;
}