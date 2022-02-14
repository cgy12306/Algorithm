// https://www.acmicpc.net/problem/4485
// ³ì»ö ¿Ê ÀÔÀº ¾Ö°¡ Á©´ÙÁö?
#include<iostream>
#include<vector>
#include<queue>	
#include<cstring>
#include<tuple>
using namespace std;
int N, map[126][126], INF = 999999999, minCost[126][126];
int dx[] = { -1, 1, 0 ,0 };
int dy[] = { 0, 0, -1, 1 };
bool visited[126][126];

void dijkstra(int x, int y) {
	fill(minCost[0], minCost[126], INF);
	
	priority_queue<tuple<int, int, int>> pq;
	minCost[x][y] = map[x][y];
	pq.push(make_tuple(-map[x][y], x, y));
	visited[x][y] = true;
	while (!pq.empty()) {
		int cost = -get<0>(pq.top());
		int currentx = get<1>(pq.top());
		int currenty = get<2>(pq.top());
		pq.pop();
		if (minCost[currentx][currenty] < cost) continue;

		for (int i = 0; i < 4; i++) {
			int nextx = dx[i] + currentx;
			int nexty = dy[i] + currenty;
			int nextCost = map[nextx][nexty] + cost;
			if (nextx < 0 || nexty < 0 || nextx >= N || nexty >= N || visited[nextx][nexty]) continue;
			if (minCost[nextx][nexty] > nextCost) {
				minCost[nextx][nexty] = nextCost;
				pq.push(make_tuple(-nextCost, nextx, nexty));
				visited[nextx][nexty] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int cnt = 1;
	while (1) {
		cin >> N;
		if (N == 0)break;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		dijkstra(0, 0);
		cout << "Problem " << cnt << ": " << minCost[N - 1][N - 1] <<"\n";
		cnt++;
	}

}