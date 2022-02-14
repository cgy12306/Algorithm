#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	vector<pair<int, int>> pv;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		pv.push_back({ x,y });
	}
	sort(pv.begin(), pv.end(), comp);

	for (auto i : pv) {
		cout << i.first << " " << i.second << "\n";
	}
}