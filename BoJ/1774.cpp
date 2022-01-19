#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<algorithm>

using namespace std;
int N, M;
int parent[1002];
vector<pair<int, int>> god;
vector<tuple<int, int, double>> path;

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
	double sum = 0;
	for (auto p : path) {
		int a = get<0>(p);
		int b = get<1>(p);
		double cost = get<2>(p);
		if (Find(a) != Find(b)) {
			sum += cost;
			Union(a, b);
		}
	}
	cout << sum;
}
void difference(int i, int j) {
	double distance = sqrt(pow(god[j].first - god[i].first, 2) + pow(god[j].second - god[i].second, 2));
	path.push_back(make_tuple(i, j, distance));
}
bool cmp(tuple<int, int, double> a, tuple<int, int, double> b) {
	return get<2>(a) < get<2>(b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cout << fixed;
	cout.precision(2);
	
	for (int i = 0; i < N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		god.push_back(make_pair(x - 1, y - 1));
	}

	for (int i = 0; i < god.size(); i++) {
		for (int j = i; j < god.size(); j++) {
			if (i == j) continue;
			difference(i, j);
		}
	}

	sort(path.begin(), path.end(), cmp);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		Union(x - 1, y - 1);
	}
	
	kruskal();
}