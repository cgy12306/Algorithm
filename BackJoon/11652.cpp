#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
long long num;
int N;

bool cmp(pair<long long, int> &a, pair<long long, int> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	unordered_map<long long, int> um;

	for (int i = 0; i < N; i++) {
		cin >> num;
		um[num]++;
	}
	vector<pair<long long, int>> V(um.begin(), um.end());
	sort(V.begin(), V.end(), cmp);

	cout << V[0].first;
}