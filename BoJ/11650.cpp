#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, x, y;
	vector<pair<int, int>> pv;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		pv.push_back({ x,y });
	}
	sort(pv.begin(), pv.end());

	for (auto i : pv)cout << i.first << " " << i.second << "\n";
}