// https://www.acmicpc.net/problem/16398
// 행성 연결
#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;
long long N, parent[1002], map[1002][1002];
vector<tuple<long long, int, int>> Edges;
int Find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

void kruskal() {
	long long sum = 0;
	for (auto e : Edges) {
		long long cost = get<0>(e);
		int a = get<1>(e);
		int b = get<2>(e);
		if (Find(a) != Find(b)) {
			sum += cost;
			Union(a, b);
		}
	}
	cout << sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			Edges.push_back({ map[i][j], i, j });
		}
	}
	sort(Edges.begin(), Edges.end());

	kruskal();
}