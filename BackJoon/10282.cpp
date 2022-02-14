// https://www.acmicpc.net/problem/10282
// «ÿ≈∑
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
vector<vector<pair<int,int>>> Edges;
int minCost[10002], INF = 999999999;
int n, d, c;

void dijkstra(int start) {
	
	//for (int i = 1; i <= 10001; i++) minCost[i] = INF;
	fill(minCost, minCost + n + 2, INF);
	minCost[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (minCost[current] < cost) continue;

		for (auto e : Edges[current]) {
			int next = e.first;
			int nextCost = e.second + cost;
			if (minCost[next] > nextCost) {
				minCost[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
		
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		
		Edges.clear();
		memset(minCost, 0, sizeof(minCost));
		cin >> n >> d >> c;
		Edges.resize(n + 1);

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			Edges[b].push_back(make_pair(a, s));
		}
		dijkstra(c);
		int cnt = 0, ans = 0;
		
		for (int i = 1; i <= n; i++) {
			if (minCost[i] != INF) {
				cnt++;
				ans = max(minCost[i], ans);
			}
		}

		cout << cnt << " " << ans <<"\n";
	}
}