// https://www.acmicpc.net/problem/9372
// 상근이의 여행
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<int, int>> edges;
int parent[1002];
int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
void kruskal() {
	int cnt = 0;
	for (auto e : edges) {
		int a = e.first;
		int b = e.second;
		if (Find(a) != Find(b)) {
			Union(a, b);
			cnt++;
		}
	}
	cout << cnt <<"\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		memset(parent, 0, sizeof(parent));
		edges.clear();
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}	

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			edges.push_back(make_pair(a, b));
		}
		kruskal();
	}
}