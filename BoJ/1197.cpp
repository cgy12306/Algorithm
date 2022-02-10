// https://www.acmicpc.net/problem/1197
// 최소 스패닝 트리
#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int V, E;
vector<tuple<int, int, long long>> Edges;
int parent[10002];
bool cmp(tuple<int, int, long long> a, tuple<int, int, long long> b) {
	return get<2>(a) < get<2>(b);
}
int Find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}
void kruskal() {
	int sum = 0;
	for (auto e : Edges) {
		int a = get<0>(e);
		int b = get<1>(e);
		long long cost = get<2>(e);
		if (Find(a) != Find(b)) {
			sum += cost;
			Union(a, b);
		}
	}
	cout << sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Edges.push_back(make_tuple(A, B, C));
	}
	
	sort(Edges.begin(), Edges.end(), cmp);
	kruskal();
	
}