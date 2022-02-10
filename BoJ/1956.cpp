// https://www.acmicpc.net/problem/1956
// ¿îµ¿
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int map[402][402];
int V, E;
int INF = 999999999;
void floyd() {
	for(int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (map[i][k] != INF && map[k][j] != INF) {
					map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(map[0], map[402], INF);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from][to] = cost;
	}

	floyd();
	int Min = INF;
	for (int i = 1; i <= V; i++) {
		Min = min(map[i][i], Min);
	}
	if (Min == INF) cout << "-1";
	else cout << Min;
}