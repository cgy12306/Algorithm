#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int V, E;
int parent[10002];

vector<tuple<int, int, int>> Edges;

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
	int sum = 0;
	for (auto e : Edges) {
		long long cost = get<0>(e);
		int a = get<1>(e);
		int b = get<2>(e);
		
		if (Find(a) != Find(b)) {
			Union(a, b);
			sum += cost;
		}
	}
	cout << sum;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	
	for (int i = 1; i <= V; i++) parent[i] = i;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		Edges.push_back({ cost, from, to });
	}

	sort(Edges.begin(), Edges.end());

	kruskal();

}