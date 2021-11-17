#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, rank[50] = { 0, };
	cin >> N;
	
	vector<pair<int, int>> v;
	int maxx=0, maxy=0;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i].first > v[j].first && v[i].second > v[j].second) {
				rank[j]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << rank[i] + 1 << " ";
	}

}