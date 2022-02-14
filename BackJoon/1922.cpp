// https://www.acmicpc.net/problem/1922
// 네트워크 연결
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int N, M, parent[1002];
vector<tuple<int, int, int>> Network;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<2>(a) < get<2>(b);
}
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
	int sum = 0;
	for (auto n : Network) {
		int a = get<0>(n);
		int b = get<1>(n);
		int cost = get<2>(n);
		if (Find(a) != Find(b)) {
			sum += cost;
			Union(a, b);
		}
	}
	cout << sum;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Network.push_back(make_tuple(from, to, cost));
	}

	sort(Network.begin(), Network.end(), cmp);
	kruskal();
}