// https://www.acmicpc.net/problem/1261
// ¾Ë°í½ºÆÌ
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
#include<string>
using namespace std;
int N, M, INF = 999999999;
int map[102][102], minCost[102][102];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
void dijkstra() {
	fill(minCost[0], minCost[102], INF);
	priority_queue<tuple<int, int, int>> pq;
	minCost[1][1] = 0;
	pq.push(make_tuple(map[1][1], 1, 1));
	while (!pq.empty()) {
		int cost = -get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		if (minCost[x][y] < cost)continue;

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			int nextCost = map[nx][ny] + cost;
			if (nx < 1 || ny < 1 || nx > M || ny > N) continue;

			if (minCost[nx][ny] > nextCost) {
				minCost[nx][ny] = nextCost;
				pq.push(make_tuple(-nextCost, nx, ny));
			}
		}
	}
	if (minCost[M][N] == INF) cout << "0";
	else cout << minCost[M][N];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string s;
	for (int i = 1; i <= M; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j + 1] = s[j] - '0';
		}
	}
	dijkstra();
}