// https://www.acmicpc.net/problem/15686
// 치킨 배달

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N, M, map[51][51], dist = 987654321, res = 987654321;

vector<pair<int,int>> store;
vector<pair<int, int>> home;
vector<int> open;

int distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void brute_force() {
	for (int i = 0; i < M; i++) {
		open[i] = 1;
	}
	sort(open.begin(), open.end());

	do {

		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			dist = 987654321;

			for (int j = 0; j < store.size(); j++) {
				if (open[j]) {
					dist = min(distance(store[j].first,  store[j].second, home[i].first, home[i].second), dist);
				}
			}
			sum += dist;
		}
		res = min(res, sum);
	} while (next_permutation(open.begin(), open.end()));

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) home.push_back(make_pair(i, j));
			else if (map[i][j] == 2) {
				store.push_back(make_pair(i, j));
				open.push_back(0);
			}
		}
	}

	brute_force();
	
	cout << res;
	

}